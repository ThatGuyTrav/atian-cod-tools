#include <includes.hpp>
#include <tools/fastfile.hpp>
#include <tools/ff/fastfile_handlers.hpp>
#include <games/bo4/pool.hpp>
#include <tools/utils/data_utils.hpp>
#include <utils/compress_utils.hpp>
#include <tools/compatibility/acti_crypto_keys.hpp>
#include <hook/error.hpp>
#include <hook/memory.hpp>
#include <bdiff.hpp>
#include <games/bo4/t8_errors.hpp>
#include <wincrypt.h>

namespace {

	namespace cod2020 {
		enum XFileBlock : __int32 {
			XFILE_BLOCK_TEMP = 0x0,
			XFILE_BLOCK_TEMP_PRELOAD = 0x1,
			XFILE_BLOCK_RUNTIME_VIRTUAL = 0x2,
			XFILE_BLOCK_RUNTIME_PHYSICAL = 0x3,
			XFILE_BLOCK_VIRTUAL = 0x4,
			XFILE_BLOCK_CPU_GPU_SHARE = 0x5,
			XFILE_BLOCK_PHYSICAL = 0x6,
			XFILE_BLOCK_STREAMER = 0x7,
			XFILE_BLOCK_STREAMER_CPU = 0x8,
			XFILE_BLOCK_MEMMAPPED = 0x9,
			XFILE_BLOCK_LOAD_TIME = 0xA,
			XFILE_BLOCK_TEMP_PRELOAD_SAVED_PTR = 0xB,
			XFILE_BLOCK_COUNT = 0xC,
		};
		struct XFileData {
			uint32_t version;
			bool server;
			fastfile::FastFileCompression compression;
			fastfile::FastFilePlatform platform;
			bool encrypted;
			uint64_t unk8;
			uint64_t timestamp;
			uint32_t changelist;
			uint32_t archiveChecksum[4];
			char builderName[32];
			uint32_t unk4c;
			uint32_t unk50;
			byte linkResultCode;
			char linkResult[256];
			uint64_t size;
			uint64_t externalSize;
			uint64_t memMappedOffset;
			uint64_t blockSize[12];
			byte pad[536];
			char fastfileName[64];
			uint8_t signature[256];
			uint8_t aesIV[16];
		}; static_assert(sizeof(XFileData) == 0x538);
	}
	namespace cwrelease {
		enum XFileBlock : __int32 {
			XFILE_BLOCK_TEMP = 0x0,
			XFILE_BLOCK_TEMP_PRELOAD = 0x1,
			XFILE_BLOCK_RUNTIME_VIRTUAL = 0x2,
			XFILE_BLOCK_RUNTIME_PHYSICAL = 0x3,
			XFILE_BLOCK_VIRTUAL = 0x4,
			XFILE_BLOCK_CPU_GPU_SHARE = 0x5,
			XFILE_BLOCK_PHYSICAL = 0x6,
			XFILE_BLOCK_STREAMER = 0x7,
			XFILE_BLOCK_STREAMER_CPU = 0x8,
			XFILE_BLOCK_MEMMAPPED = 0x9,
			XFILE_BLOCK_LOAD_TIME = 0xA,
			XFILE_BLOCK_TEMP_PRELOAD_SAVED_PTR = 0xB,
			XFILE_BLOCK_MESH = 0xC,
			XFILE_BLOCK_COUNT = 0xD,
		};
		struct XFileData {
			uint32_t version;
			bool server;
			fastfile::FastFileCompression compression;
			fastfile::FastFilePlatform platform;
			bool encrypted;
			uint64_t unk8;
			uint64_t timestamp;
			uint32_t changelist;
			uint32_t archiveChecksum[4];
			char builderName[32];
			uint32_t unk4c;
			uint32_t unk50;
			byte linkResultCode;
			char linkResult[256];
			uint64_t size;
			uint64_t externalSize;
			uint64_t memMappedOffset;
			uint64_t blockSize[13];
			byte pad[584];
			char fastfileName[64];
			uint8_t signature[256];
			uint8_t aesIV[16];
		}; static_assert(sizeof(XFileData) == 0x570);

	}
	union XFileData {
		cod2020::XFileData cod2020;
		cwrelease::XFileData cw;
	};

	void DumpHeader(XFileData& udata, const char* title) {
		cwrelease::XFileData& data{ udata.cw };
		LOG_INFO("{}: v{} server:{}, comp:{}, plt:{} enc:{}, unk:{} bld:{}", 
			title, data.version, data.server ? "true" : "false",
			fastfile::GetFastFileCompressionName(data.compression), fastfile::GetFastFilePlatformName(data.platform),
			data.server ? "true" : "false", data.unk8, data.builderName
		);
	}

