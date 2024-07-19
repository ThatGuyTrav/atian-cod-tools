#pragma once

namespace tool::gsc::gdb {
	constexpr uint64_t MAGIC = 0x21000A0D42444780;

	struct GSC_GDB {
		byte magic[8];
		uint32_t version;
		uint32_t source_crc;
		uint32_t lineinfo_offset;
		uint32_t lineinfo_count;
		uint32_t devblock_stringtable_offset;
		uint32_t devblock_stringtable_count;
		uint32_t stringtable_offset;
		uint32_t stringtable_count;
	};

	struct GSC_LINEINFO {
		uint32_t offset;
		uint32_t nulled4;
	};

	class ACTS_GSC_GDB {
	public:
		uint64_t name;
		uint32_t crc;
		uint32_t version;

		bool nameHashed{};
		std::string nameStr{};

		std::unordered_map<uint32_t, std::string> strings{};

		bool ReadFrom(const std::filesystem::path& file);
	};


}