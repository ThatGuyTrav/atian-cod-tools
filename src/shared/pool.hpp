#pragma once
#include <includes_shared.hpp>

namespace pool {
    enum XAssetType : BYTE{
        ASSET_TYPE_PHYSPRESET = 0,
        ASSET_TYPE_PHYSCONSTRAINTS = 1,
        ASSET_TYPE_DESTRUCTIBLEDEF = 2,
        ASSET_TYPE_XANIM = 3,
        ASSET_TYPE_XMODEL = 4,
        ASSET_TYPE_XMODELMESH = 5,
        ASSET_TYPE_MATERIAL = 6,
        ASSET_TYPE_COMPUTE_SHADER_SET = 7,
        ASSET_TYPE_TECHNIQUE_SET = 8,
        ASSET_TYPE_IMAGE = 9,
        ASSET_TYPE_SOUND = 10,
        ASSET_TYPE_CLIPMAP = 11,
        ASSET_TYPE_COMWORLD = 12,
        ASSET_TYPE_GAMEWORLD = 13,
        ASSET_TYPE_GFXWORLD = 14,
        ASSET_TYPE_FONTICON = 15,
        ASSET_TYPE_LOCALIZE_ENTRY = 16,
        ASSET_TYPE_LOCALIZE_LIST = 17,
        ASSET_TYPE_GESTURE = 18,
        ASSET_TYPE_GESTURE_TABLE = 19,
        ASSET_TYPE_WEAPON = 20,
        ASSET_TYPE_WEAPON_FULL = 21,
        ASSET_TYPE_WEAPON_TUNABLES = 22,
        ASSET_TYPE_CGMEDIA = 23,
        ASSET_TYPE_PLAYERSOUNDS = 24,
        ASSET_TYPE_PLAYERFX = 25,
        ASSET_TYPE_SHAREDWEAPONSOUNDS = 26,
        ASSET_TYPE_ATTACHMENT = 27,
        ASSET_TYPE_ATTACHMENT_UNIQUE = 28,
        ASSET_TYPE_WEAPON_CAMO = 29,
        ASSET_TYPE_CUSTOMIZATION_TABLE = 30,
        ASSET_TYPE_CUSTOMIZATION_TABLE_FE_IMAGES = 31,
        ASSET_TYPE_SNDDRIVER_GLOBALS = 32,
        ASSET_TYPE_FX = 33,
        ASSET_TYPE_TAGFX = 34,
        ASSET_TYPE_KLF = 35,
        ASSET_TYPE_IMPACT_FX = 36,
        ASSET_TYPE_IMPACT_SOUND = 37,
        ASSET_TYPE_AITYPE = 38,
        ASSET_TYPE_CHARACTER = 39,
        ASSET_TYPE_XMODELALIAS = 40,
        ASSET_TYPE_RAWFILE = 41,
        ASSET_TYPE_XANIM_TREE = 42,
        ASSET_TYPE_STRINGTABLE = 43,
        ASSET_TYPE_STRUCTURED_TABLE = 44,
        ASSET_TYPE_LEADERBOARD = 45,
        ASSET_TYPE_DDL = 46,
        ASSET_TYPE_GLASSES = 47,
        ASSET_TYPE_SCRIPTPARSETREE = 48,
        ASSET_TYPE_SCRIPTPARSETREEDBG = 49,
        ASSET_TYPE_SCRIPTPARSETREEFORCED = 50,
        ASSET_TYPE_KEYVALUEPAIRS = 51,
        ASSET_TYPE_VEHICLEDEF = 52,
        ASSET_TYPE_TRACER = 53,
        ASSET_TYPE_SURFACEFX_TABLE = 54,
        ASSET_TYPE_SURFACESOUNDDEF = 55,
        ASSET_TYPE_FOOTSTEP_TABLE = 56,
        ASSET_TYPE_ENTITYFXIMPACTS = 57,
        ASSET_TYPE_ENTITYSOUNDIMPACTS = 58,
        ASSET_TYPE_ZBARRIER = 59,
        ASSET_TYPE_VEHICLEFXDEF = 60,
        ASSET_TYPE_VEHICLESOUNDDEF = 61,
        ASSET_TYPE_TYPEINFO = 62,
        ASSET_TYPE_SCRIPTBUNDLE = 63,
        ASSET_TYPE_SCRIPTBUNDLELIST = 64,
        ASSET_TYPE_RUMBLE = 65,
        ASSET_TYPE_BULLETPENETRATION = 66,
        ASSET_TYPE_LOCDMGTABLE = 67,
        ASSET_TYPE_AIMTABLE = 68,
        ASSET_TYPE_SHOOTTABLE = 69,
        ASSET_TYPE_PLAYERGLOBALTUNABLES = 70,
        ASSET_TYPE_ANIMSELECTORTABLESET = 71,
        ASSET_TYPE_ANIMMAPPINGTABLE = 72,
        ASSET_TYPE_ANIMSTATEMACHINE = 73,
        ASSET_TYPE_BEHAVIORTREE = 74,
        ASSET_TYPE_BEHAVIORSTATEMACHINE = 75,
        ASSET_TYPE_TTF = 76,
        ASSET_TYPE_SANIM = 77,
        ASSET_TYPE_LIGHT_DESCRIPTION = 78,
        ASSET_TYPE_SHELLSHOCK = 79,
        ASSET_TYPE_STATUS_EFFECT = 80,
        ASSET_TYPE_CINEMATIC_CAMERA = 81,
        ASSET_TYPE_CINEMATIC_SEQUENCE = 82,
        ASSET_TYPE_SPECTATE_CAMERA = 83,
        ASSET_TYPE_XCAM = 84,
        ASSET_TYPE_BG_CACHE = 85,
        ASSET_TYPE_TEXTURE_COMBO = 86,
        ASSET_TYPE_FLAMETABLE = 87,
        ASSET_TYPE_BITFIELD = 88,
        ASSET_TYPE_MAPTABLE = 89,
        ASSET_TYPE_MAPTABLE_LIST = 90,
        ASSET_TYPE_MAPTABLE_LOADING_IMAGES = 91,
        ASSET_TYPE_MAPTABLE_PREVIEW_IMAGES = 92,
        ASSET_TYPE_MAPTABLEENTRY_LEVEL_ASSETS = 93,
        ASSET_TYPE_OBJECTIVE = 94,
        ASSET_TYPE_OBJECTIVE_LIST = 95,
        ASSET_TYPE_NAVMESH = 96,
        ASSET_TYPE_NAVVOLUME = 97,
        ASSET_TYPE_LASER = 98,
        ASSET_TYPE_BEAM = 99,
        ASSET_TYPE_STREAMER_HINT = 100,
        ASSET_TYPE_FLOWGRAPH = 101,
        ASSET_TYPE_POSTFXBUNDLE = 102,
        ASSET_TYPE_LUAFILE = 103,
        ASSET_TYPE_LUAFILE_DBG = 104,
        ASSET_TYPE_RENDEROVERRIDEBUNDLE = 105,
        ASSET_TYPE_STATIC_LEVEL_FX_LIST = 106,
        ASSET_TYPE_TRIGGER_LIST = 107,
        ASSET_TYPE_PLAYER_ROLE_TEMPLATE = 108,
        ASSET_TYPE_PLAYER_ROLE_CATEGORY_TABLE = 109,
        ASSET_TYPE_PLAYER_ROLE_CATEGORY = 110,
        ASSET_TYPE_CHARACTER_BODY_TYPE = 111,
        ASSET_TYPE_PLAYER_OUTFIT = 112,
        ASSET_TYPE_GAMETYPETABLE = 113,
        ASSET_TYPE_FEATURE = 114,
        ASSET_TYPE_FEATURETABLE = 115,
        ASSET_TYPE_UNLOCKABLE_ITEM = 116,
        ASSET_TYPE_UNLOCKABLE_ITEM_TABLE = 117,
        ASSET_TYPE_ENTITY_LIST = 118,
        ASSET_TYPE_PLAYLISTS = 119,
        ASSET_TYPE_PLAYLIST_GLOBAL_SETTINGS = 120,
        ASSET_TYPE_PLAYLIST_SCHEDULE = 121,
        ASSET_TYPE_MOTION_MATCHING_INPUT = 122,
        ASSET_TYPE_BLACKBOARD = 123,
        ASSET_TYPE_TACTICALQUERY = 124,
        ASSET_TYPE_PLAYER_MOVEMENT_TUNABLES = 125,
        ASSET_TYPE_HIERARCHICAL_TASK_NETWORK = 126,
        ASSET_TYPE_RAGDOLL = 127,
        ASSET_TYPE_STORAGEFILE = 128,
        ASSET_TYPE_STORAGEFILELIST = 129,
        ASSET_TYPE_CHARMIXER = 130,
        ASSET_TYPE_STOREPRODUCT = 131,
        ASSET_TYPE_STORECATEGORY = 132,
        ASSET_TYPE_STORECATEGORYLIST = 133,
        ASSET_TYPE_RANK = 134,
        ASSET_TYPE_RANKTABLE = 135,
        ASSET_TYPE_PRESTIGE = 136,
        ASSET_TYPE_PRESTIGETABLE = 137,
        ASSET_TYPE_FIRSTPARTYENTITLEMENT = 138,
        ASSET_TYPE_FIRSTPARTYENTITLEMENTLIST = 139,
        ASSET_TYPE_ENTITLEMENT = 140,
        ASSET_TYPE_ENTITLEMENTLIST = 141,
        ASSET_TYPE_SKU = 142,
        ASSET_TYPE_LABELSTORE = 143,
        ASSET_TYPE_LABELSTORELIST = 144,
        ASSET_TYPE_CPU_OCCLUSION_DATA = 145,
        ASSET_TYPE_LIGHTING = 146,
        ASSET_TYPE_STREAMERWORLD = 147,
        ASSET_TYPE_TALENT = 148,
        ASSET_TYPE_PLAYERTALENTTEMPLATE = 149,
        ASSET_TYPE_PLAYERANIMATION = 150,
        ASSET_TYPE_ERR_UNUSED = 151,
        ASSET_TYPE_TERRAINGFX = 152,
        ASSET_TYPE_HIGHLIGHTREELINFODEFINES = 153,
        ASSET_TYPE_HIGHLIGHTREELPROFILEWEIGHTING = 154,
        ASSET_TYPE_HIGHLIGHTREELSTARLEVELS = 155,
        ASSET_TYPE_DLOGEVENT = 156,
        ASSET_TYPE_RAWSTRING = 157,
        ASSET_TYPE_BALLISTICDESC = 158,
        ASSET_TYPE_STREAMKEY = 159,
        ASSET_TYPE_RENDERTARGETS = 160,
        ASSET_TYPE_DRAWNODES = 161,
        ASSET_TYPE_GROUPLODMODEL = 162,
        ASSET_TYPE_FXLIBRARYVOLUME = 163,
        ASSET_TYPE_ARENASEASONS = 164,
        ASSET_TYPE_SPRAYORGESTUREITEM = 165,
        ASSET_TYPE_SPRAYORGESTURELIST = 166,
        ASSET_TYPE_HWPLATFORM = 167,
        ASSET_TYPE_COUNT = 168,
        ASSET_TYPE_ASSETLIST = 168,
        ASSET_TYPE_REPORT = 169,
        ASSET_TYPE_FULL_COUNT = 170,
    };

}