	struct XFileMagic {
		byte magic[4];
		uint32_t blocks;
	};
	void ErrorStub(uint32_t errcode) {
		throw std::runtime_error(games::bo4::errors::TranslateError(errcode));
	}

    static byte ff_magic[4]{ 'T', 'A', 'F', 'F' };
	XFileData& DecryptHeader(core::bytebuffer::ByteBuffer& headerBuffer, size_t* headerSizeOut = nullptr) {
		byte tmpBuff[0x570]{};

		size_t headerSize{ headerBuffer.Loc() };
		// to write the result inside the ff data at the end
		if (!headerBuffer.CanRead(sizeof(XFileData))) throw std::runtime_error("Can't read xfile header size");
		XFileData* res{ headerBuffer.Ptr<XFileData>() };
        byte* data{ tmpBuff };
        __int64 v7; // rcx
        __int64 v8; // r8
        byte v9; // dl
        __int64 v10; // rax
        byte v11; // r9
        size_t v12; // r14d
        __int64 v14; // rbx
        byte* v15; // rcx
        uint32_t v17[2]; // [rsp+20h] [rbp-48h] BYREF
        XFileMagic magicData; // [rsp+28h] [rbp-40h] BYREF

        std::memset(data, 0, sizeof(tmpBuff));
        //read_func->stream_readskip(&magicData, 8i64, 0i64, &read_func->streamff);
        headerBuffer.Read(&magicData, sizeof(magicData));
        v7 = 0i64;
        v8 = 4i64;
        while (1) {
            v9 = magicData.magic[v7];
            v10 = v8;
            v11 = ff_magic[v7++];
            --v8;
            if (!v10) {
            LABEL_5:
                v12 = 0;
                if (!magicData.blocks) {
				WRITE_RES:
					headerSize = headerBuffer.Loc() - headerSize;
					if (headerSizeOut) *headerSizeOut = headerSize;
					std::memcpy(res, tmpBuff, std::min<size_t>(headerSize, sizeof(tmpBuff)));
                    return *res;
                }
                while (1) {
                    //read_func->stream_readskip(v17, 8i64, 0i64, &read_func->streamff);
                    headerBuffer.Read(&v17[0], sizeof(v17));

                    v14 = 0i64;
                    if (v17[0] > 0x39CB44F1) {
                        switch (v17[0]) {
                        case 0x66C65056u:
                            v14 = 96i64;
                            if (v17[1] <= 0x60)
                                v14 = v17[1];
                            v15 = data + 368;
                            goto LABEL_44;
                        case 0x6AEBB196u:
                            v14 = 96i64;
                            if (v17[1] <= 0x60)
                                v14 = v17[1];
                            v15 = data + 464;
                            goto LABEL_44;
                        case 0x8578C004:
                            v14 = 264i64;
                            if (v17[1] <= 0x108)
                                v14 = v17[1];
                            v15 = data + 80;
                            goto LABEL_44;
                        case 0xC7708CDA:
                            v14 = 336i64;
                            if (v17[1] <= 0x150)
                                v14 = v17[1];
                            v15 = data + 1000;
                            goto LABEL_44;
                        }
                    }
                    else {
                        switch (v17[0]) {
                        case 0x39CB44F1u:
                            v14 = 4i64;
                            if (v17[1] <= 4)
                                v14 = v17[1];
                            v15 = data;
                            goto LABEL_44;
                        case 0xF992DFEu:
                            v14 = 24i64;
                            if (v17[1] <= 0x18)
                                v14 = v17[1];
                            v15 = data + 344;
                            goto LABEL_44;
                        case 0x1CE68F50u:
                            v14 = 440i64;
                            if (v17[1] <= 0x1B8)
                                v14 = v17[1];
                            v15 = data + 560;
                            goto LABEL_44;
                        case 0x2C2381CFu:
                            v14 = 5i64;
                            if (v17[1] <= 5)
                                v14 = v17[1];
                            v15 = data + 4;
                            goto LABEL_44;
                        case 0x37F9D612u:
                            v14 = 64i64;
                            if (v17[1] <= 0x40)
                                v14 = v17[1];
                            v15 = data + 16;
                        LABEL_44:
                            //read_func->stream_readskip(v15, v14, 0i64, &read_func->streamff);
                            headerBuffer.Read(v15, v14);
                            break;
                        }
                    }
                    if (v14 != v17[1]) {
                        //read_func->stream_readskip(0i64, v17[1] - v14, 1i64, &read_func->streamff);
                        headerBuffer.Skip(v17[1] - v14);
                    }
                    if (++v12 >= magicData.blocks) {
						goto WRITE_RES;
                    }
                }
            }
            if (v9 != v11)
                break;
            if (!v9)
                goto LABEL_5;

        }
		throw std::runtime_error("Invalid fastfile magic");
	}


