#pragma once

namespace bo3::pool {
	constexpr size_t xassetpools = 0x94073F0;
	constexpr size_t gscobjinfo = 0x50DC2E0;
	constexpr size_t gscobjinfocount = 0x50EFB60;

	struct T7XAssetPool {
		uintptr_t pool; // void*
		unsigned int itemSize;
		int itemCount;
		bool isSingleton;
		int itemAllocCount;
		uintptr_t freeHead; // AssetLink*
	};
	static_assert(sizeof(T7XAssetPool) == 0x20);

	struct T7ScriptParseTree {
		uintptr_t name; // const char*
		int64_t scriptSize;
		uintptr_t script; // T7GSC_OBJ*
	};
	static_assert(sizeof(T7ScriptParseTree) == 0x18);

	enum T7XAssetType : byte {
		T7_ASSET_TYPE_PHYSPRESET = 0,
		T7_ASSET_TYPE_PHYSCONSTRAINTS = 1,
		T7_ASSET_TYPE_DESTRUCTIBLEDEF = 2,
		T7_ASSET_TYPE_XANIM = 3,
		T7_ASSET_TYPE_XMODEL = 4,
		T7_ASSET_TYPE_XMODELMESH = 5,
		T7_ASSET_TYPE_MATERIAL = 6,
		T7_ASSET_TYPE_COMPUTESHADERSET = 7,
		T7_ASSET_TYPE_TECHSET = 8,
		T7_ASSET_TYPE_IMAGE = 9,
		T7_ASSET_TYPE_SOUND = 10,
		T7_ASSET_TYPE_SOUND_PATCH = 11,
		T7_ASSET_TYPE_COL_MAP = 12,
		T7_ASSET_TYPE_COM_MAP = 13,
		T7_ASSET_TYPE_GAME_MAP = 14,
		T7_ASSET_TYPE_MAP_ENTS = 15,
		T7_ASSET_TYPE_GFX_MAP = 16,
		T7_ASSET_TYPE_LIGHTDEF = 17,
		T7_ASSET_TYPE_LENSFLAREDEF = 18,
		T7_ASSET_TYPE_UI_MAP = 19,
		T7_ASSET_TYPE_FONT = 20,
		T7_ASSET_TYPE_FONTICON = 21,
		T7_ASSET_TYPE_LOCALIZE = 22,
		T7_ASSET_TYPE_WEAPON = 23,
		T7_ASSET_TYPE_WEAPONDEF = 24,
		T7_ASSET_TYPE_WEAPONVARIANT = 25,
		T7_ASSET_TYPE_WEAPONFULL = 26,
		T7_ASSET_TYPE_CGMEDIATABLE = 27,
		T7_ASSET_TYPE_PLAYERSOUNDSTABLE = 28,
		T7_ASSET_TYPE_PLAYERFXTABLE = 29,
		T7_ASSET_TYPE_SHAREDWEAPONSOUNDS = 30,
		T7_ASSET_TYPE_ATTACHMENT = 31,
		T7_ASSET_TYPE_ATTACHMENTUNIQUE = 32,
		T7_ASSET_TYPE_WEAPONCAMO = 33,
		T7_ASSET_TYPE_CUSTOMIZATIONTABLE = 34,
		T7_ASSET_TYPE_CUSTOMIZATIONTABLE_FEIMAGES = 35,
		T7_ASSET_TYPE_CUSTOMIZATIONTABLECOLOR = 36,
		T7_ASSET_TYPE_SNDDRIVERGLOBALS = 37,
		T7_ASSET_TYPE_FX = 38,
		T7_ASSET_TYPE_TAGFX = 39,
		T7_ASSET_TYPE_KLF = 40,
		T7_ASSET_TYPE_IMPACTSFXTABLE = 41,
		T7_ASSET_TYPE_IMPACTSOUNDSTABLE = 42,
		T7_ASSET_TYPE_PLAYER_CHARACTER = 43,
		T7_ASSET_TYPE_AITYPE = 44,
		T7_ASSET_TYPE_CHARACTER = 45,
		T7_ASSET_TYPE_XMODELALIAS = 46,
		T7_ASSET_TYPE_RAWFILE = 47,
		T7_ASSET_TYPE_STRINGTABLE = 48,
		T7_ASSET_TYPE_STRUCTUREDTABLE = 49,
		T7_ASSET_TYPE_LEADERBOARDDEF = 50,
		T7_ASSET_TYPE_DDL = 51,
		T7_ASSET_TYPE_GLASSES = 52,
		T7_ASSET_TYPE_TEXTURELIST = 53,
		T7_ASSET_TYPE_SCRIPTPARSETREE = 54,
		T7_ASSET_TYPE_KEYVALUEPAIRS = 55,
		T7_ASSET_TYPE_VEHICLE = 56,
		T7_ASSET_TYPE_ADDON_MAP_ENTS = 57,
		T7_ASSET_TYPE_TRACER = 58,
		T7_ASSET_TYPE_SLUG = 59,
		T7_ASSET_TYPE_SURFACEFXTABLE = 60,
		T7_ASSET_TYPE_SURFACESOUNDDEF = 61,
		T7_ASSET_TYPE_FOOTSTEPTABLE = 62,
		T7_ASSET_TYPE_ENTITYFXIMPACTS = 63,
		T7_ASSET_TYPE_ENTITYSOUNDIMPACTS = 64,
		T7_ASSET_TYPE_ZBARRIER = 65,
		T7_ASSET_TYPE_VEHICLEFXDEF = 66,
		T7_ASSET_TYPE_VEHICLESOUNDDEF = 67,
		T7_ASSET_TYPE_TYPEINFO = 68,
		T7_ASSET_TYPE_SCRIPTBUNDLE = 69,
		T7_ASSET_TYPE_SCRIPTBUNDLELIST = 70,
		T7_ASSET_TYPE_RUMBLE = 71,
		T7_ASSET_TYPE_BULLETPENETRATION = 72,
		T7_ASSET_TYPE_LOCDMGTABLE = 73,
		T7_ASSET_TYPE_AIMTABLE = 74,
		T7_ASSET_TYPE_ANIMSELECTORTABLE = 75,
		T7_ASSET_TYPE_ANIMMAPPINGTABLE = 76,
		T7_ASSET_TYPE_ANIMSTATEMACHINE = 77,
		T7_ASSET_TYPE_BEHAVIORTREE = 78,
		T7_ASSET_TYPE_BEHAVIORSTATEMACHINE = 79,
		T7_ASSET_TYPE_TTF = 80,
		T7_ASSET_TYPE_SANIM = 81,
		T7_ASSET_TYPE_LIGHTDESCRIPTION = 82,
		T7_ASSET_TYPE_SHELLSHOCK = 83,
		T7_ASSET_TYPE_XCAM = 84,
		T7_ASSET_TYPE_BGCACHE = 85,
		T7_ASSET_TYPE_TEXTURECOMBO = 86,
		T7_ASSET_TYPE_FLAMETABLE = 87,
		T7_ASSET_TYPE_BITFIELD = 88,
		T7_ASSET_TYPE_ATTACHMENTCOSMETICVARIANT = 89,
		T7_ASSET_TYPE_MAPTABLE = 90,
		T7_ASSET_TYPE_MAPTABLELOADINGIMAGES = 91,
		T7_ASSET_TYPE_MEDAL = 92,
		T7_ASSET_TYPE_MEDALTABLE = 93,
		T7_ASSET_TYPE_OBJECTIVE = 94,
		T7_ASSET_TYPE_OBJECTIVELIST = 95,
		T7_ASSET_TYPE_UMBRA_TOME = 96,
		T7_ASSET_TYPE_NAVMESH = 97,
		T7_ASSET_TYPE_NAVVOLUME = 98,
		T7_ASSET_TYPE_BINARYHTML = 99,
		T7_ASSET_TYPE_LASER = 100,
		T7_ASSET_TYPE_BEAM = 101,
		T7_ASSET_TYPE_STREAMERHINT = 102,
		T7_ASSET_TYPE_STRING = 103,
		T7_ASSET_TYPE_COUNT = 104,
		T7_ASSET_TYPE_ASSETLIST = 104,
		T7_ASSET_TYPE_REPORT = 105,
		T7_ASSET_TYPE_DEPEND = 106,
	};

