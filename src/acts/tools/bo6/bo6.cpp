#include <includes.hpp>
#include <core/bytebuffer.hpp>
#include <hook/module_mapper.hpp>
#include <tools/bo6/bo6.hpp>

namespace {
	void NullStub() {}
	template<typename T, T val>
	T ReturnStub() { return val; }


	enum RadianKeysType : byte {
		RKT_UNK0 = 0,
		RKT_UNK1 = 1,
		RKT_STRING = 2,
		RKT_UNK3 = 3,
		RKT_VECTOR = 4,
		RKT_UNK5 = 5,
		RKT_FLOAT = 6,
		RKT_INTEGER = 7,
		RKT_UNK8 = 8,
		RKT_HASH_LOCALIZED = 9,
	};

	const char* RadianKeysTypeName(RadianKeysType type) {
		switch (type) {
		case RKT_STRING: return "string";
		case RKT_VECTOR: return "vector";
		case RKT_FLOAT: return "float";
		case RKT_INTEGER: return "int";
		case RKT_HASH_LOCALIZED: return "localized";
		default: return utils::va("unk%d", type);
		}
	}

	int bo6_radiant_keys(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 1)) return tool::BAD_USAGE;
		std::vector<byte> data{};
		if (!utils::ReadFile(argv[2], data)) {
			LOG_ERROR("Can't read {}", argv[2]);
			return tool::BASIC_ERROR;
		}
		std::filesystem::path out;

		if (tool::NotEnoughParam(argc, 2)) {
			out = argv[2];
			out.replace_extension(".dec.txt");
		}
		else {
			out = argv[3];
		}

		utils::OutFileCE os{ out };
		if (!os) {
			LOG_ERROR("Can't open {}", argv[3]);
			return tool::BASIC_ERROR;
		}
		core::bytebuffer::ByteBuffer buffer{ data };

		while (buffer.CanRead(sizeof(uint64_t))) {
			uint64_t key{ buffer.Read<uint64_t>() };

			if (!key) break;

			RadianKeysType type{ buffer.Read<RadianKeysType>() };

			os << std::setw(10) << std::setfill(' ') << std::left << RadianKeysTypeName(type) << " " << hashutils::ExtractTmp("hash", key) << "\n";
		}

		LOG_INFO("Dump into {}", out.string());

		return tool::OK;
	}


	int lua_file_delta(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 3)) {
			return tool::BAD_USAGE;
		}
		std::vector<byte> f1{};
		std::vector<byte> f2{};
		size_t offset{ std::strtoull(argv[4], nullptr, 10) };
		if (!utils::ReadFile(argv[2], f1) || !utils::ReadFile(argv[3], f2)) {
			LOG_ERROR("Can't read files");
			return tool::BASIC_ERROR;
		}

		size_t max{ std::max<size_t>(f1.size(), f2.size()) };

		std::map<byte, std::unordered_set<byte>> diff{};

		for (size_t i = offset; i < max; i++) {
			if (f1[i] != f2[i]) {
				diff[f1[i]].insert(f2[i]);
			}
		}

		for (auto& [old, news] : diff) {
			std::stringstream ss{};

			for (byte nw : news) {
				ss << " " << std::dec << (int)nw;
			}

			LOG_INFO("{} ->{}", (int)old, ss.str());
		}

		


		return tool::OK;
	}


	struct GscFunction {
		uint64_t name;
		void(__fastcall* func)(void* vm);
		bool devFunc;
		byte minArgs;
		byte maxArgs;
	};

	struct GscFuncContainerData {
		GscFunction* functions;
		uint64_t count;
	};
	struct GscFuncContainerDataType {
		GscFuncContainerData data;
		bool isMethod;
	};
	static struct {
		std::vector<std::vector<GscFuncContainerDataType>> pool{};
		std::vector<GscFuncContainerDataType>* functions{};
	} bo6GscData;

	template<bool isMethod>
	void Bo6LoadFuncs(void* container, GscFuncContainerData* cfg) {
		bo6GscData.functions->emplace_back(*cfg, isMethod);
	}

	int bo6_gsc_dump(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 2)) return tool::BAD_USAGE;

		std::filesystem::path exe{ argv[2] };

		hook::module_mapper::Module mod{ true };

		LOG_INFO("Loading module {}", exe.string());
		if (!mod.Load(exe) || !mod) {
			LOG_ERROR("Can't load module");
			return tool::BASIC_ERROR;
		}

		LOG_INFO("Loaded");

		constexpr size_t len = 0x100000;

		std::unique_ptr<byte[]> data{ std::make_unique<byte[]>(len) };

		bo6GscData.pool.clear();

		mod->Redirect("4C 8B 4A 08 4D 85 C9 74 35", Bo6LoadFuncs<false>);
		mod->Redirect("4C 8B 4A 08 4D 85 C9 74 3F", Bo6LoadFuncs<true>);

		for (hook::library::ScanResult& res : mod->Scan("48 89 5C 24 08 55 48 8B EC 48 83 EC 40 48 8B D9 E8 ? ? ? ? ? ? ? ?")) {
			LOG_INFO("Loading function: {}", hook::library::CodePointer{ res.location });

			bo6GscData.pool.emplace_back();
			bo6GscData.functions = &bo6GscData.pool[bo6GscData.pool.size() - 1];

			res.GetPtr<void(*)(byte*)>()(data.get());
		}

		utils::OutFileCE os{ argv[3] };

		if (!os) {
			LOG_ERROR("Can't open {}", argv[3]);
			return tool::BASIC_ERROR;
		}

		LOG_INFO("Dumping functions in {}", argv[3]);

		os << "pool,container,type,name,minargs,maxargs,type,offset";

		for (size_t i = 0; i < bo6GscData.pool.size(); i++) {
			std::vector<GscFuncContainerDataType>& pool{ bo6GscData.pool[i] };
			for (size_t j = 0; j < pool.size(); j++) {
				GscFuncContainerDataType& container{ pool[j] };
				for (size_t k = 0; k < container.data.count; k++) {
					GscFunction& func{ container.data.functions[k] };
					os
						<< "\n" << std::dec
						<< i << ","
						<< j << ","
						<< (container.isMethod ? "method" : "function") << ","
						<< hashutils::ExtractTmp("function", func.name) << ","
						<< (int)func.minArgs << ","
						<< (int)func.maxArgs << ","
						<< (func.devFunc ? "dev" : "common") << ","
						<< hook::library::CodePointer{ func.func };
				}
			}
		}


		return tool::OK;
	}

	constexpr const char* defaultBo6LuaFuncObject = "default";
	static struct {
		std::map<const char*, std::map<uint64_t, void*>> funcs{};
		const char* currentFunc{ defaultBo6LuaFuncObject };

		void Cleanup() {
			funcs.clear();
			bo6LuaData.currentFunc = defaultBo6LuaFuncObject;
		}
	} bo6LuaData;

	void Bo6LoadLuaPop(void* vm, size_t count) {
		bo6LuaData.currentFunc = defaultBo6LuaFuncObject;
	}
	void Bo6LoadLuaPush(void* vm, int a2, const char* category) {
		bo6LuaData.currentFunc = category;
	}

	void Bo6LoadLuaFunc(void* vm, uint64_t hash, void* func) {
		bo6LuaData.funcs[bo6LuaData.currentFunc][hash] = func;
	}
	void Bo6LoadLuaFuncStr(void* vm, const char* str, void* func) {
		uint64_t hash{ hash::Hash64A(str) };
		hashutils::AddPrecomputed(hash, str, true);
		Bo6LoadLuaFunc(vm, hash, func);
	}

	int bo6_lua_dump(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 2)) return tool::BAD_USAGE;

		std::filesystem::path exe{ argv[2] };

		hook::module_mapper::Module mod{ true };

		LOG_INFO("Loading module {}", exe.string());
		if (!mod.Load(exe) || !mod) {
			LOG_ERROR("Can't load module");
			return tool::BASIC_ERROR;
		}

		LOG_INFO("Loaded");

		bo6LuaData.Cleanup();

		// remove lua things
		mod->Redirect("48 89 5C 24 10 57 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D 87", NullStub); // 88F4A60
		mod->Redirect("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D D2 A9", NullStub); // 88F5610
		mod->Redirect("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D 62", NullStub); // 88F2B80
		// if false it creates some useless calls
		mod->Redirect("40 53 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D 5B", ReturnStub<bool, true>); // 88F5390


		// registry function
		mod->Redirect("40 53 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D 6B", Bo6LoadLuaPop); // 88F4E80
		mod->Redirect("48 89 5C 24 10 57 48 83 EC 20 48 8B 44 24 28 48 8B D9 48 8D 0D 47", Bo6LoadLuaPush); // 88F2FA0

		void* stub{ mod->ScanSingle("E8 ? ? ? ? 48 BA 34 DB FC 73 86 28 B6 F9").GetRelative<int32_t>(1) };
		void* stubStr{ mod->ScanSingle("E8 ? ? ? ? 4C 8D 05 ? ? ? ? 48 8D 15 ? ? ? ? 49 8B CC").GetRelative<int32_t>(1) };

		LOG_INFO("redirect hash . {}", hook::library::CodePointer{ stub });
		LOG_INFO("redirect str .. {}", hook::library::CodePointer{ stubStr });

		hook::memory::RedirectJmp(
			stub,
			Bo6LoadLuaFunc
		);

		hook::memory::RedirectJmp(
			stubStr,
			Bo6LoadLuaFuncStr
		);

		mod->ScanSingle("E9 EC AA 0A 00").GetPtr<void(*)(void*)>()(nullptr);

		utils::OutFileCE os{ argv[3] };

		if (!os) {
			LOG_ERROR("Can't open {}", argv[3]);
			return tool::BASIC_ERROR;
		}

		LOG_INFO("Dumping functions in {}", argv[3]);

		os << "object,name,offset";

		for (auto& [cat, funcs] : bo6LuaData.funcs) {
			for (auto& [name, func] : funcs) {
				os << "\n" << cat << "," << hashutils::ExtractTmp("hash", name) << "," << hook::library::CodePointer{ func };
			}
		}

		bo6LuaData.Cleanup();


		return tool::OK;
	}

	int bo6_data_dump(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 1)) return tool::BAD_USAGE;


		std::filesystem::path exe{ argv[2] };

		hook::module_mapper::Module mod{ true };

		LOG_INFO("Loading module {}", exe.string());
		if (!mod.Load(exe) || !mod) {
			LOG_ERROR("Can't load module");
			return tool::BASIC_ERROR;
		}

		LOG_INFO("Loaded");
		LOG_INFO("base: {:x}", mod->GetOptHeader()->ImageBase);

		// Dump bo6 pool names
		// I know it not that, but it's fine idc
		struct PoolInfo {
			uint32_t size;
			uint32_t unk04;
			uint64_t unk08;
			uint64_t unk10;
			uint64_t unk18;
			uint64_t unk20;
			uint64_t unk28;
		};
		auto* pools{ mod->Get<uintptr_t>(0x8FFBE40) };
		auto* poolsSizes{ mod->Get<PoolInfo>(0x8ED5FF0) };
		{
			std::filesystem::path pf{ exe.parent_path() / "pools.csv" };
			std::ofstream osf{ pf };
			if (!osf) {
				LOG_ERROR("Can't open {}", pf.string());
			}
			else {
				utils::CloseEnd osfce{ osf };
				osf << "id,name,size";
				for (size_t idx = 0; idx < bo6::T10R_ASSET_COUNT; idx++) {
					const char* cc = mod->Rebase<const char>(pools[idx]);
					osf << "\n" << std::dec << idx << "," << cc << ",0x" << std::hex << poolsSizes[idx].size;
				}
			}
			LOG_INFO("Created {}", pf.string());
		}

		struct GscObj {
			byte magic[0x58];
		};
		struct builtin_func {
			uint64_t name;
			void* func;
		};

		struct gscvm_builtins {
			builtin_func builtinsF[2200];
			builtin_func builtinsM[3200];
			uint32_t countFunc;
			uint32_t countMethod;
			bool funcSorted;
			bool methodSorted;
		};


		struct gscvm2 {
			gscvm_builtins* builtins;
			// ...
		};


		struct GscInfo {
			GscObj* obj;
			uint32_t count;
			uint32_t group;
		};

		struct gscvm {
			gscvm2* vm2;
			uint64_t unk08;
			GscInfo* objInfo;
			uint32_t objCount;
			uint32_t group_id;
			GscObj default_obj;
		};

		struct gscvm3 {
			byte pad[2510576];
			gscvm vm;
		};

		auto* gscVm{ mod->Get<gscvm3>(0xC4096A0) };
		LOG_INFO("gscVm: {:x}", mod->Rloc(gscVm));
		auto* vm2{ mod->Rebase(gscVm->vm.vm2) };
		LOG_INFO("vm2: {:x}", mod->Rloc(vm2));
		auto* builtins{ mod->Rebase(vm2->builtins) };
		LOG_INFO("builtins: {:x}", mod->Rloc(builtins));
		{
			std::filesystem::path pf{ exe.parent_path() / "funcs.csv" };
			std::ofstream osf{ pf };
			if (!osf) {
				LOG_ERROR("Can't open {}", pf.string());
			}
			else {
				utils::CloseEnd osfce{ osf };
				osf << "name,type,ptr";
				for (size_t idx = 0; idx < builtins->countFunc; idx++) {
					auto bi{ builtins->builtinsF[idx] };

					osf << "\n" << hashutils::ExtractTmp("function", bi.name) << ",function," << mod->RlocBased(bi.func);
				}
				for (size_t idx = 0; idx < builtins->countMethod; idx++) {
					auto bi{ builtins->builtinsM[idx] };

					osf << "\n" << hashutils::ExtractTmp("function", bi.name) << ",function," << mod->RlocBased(bi.func);
				}
			}
			LOG_INFO("Created {}", pf.string());
		}



		LOG_INFO("Done");

		return tool::OK;
	}

	int bo6_test_hash_types(int argc, const char* argv[]) {
		if (tool::NotEnoughParam(argc, 1)) return tool::BAD_USAGE;


		std::filesystem::path out{ argv[2] };

		utils::OutFileCE os{ out };

		for (size_t i = 0; i < bo6::T10R_ASSET_COUNT; i++) {
			os << std::dec << i << ","
				<< bo6::PoolNameRelease((bo6::T10RAssetType)i) 
				<< ",0x" << std::hex << hash::HashX32(bo6::PoolNameRelease((bo6::T10RAssetType)i)) << "\n";
		}

		LOG_INFO("Dump into {}", out.string());;

		return tool::OK;
	}

	ADD_TOOL(bo6_data_dump, "bo6", " [exe]", "Dump common data from an exe dump", bo6_data_dump);
	ADD_TOOL(bo6_test_hash_types, "dev", " [exe]", "Dump int map for types", bo6_test_hash_types);
	ADD_TOOL(bo6_gsc_dump, "bo6", " [exe]", "Dump gsc function data from an exe dump", bo6_gsc_dump);
	ADD_TOOL(bo6_lua_dump, "bo6", " [exe]", "Dump lua function data from an exe dump", bo6_lua_dump);
	ADD_TOOL(bo6_radiant_keys, "bo6", " [keys] [out]", "Read bo6 radiant keys", bo6_radiant_keys);
	ADD_TOOL(lua_file_delta, "dev", " [a1] [a2] [offset]", "Lua file delta", lua_file_delta);
}