	class T9FFDecompressor : public fastfile::FFDecompressor {
	public:
        T9FFDecompressor() : fastfile::FFDecompressor("Black Ops Cold War", 0x46464154, fastfile::MASK32) {}

        void LoadFastFile(fastfile::FastFileOption& opt, core::bytebuffer::ByteBuffer& reader, fastfile::FastFileContext& ctx, std::vector<byte>& ffdata) {
            if (!reader.CanRead(sizeof(XFileData))) {
                throw std::runtime_error("Can't read XFile header");
            }

            XFileMagic* header{ reader.Ptr<XFileMagic>() };
            // patch header B96310

			size_t headerSize{};

			XFileData& data{ DecryptHeader(reader, &headerSize) };

			if (opt.m_header) {
				DumpHeader(data, "header");
			}


			if (data.cw.version != 0x64) {
				throw std::runtime_error(std::format("Fast file version not supported: 0x{:x}", data.cw.version));
			}
			if (data.cw.encrypted) {
				throw std::runtime_error(std::format("Encrypted Fast file version not supported: 0x{:x}", data.cw.version));
			}

			const char* ffname;
			if (opt.alpha) {
				ffname = data.cod2020.fastfileName;
				ctx.blocksCount = cod2020::XFileBlock::XFILE_BLOCK_COUNT;
			}
			else {
				ffname = data.cw.fastfileName;
				ctx.blocksCount = cwrelease::XFileBlock::XFILE_BLOCK_COUNT;
			}
			sprintf_s(ctx.ffname, "%s", ffname);

			for (size_t i = 0; i < ctx.blocksCount; i++) {
				ctx.blockSizes[i].size = data.cw.blockSize[i];
			}

            utils::compress::CompressionAlgorithm alg{ fastfile::GetFastFileCompressionAlgorithm(data.cw.compression) };

            size_t idx{};
            while (true) {
                size_t loc{ reader.Loc() };

                fastfile::DBStreamHeader* block{ reader.ReadPtr<fastfile::DBStreamHeader>() };
                if (!block->alignedSize) break; // end

                if (block->offset != loc) {
                    LOG_ERROR("bad block position: 0x{:x} != 0x{:x}", loc, block->offset);
                    break;
                }
                idx++;

                if (!block->uncompressedSize) {
                    reader.Align(0x800000);
                    continue;
                }

                byte* blockBuff{ reader.ReadPtr<byte>(block->alignedSize) };
                LOG_TRACE("Decompressing block 0x{:x} {}(0x{:x}/0x{:x} -> 0x{:x})", loc, data.cw.encrypted ? "encrypted " : "", block->compressedSize, block->alignedSize, block->uncompressedSize);

                size_t unloc{ utils::Allocate(ffdata, block->uncompressedSize) };
                byte* decompressed{ &ffdata[unloc] };

                if (!utils::compress::Decompress(alg, decompressed, block->uncompressedSize, blockBuff, block->compressedSize)) {
                    throw std::runtime_error(std::format("Can't decompress block 0x{:x}", loc));
                }
            }

			if (opt.m_fd) {
				std::filesystem::path fdfile{ ctx.file };

				fdfile.replace_extension(".fd");

				std::vector<byte> fileFDBuff{};
				if (opt.ReadFile(fdfile.string(), fileFDBuff)) {
					core::bytebuffer::ByteBuffer fdreader{ fileFDBuff };

					// todo: handle fd file

					
					struct BDiffHeader {
						uint32_t size;
						float version;
						uint32_t flags;
						size_t maxDestWindowSize;
						uint64_t maxSourceWindowSize;
						uint64_t maxDiffWindowSize;
					}; static_assert(sizeof(BDiffHeader) == 0x28);

					BDiffHeader* bdiffHeader{ fdreader.ReadPtr<BDiffHeader>() };

					XFileData& newXFileHeader{ DecryptHeader(fdreader) };
					XFileData& baseXFileHdr{ DecryptHeader(fdreader) };
					
					
					// patch header B96310


					if (opt.m_header) {
						DumpHeader(newXFileHeader, "fd header");
						DumpHeader(baseXFileHdr, "ff header");
					}

					if (opt.dump_decompressed) {
						std::vector<byte> headerData{};

						utils::WriteValue(headerData, &newXFileHeader, sizeof(newXFileHeader));
						utils::WriteValue(headerData, &baseXFileHdr, sizeof(baseXFileHdr));

						std::filesystem::path of{ ctx.file };
						std::filesystem::path decfile{ opt.m_output / of.filename() };

						decfile.replace_extension(".fd.header.dec");

						std::filesystem::create_directories(decfile.parent_path());
						if (!utils::WriteFile(decfile, headerData)) {
							LOG_ERROR("Can't dump {}", decfile.string());
						}
						else {
							LOG_INFO("Dump fd header into {}", decfile.string());
						}
					}

					if (std::memcmp(&baseXFileHdr, header, sizeof(baseXFileHdr))) {
						throw std::runtime_error("The patch file is for this fast file");
					}

					for (size_t i = 0; i < ctx.blocksCount; i++) {
						LOG_DEBUG("New size for block {} 0x{:x} -> 0x{:x}", i, ctx.blockSizes[i].size, newXFileHeader.cw.blockSize[i]);
						ctx.blockSizes[i].size = newXFileHeader.cw.blockSize[i];
					}

					if (bdiffHeader->maxDiffWindowSize < 0x10000) bdiffHeader->maxDiffWindowSize = 0x10000;
					if (bdiffHeader->maxDestWindowSize < 0x10000) bdiffHeader->maxDestWindowSize = 0x10000;
					if (bdiffHeader->maxSourceWindowSize < 0x10000) bdiffHeader->maxSourceWindowSize = 0x10000;

					size_t compressedSize{ fdreader.Remaining() };
					size_t fdDecompressedSize{ newXFileHeader.cw.size };

					LOG_TRACE("Decompressing patch {} 0x{:x}: 0x{:x} -> 0x{:x}", fastfile::GetFastFileCompressionName(newXFileHeader.cw.compression), fdreader.Loc(), compressedSize, fdDecompressedSize);
					auto uncompress{ std::make_unique<byte[]>(fdDecompressedSize) };

					utils::compress::CompressionAlgorithm alg{};
					switch (newXFileHeader.cw.compression) {
					case fastfile::XFILE_BDELTA_UNCOMP:
						alg = utils::compress::COMP_NONE;
						break;
					case fastfile::XFILE_BDELTA_ZLIB:
						alg = utils::compress::COMP_ZLIB;
						break;
					case fastfile::XFILE_BDELTA_LZMA:
						alg = utils::compress::COMP_LZMA;
						break;
					default:
						throw std::runtime_error(std::format("No fastfile decompressor for type {}", (int)newXFileHeader.cw.compression));
					}

					if (!utils::compress::Decompress(alg, uncompress.get(), fdDecompressedSize, fdreader.ReadPtr<byte>(compressedSize), compressedSize)) {
						throw std::runtime_error(std::format("Error when decompressing fd data for type {}", fastfile::GetFastFileCompressionName(newXFileHeader.cw.compression)));
					}

					LOG_TRACE("Decompressed 0x{:x} byte(s) from patch file", fdDecompressedSize);

					if (opt.dump_decompressed) {
						std::filesystem::path of{ ctx.file };
						std::filesystem::path decfile{ opt.m_output / ctx.ffname };

						decfile.replace_extension(".fd.dec");

						std::filesystem::create_directories(decfile.parent_path());
						if (!utils::WriteFile(decfile, uncompress.get(), fdDecompressedSize)) {
							LOG_ERROR("Can't dump {}", decfile.string());
						}
						else {
							LOG_INFO("Dump fd into {}", decfile.string());
						}
					}


					struct BdiffStates {
						BDiffHeader* bdiffHeader{};
						byte* destWindow{};
						size_t destWindowSize{};
						size_t patchWindowOffsetLast{};
						size_t destWindowLastSize{};
						core::bytebuffer::ByteBuffer* ffbb{};
						core::bytebuffer::ByteBuffer* fdbb{};

						std::vector<byte> destData{};

						void SyncData() {
							if (!destWindowLastSize) return;

							LOG_TRACE("Sync 0x{:x} bytes", destWindowLastSize);
							utils::WriteValue(destData, destWindow, destWindowLastSize);

							destWindowLastSize = 0;
						}
					} bdiffStates{};


					bdiffStates.bdiffHeader = bdiffHeader;
					std::vector<byte> outwindow{};
					bdiffStates.destWindowSize = bdiffHeader->maxDestWindowSize + bdiffHeader->maxSourceWindowSize + 2 * (bdiffHeader->maxDiffWindowSize + 0x80000);
					outwindow.resize(bdiffStates.destWindowSize);
					bdiffStates.destWindow = outwindow.data();
					bdiffStates.destData.clear();
					bdiffStates.destWindowLastSize = 0;

					core::bytebuffer::ByteBuffer ffbb{ ffdata };
					core::bytebuffer::ByteBuffer fdbb{ uncompress.get(), fdDecompressedSize };
					bdiffStates.fdbb = &fdbb;
					bdiffStates.ffbb = &ffbb;

					bdiff::diffInfo diffInfo{};
					diffInfo.state = &bdiffStates;
					bdiffStates.patchWindowOffsetLast = 0;
					do {
						if (!bdiffStates.fdbb->CanRead(0x400)) {
							break; // can't read header
						}
						LOG_TRACE("Pre bdiff");
						if (!bdiff::bdiff_internal(&diffInfo,
							[](void* data, size_t offset, size_t size) -> uint8_t* {
								BdiffStates& bdiffStates{ *(BdiffStates*)data };
								// vcSourceCB_t
								bdiffStates.ffbb->Goto(offset);
								if (!bdiffStates.ffbb->CanRead(size)) {
									hook::error::DumpStackTraceFrom();
									throw std::runtime_error(std::format("vcSourceCB_t: read too much at 0x{:x}/0x{:x}", bdiffStates.ffbb->Loc(), size));
								}
								LOG_TRACE("vcSourceCB_t: read 0x{:x}:0x{:x}", bdiffStates.ffbb->Loc(), size);
								return bdiffStates.ffbb->ReadPtr<uint8_t>(size);
							},
							[](void* data, size_t offset, size_t size, size_t* pOffset) -> uint8_t* {
								BdiffStates& bdiffStates{ *(BdiffStates*)data };
								if (offset) {
									bdiffStates.patchWindowOffsetLast = offset;
								}
								else {
									offset = bdiffStates.patchWindowOffsetLast;
								}
								if (pOffset) *pOffset = offset;

								// vcDiffCB_t
								bdiffStates.fdbb->Goto(offset);
								if (!bdiffStates.fdbb->CanRead(size)) {
									hook::error::DumpStackTraceFrom();
									throw std::runtime_error(std::format("vcDiffCB_t: read too much at 0x{:x}/0x{:x}", bdiffStates.fdbb->Loc(), size));
								}
								LOG_TRACE("vcDiffCB_t: read 0x{:x}:0x{:x}", bdiffStates.fdbb->Loc(), size);
								return bdiffStates.fdbb->ReadPtr<uint8_t>(size);
							},
							[](void* data, size_t size) -> uint8_t* {
								BdiffStates& bdiffStates{ *(BdiffStates*)data };
								// vcDestCB_t
								bdiffStates.SyncData();
								bdiffStates.destWindowLastSize = size;
								LOG_TRACE("vcDestCB_t: give 0x{:x}", size);
								if (size <= bdiffStates.bdiffHeader->maxDestWindowSize) {
									return bdiffStates.destWindow;
								}
								throw std::runtime_error(std::format("vcDestCB_t: dest window too small 0x{:x} < 0x{:x}", bdiffStates.bdiffHeader->maxDestWindowSize, size));
							}
						)) {
							throw std::runtime_error("bdiff error");
						}
					} while (bdiffStates.destWindowLastSize);
					bdiffStates.SyncData();
					LOG_TRACE("end size: 0x{:x}", bdiffStates.destData.size());

					ffdata = bdiffStates.destData;

					if (opt.dump_decompressed) {
						std::filesystem::path of{ ctx.file };
						std::filesystem::path decfile{ opt.m_output / ctx.ffname };

						decfile.replace_extension(".fd.patch.dec");

						std::filesystem::create_directories(decfile.parent_path());
						if (!utils::WriteFile(decfile, bdiffStates.destData)) {
							LOG_ERROR("Can't dump {}", decfile.string());
						}
						else {
							LOG_INFO("Dump fd patch into {}", decfile.string());
						}
					}

				}
				else {
					throw std::runtime_error(std::format("No patch file {}", fdfile.string()));
				}
			}
        }
	};

	utils::ArrayAdder<T9FFDecompressor, fastfile::FFDecompressor> arr{ fastfile::GetDecompressors() };
}