	T7XAssetType T7XAssetIdFromName(const char* name);
	const char* T7XAssetName(T7XAssetType type);

	enum T7ScrVarType : uint32_t {
		T7_TYPE_UNDEFINED = 0,
		T7_TYPE_POINTER = 1,
		T7_TYPE_STRING = 2,
		T7_TYPE_LOCALIZED_STRING = 3,
		T7_TYPE_VECTOR = 4,
		T7_TYPE_HASH = 5,
		T7_TYPE_FLOAT = 6,
		T7_TYPE_INT = 7,
		T7_TYPE_UINT64 = 8,
		T7_TYPE_UINTPTR_T = 9,
		T7_TYPE_ENTITY_OFFSET = 10,
		T7_TYPE_CODEPOS = 11,
		T7_TYPE_PRECODEPOS = 12,
		T7_TYPE_API_FUNCTION = 13,
		T7_TYPE_FUNCTION = 14,
		T7_TYPE_STACK = 15,
		T7_TYPE_ANIMATION = 16,
		T7_TYPE_THREAD = 17,
		T7_TYPE_NOTIFY_THREAD = 18,
		T7_TYPE_TIME_THREAD = 19,
		T7_TYPE_CHILD_THREAD = 20,
		T7_TYPE_CLASS = 21,
		T7_TYPE_STRUCT = 22,
		T7_TYPE_REMOVED_ENTITY = 23,
		T7_TYPE_ENTITY = 24,
		T7_TYPE_ARRAY = 25,
		T7_TYPE_REMOVED_THREAD = 26,
		T7_TYPE_FREE = 27,
		T7_TYPE_THREAD_LIST = 28,
		T7_TYPE_ENT_LIST = 29,
	};

}