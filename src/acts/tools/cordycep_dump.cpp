#include <includes.hpp>
#include "cordycep_dump.hpp"
#include <core/memory_allocator.hpp>
#include "tools/gsc_opcodes.hpp"
#include "tools/pool.hpp"
#include "gsc_iw.hpp"

namespace tool::cordycep::dump {
	int ForEachEntry(Process& proc, compatibility::scobalula::csi::XAssetPool64& pool, std::function<bool(const compatibility::scobalula::csi::XAsset64& asset, size_t count)> func) {
		uintptr_t curr = pool.Root;

		compatibility::scobalula::csi::XAsset64 asset{};
		int res{};
		bool ok{ true };
		size_t count{};
		while (curr) {
			if (!proc.ReadMemory(&asset, curr, sizeof(asset))) {
				LOG_ERROR("Can't read pool entry {:x}", curr);
				return false;
			}

			if (asset.Header) {
				try {
					if (!func(asset, count++)) {
						ok = false;
					}
				}
				catch (std::runtime_error& e) {
					LOG_ERROR("{}", e.what());
					ok = false;
				}
				res++;
			}

			curr = asset.Next;
		}

		return ok ? res : -res;
	}

	std::vector<CordycepDumper*>& GetDumpers() {
		static std::vector<CordycepDumper*> vec{};
		return vec;
	}

	namespace {
		int csi_test(int argc, const char* argv[]) {
			if (!argv[2]) return tool::BAD_USAGE;

			compatibility::scobalula::csi::CordycepProc cordycep{};

			if (!cordycep.ReadCsi(argv[2])) {
				LOG_ERROR("Can't read Cordycep database: {}", argv[2]);
				return tool::BASIC_ERROR;
			}

			LOG_INFO("Loaded");

			LOG_INFO("Game Id .. {} (0x{:x})", compatibility::scobalula::csi::CordycepGameName(cordycep.gameId), (uint64_t)cordycep.gameId);
			LOG_INFO("Pools .... 0x{:x}", cordycep.poolsAddress);
			LOG_INFO("Strings .. 0x{:x}", cordycep.stringsAddress);
			LOG_INFO("Game dir . '{}'", cordycep.gameDir);

			return tool::OK;
		}

		int dpcord(Process& proc, int argc, const char* argv[]) {
			std::filesystem::path exe{ proc[nullptr].path };
			std::filesystem::path db{ exe.parent_path() / "Data/CurrentHandler.csi" };
			std::string dbBuff{};

			compatibility::scobalula::csi::CordycepProc cordycep{};

			if (!cordycep.ReadCsi(db)) {
				LOG_ERROR("Can't read Cordycep database: {}", db.string());
				return tool::BASIC_ERROR;
			}

			CordycepDumper* dump{};

			for (CordycepDumper* d : GetDumpers()) {
				if (d->game == cordycep.gameId) {
					dump = d;
					break;
				}
			}

			if (!dump) {
				LOG_ERROR("Can't find dumper for game {} (0x{:x})", CordycepGameName(cordycep.gameId), (uint64_t)cordycep.gameId);
				return tool::BASIC_ERROR;
			}

			return dump->dump(proc, cordycep, argc, argv);
		}

		int dpcordhashes(Process& proc, int argc, const char* argv[]) {
			if (tool::NotEnoughParam(argc, 1)) return tool::BAD_USAGE;
			std::filesystem::path exe{ proc[nullptr].path };
			std::filesystem::path db{ exe.parent_path() / "Data/CurrentHandler.csi" };
			std::string dbBuff{};

			compatibility::scobalula::csi::CordycepProc cordycep{};

			if (!cordycep.ReadCsi(db)) {
				LOG_ERROR("Can't read Cordycep database: {}", db.string());
				return tool::BASIC_ERROR;
			}

			CordycepDumper* dump{};

			for (CordycepDumper* d : GetDumpers()) {
				if (d->game == cordycep.gameId) {
					dump = d;
					break;
				}
			}

			if (!dump) {
				LOG_ERROR("Can't find dumper for game {} (0x{:x})", CordycepGameName(cordycep.gameId), (uint64_t)cordycep.gameId);
				return tool::BASIC_ERROR;
			}


			auto pools = proc.ReadMemoryArrayEx<compatibility::scobalula::csi::XAssetPool64>(cordycep.poolsAddress, dump->numpools);

			utils::OutFileCE out{ argv[2], true };

			out << "type,id";
			for (size_t i = 0; i < dump->numpools; i++) {
				cordycep::dump::ForEachEntry(proc, pools[i], [&out](const compatibility::scobalula::csi::XAsset64& asset, size_t count) -> bool {
					out << "\n0x" << std::hex << asset.Type << ",#" << hashutils::ExtractTmp("hash", asset.ID);
					return true;
				});
			}

			return tool::OK;
		}
	}

	ADD_TOOL(csid, "compatibility", "", "Dump csi info", csi_test);
	ADD_TOOL(dpcord, "common", "", "Cordycep dump tool", L"Cordycep.CLI.exe", dpcord);
	ADD_TOOL(dpcordhashes, "common", " [dump]", "Cordycep dump hashes", L"Cordycep.CLI.exe", dpcordhashes);
}