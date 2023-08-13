#include <includes.hpp>
#include "gsc_opcodes_load.hpp"

void tool::gsc::opcode::RegisterOpCodesMap() {
	static std::once_flag f{};

	std::call_once(f, [] {

		// Register mapping
		// todo: create file containing it

		// BLACK OPS 4 (VM 36)
		RegisterVM(0x36, "Call of Duty: Black ops 4");

		RegisterOpCode(0x36, OPCODE_Unknown0, 0x0);
		RegisterOpCode(0x36, OPCODE_Unknown1, 0x1);
		RegisterOpCode(0x36, OPCODE_Unknown2, 0x2);
		RegisterOpCode(0x36, OPCODE_Unknown3, 0x3);
		RegisterOpCode(0x36, OPCODE_Unknown4, 0x4);
		RegisterOpCode(0x36, OPCODE_Unknown5, 0x5);
		RegisterOpCode(0x36, OPCODE_Unknown6, 0x6);
		RegisterOpCode(0x36, OPCODE_Unknown7, 0x7);
		RegisterOpCode(0x36, OPCODE_Unknowna, 0xa);
		RegisterOpCode(0x36, OPCODE_Unknownb, 0xb);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x12, 0x13, 0x14, 0x16, 0x18, 0x1a, 0x1e, 0x21, 0x23, 0x25, 0x27, 0x28, 0x2b,
			0x2c, 0x2d, 0x2f, 0x30, 0x3d, 0x3e, 0x3f, 0x41, 0x43, 0x48, 0x4f, 0x50, 0x52,
			0x53, 0x5b, 0x5e, 0x66, 0x67, 0x69, 0x6d, 0x73, 0x74, 0x75, 0x79, 0x7f, 0x80,
			0x83, 0x84, 0x86, 0x87, 0x88, 0x90, 0x97, 0x99, 0x9c, 0xa3, 0xa5, 0xa8, 0xaa,
			0xab, 0xac, 0xaf, 0xb2, 0xb3, 0xb6, 0xbd, 0xbf, 0xc3, 0xc6, 0xcb, 0xcd, 0xd1,
			0xd2, 0xd5, 0xd6, 0xd8, 0xdb, 0xde, 0xdf, 0xe0, 0xe2, 0xe5, 0xe8, 0xec, 0xee);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xef, 0xf1, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xff, 0x103, 0x108, 0x109, 0x10b, 0x111,
			0x115, 0x11a, 0x121, 0x124, 0x127, 0x128, 0x12b, 0x12e, 0x12f, 0x131, 0x132, 0x135, 0x139,
			0x13f, 0x140, 0x143, 0x148, 0x14a, 0x14d, 0x14f, 0x153, 0x156, 0x158, 0x159, 0x15b, 0x15c,
			0x15d, 0x15e, 0x160, 0x161, 0x163, 0x166, 0x16b, 0x16c, 0x173, 0x174, 0x176, 0x17a, 0x17b,
			0x185, 0x188, 0x18b, 0x18c, 0x18d, 0x18f, 0x191, 0x195, 0x19b, 0x19c, 0x19e, 0x19f, 0x1a0,
			0x1a2, 0x1a4, 0x1a7, 0x1ad, 0x1ae, 0x1af, 0x1b3, 0x1b5, 0x1b7, 0x1b8, 0x1b9, 0x1bc, 0x1c3);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x1c7, 0x1ca, 0x1cb, 0x1cc, 0x1d1, 0x1d5, 0x1dd, 0x1e0, 0x1e1, 0x1e5, 0x1e7, 0x1ea, 0x1ef,
			0x1fa, 0x1fc, 0x1fd, 0x203, 0x20b, 0x20c, 0x20e, 0x214, 0x215, 0x216, 0x218, 0x221, 0x225,
			0x226, 0x227, 0x229, 0x22c, 0x22e, 0x233, 0x234, 0x239, 0x23b, 0x23d, 0x240, 0x244, 0x245,
			0x247, 0x24b, 0x24d, 0x254, 0x256, 0x258, 0x259, 0x25b, 0x25e, 0x25f, 0x263, 0x266, 0x267,
			0x268, 0x26a, 0x26d, 0x271, 0x273, 0x277, 0x27a, 0x27b, 0x27f, 0x281, 0x282, 0x286, 0x289,
			0x28a, 0x292, 0x297, 0x298, 0x299, 0x29b, 0x29e, 0x2a0, 0x2a1, 0x2a4, 0x2ac, 0x2ae, 0x2b0);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x2b2, 0x2b5, 0x2b8, 0x2ba, 0x2bb, 0x2c4, 0x2c6, 0x2c7, 0x2c8, 0x2c9, 0x2cb, 0x2cc, 0x2cd,
			0x2ce, 0x2d0, 0x2d1, 0x2d4, 0x2d5, 0x2d7, 0x2d8, 0x2da, 0x2e3, 0x2e4, 0x2e8, 0x2e9, 0x2ea,
			0x2ec, 0x2f0, 0x2f5, 0x2f9, 0x2fa, 0x2fd, 0x301, 0x302, 0x305, 0x306, 0x308, 0x309, 0x30d,
			0x310, 0x311, 0x313, 0x317, 0x318, 0x319, 0x31b, 0x31d, 0x31f, 0x322, 0x328, 0x329, 0x32a,
			0x32c, 0x32d, 0x32e, 0x336, 0x339, 0x33c, 0x33f, 0x343, 0x346, 0x348, 0x34f, 0x351, 0x352,
			0x353, 0x355, 0x362, 0x363, 0x367, 0x368, 0x369, 0x36a, 0x370, 0x373, 0x378, 0x37a, 0x37e);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x37f, 0x382, 0x384, 0x387, 0x38b, 0x38d, 0x38e, 0x38f, 0x393, 0x398, 0x39a, 0x3a1, 0x3a3,
			0x3a4, 0x3a5, 0x3a6, 0x3a8, 0x3a9, 0x3aa, 0x3ac, 0x3ad, 0x3af, 0x3b4, 0x3bc, 0x3bf, 0x3c2,
			0x3c5, 0x3c7, 0x3ca, 0x3d0, 0x3d2, 0x3d5, 0x3d6, 0x3d7, 0x3d9, 0x3df, 0x3e1, 0x3e2, 0x3ea,
			0x3ec, 0x3ef, 0x3f0, 0x3f3, 0x3f4, 0x3fe, 0x404, 0x407, 0x408, 0x411, 0x412, 0x413, 0x416,
			0x419, 0x41a, 0x41c, 0x41d, 0x420, 0x421, 0x422, 0x423, 0x427, 0x429, 0x42b, 0x42c, 0x431,
			0x437, 0x438, 0x439, 0x43a, 0x43c, 0x43f, 0x441, 0x443, 0x444, 0x445, 0x44a, 0x44d, 0x44f);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x453, 0x456, 0x457, 0x458, 0x459, 0x45a, 0x460, 0x466, 0x46a, 0x46b, 0x46c, 0x46e, 0x474,
			0x477, 0x47a, 0x47e, 0x47f, 0x480, 0x485, 0x488, 0x48c, 0x48e, 0x490, 0x493, 0x494, 0x495,
			0x497, 0x498, 0x49b, 0x49f, 0x4ab, 0x4ac, 0x4ad, 0x4ae, 0x4b1, 0x4bc, 0x4bf, 0x4c3, 0x4c6,
			0x4cb, 0x4cd, 0x4d4, 0x4d6, 0x4d9, 0x4dc, 0x4de, 0x4e2, 0x4e3, 0x4e5, 0x4e8, 0x4e9, 0x4ee,
			0x4f4, 0x4f6, 0x4fa, 0x4fe, 0x4ff, 0x500, 0x501, 0x504, 0x506, 0x507, 0x508, 0x50f, 0x511,
			0x515, 0x517, 0x518, 0x519, 0x51d, 0x51e, 0x521, 0x523, 0x52a, 0x52c, 0x52e, 0x532, 0x535);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x538, 0x539, 0x53a, 0x540, 0x545, 0x546, 0x54a, 0x54b, 0x550, 0x553, 0x554, 0x555, 0x559,
			0x55a, 0x55e, 0x55f, 0x562, 0x563, 0x569, 0x56b, 0x56c, 0x56f, 0x570, 0x575, 0x576, 0x577,
			0x579, 0x57f, 0x580, 0x581, 0x587, 0x588, 0x58f, 0x592, 0x59f, 0x5a1, 0x5a2, 0x5a4, 0x5a7,
			0x5ab, 0x5af, 0x5b0, 0x5b1, 0x5b5, 0x5b8, 0x5b9, 0x5bc, 0x5be, 0x5c1, 0x5c3, 0x5c5, 0x5c6,
			0x5c7, 0x5cd, 0x5ce, 0x5cf, 0x5d3, 0x5d5, 0x5dc, 0x5df, 0x5e6, 0x5e7, 0x5e8, 0x5ee, 0x5ef,
			0x5f0, 0x5f2, 0x5f3, 0x5f5, 0x5f6, 0x5f7, 0x5fa, 0x5fe, 0x5ff, 0x600, 0x603, 0x609, 0x60e);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x611, 0x612, 0x613, 0x614, 0x615, 0x619, 0x61b, 0x61d, 0x61f, 0x620, 0x626, 0x62b, 0x62c,
			0x632, 0x633, 0x634, 0x636, 0x639, 0x63b, 0x63c, 0x63e, 0x641, 0x648, 0x64a, 0x64c, 0x64e,
			0x651, 0x658, 0x659, 0x65b, 0x65c, 0x660, 0x661, 0x664, 0x665, 0x666, 0x669, 0x66c, 0x66d,
			0x66f, 0x671, 0x674, 0x676, 0x677, 0x678, 0x67a, 0x682, 0x685, 0x68e, 0x68f, 0x691, 0x695,
			0x697, 0x698, 0x699, 0x69c, 0x69d, 0x6a4, 0x6a6, 0x6a7, 0x6aa, 0x6af, 0x6b0, 0x6b3, 0x6bc,
			0x6bd, 0x6bf, 0x6c2, 0x6c3, 0x6c7, 0x6c9, 0x6ca, 0x6cb, 0x6cc, 0x6ce, 0x6d0, 0x6d6, 0x6d8);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x6d9, 0x6db, 0x6dc, 0x6dd, 0x6de, 0x6e0, 0x6e1, 0x6e2, 0x6e3, 0x6e5, 0x6e7, 0x6f0, 0x6f3,
			0x6f6, 0x6f8, 0x6f9, 0x6fb, 0x6fc, 0x701, 0x704, 0x706, 0x70d, 0x710, 0x711, 0x713, 0x71c,
			0x71f, 0x724, 0x726, 0x728, 0x731, 0x733, 0x737, 0x738, 0x73b, 0x73c, 0x73d, 0x73e, 0x740,
			0x742, 0x743, 0x748, 0x750, 0x751, 0x754, 0x758, 0x75b, 0x75e, 0x764, 0x76e, 0x76f, 0x772,
			0x77b, 0x77e, 0x77f, 0x783, 0x784, 0x785, 0x795, 0x79a, 0x79b, 0x79e, 0x7a0, 0x7a4, 0x7a6,
			0x7a8, 0x7ac, 0x7ae, 0x7af, 0x7b0, 0x7b1, 0x7b2, 0x7b4, 0x7b6, 0x7b8, 0x7ba, 0x7bc, 0x7bd);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x7c0, 0x7c2, 0x7c5, 0x7c7, 0x7cb, 0x7cc, 0x7cd, 0x7ce, 0x7cf, 0x7d2, 0x7d4, 0x7d5, 0x7d7,
			0x7d9, 0x7de, 0x7df, 0x7e3, 0x7e5, 0x7e7, 0x7e8, 0x7ec, 0x7ed, 0x7f3, 0x7f4, 0x7fc, 0x802,
			0x806, 0x808, 0x812, 0x813, 0x817, 0x818, 0x819, 0x81c, 0x81e, 0x820, 0x821, 0x822, 0x823,
			0x827, 0x833, 0x835, 0x836, 0x838, 0x83c, 0x83e, 0x83f, 0x840, 0x845, 0x847, 0x848, 0x849,
			0x84b, 0x84d, 0x84e, 0x84f, 0x853, 0x854, 0x855, 0x857, 0x858, 0x85b, 0x85d, 0x85e, 0x860,
			0x863, 0x864, 0x865, 0x867, 0x870, 0x876, 0x87a, 0x87b, 0x87d, 0x87f, 0x889, 0x88c, 0x88d);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x88f, 0x890, 0x892, 0x894, 0x895, 0x896, 0x89d, 0x8a5, 0x8a7, 0x8aa, 0x8ae, 0x8ba, 0x8bc,
			0x8c0, 0x8c2, 0x8c3, 0x8c4, 0x8c9, 0x8cb, 0x8d4, 0x8d7, 0x8d8, 0x8d9, 0x8dc, 0x8de, 0x8e3,
			0x8e4, 0x8e7, 0x8e8, 0x8f0, 0x8f1, 0x8f2, 0x8f3, 0x8f4, 0x8f5, 0x8f7, 0x8fb, 0x8fc, 0x8fd,
			0x8fe, 0x901, 0x903, 0x907, 0x909, 0x90b, 0x90e, 0x911, 0x912, 0x915, 0x916, 0x91a, 0x91e,
			0x922, 0x925, 0x927, 0x928, 0x92a, 0x92c, 0x933, 0x938, 0x939, 0x93c, 0x93e, 0x941, 0x943,
			0x944, 0x949, 0x94a, 0x94b, 0x94d, 0x94f, 0x950, 0x951, 0x952, 0x959, 0x95a, 0x95b, 0x961);
		RegisterOpCode(0x36, OPCODE_Nop,
			0x962, 0x967, 0x968, 0x969, 0x96e, 0x96f, 0x974, 0x978, 0x982, 0x98a, 0x98c, 0x98d, 0x98f,
			0x992, 0x993, 0x995, 0x999, 0x99a, 0x9a6, 0x9a9, 0x9ae, 0x9b7, 0x9be, 0x9c0, 0x9c1, 0x9c3,
			0x9c6, 0x9c7, 0x9d1, 0x9d4, 0x9d6, 0x9d8, 0x9da, 0x9e0, 0x9e2, 0x9e7, 0x9e8, 0x9ea, 0x9ef,
			0x9f0, 0x9f2, 0x9f4, 0x9f5, 0x9fa, 0x9fc, 0x9fe, 0xa01, 0xa03, 0xa04, 0xa05, 0xa06, 0xa07,
			0xa0f, 0xa10, 0xa13, 0xa14, 0xa17, 0xa18, 0xa1b, 0xa1c, 0xa1d, 0xa1e, 0xa20, 0xa22, 0xa27,
			0xa2a, 0xa2e, 0xa2f, 0xa30, 0xa39, 0xa40, 0xa42, 0xa43, 0xa46, 0xa49, 0xa4a, 0xa52, 0xa57);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xa5e, 0xa5f, 0xa61, 0xa65, 0xa68, 0xa6a, 0xa70, 0xa72, 0xa76, 0xa78, 0xa7a, 0xa80, 0xa82,
			0xa84, 0xa85, 0xa87, 0xa89, 0xa8c, 0xa8d, 0xa90, 0xa91, 0xa93, 0xa94, 0xa98, 0xa9b, 0xa9c,
			0xa9e, 0xa9f, 0xaa0, 0xaa6, 0xaab, 0xab0, 0xab1, 0xab2, 0xab4, 0xab7, 0xaba, 0xabd, 0xabe,
			0xabf, 0xac0, 0xac3, 0xac4, 0xac5, 0xac9, 0xaca, 0xacd, 0xacf, 0xad1, 0xad2, 0xad3, 0xad7,
			0xad8, 0xada, 0xade, 0xadf, 0xae1, 0xae7, 0xae8, 0xaf1, 0xaf2, 0xafc, 0xafe, 0xb00, 0xb01,
			0xb02, 0xb08, 0xb09, 0xb0a, 0xb0d, 0xb15, 0xb1e, 0xb26, 0xb2b, 0xb2c, 0xb2e, 0xb32, 0xb33);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xb39, 0xb3a, 0xb3c, 0xb3f, 0xb40, 0xb41, 0xb43, 0xb44, 0xb47, 0xb4b, 0xb4c, 0xb55, 0xb56,
			0xb57, 0xb61, 0xb68, 0xb6a, 0xb6c, 0xb6e, 0xb70, 0xb71, 0xb75, 0xb77, 0xb7b, 0xb7c, 0xb7d,
			0xb87, 0xb8b, 0xb8c, 0xb8d, 0xb96, 0xb99, 0xb9a, 0xb9e, 0xba0, 0xba3, 0xba5, 0xba9, 0xbab,
			0xbae, 0xbb1, 0xbbb, 0xbc1, 0xbc5, 0xbc6, 0xbc8, 0xbcb, 0xbd5, 0xbda, 0xbdb, 0xbdc, 0xbde,
			0xbe0, 0xbe1, 0xbe5, 0xbe7, 0xbeb, 0xbed, 0xbf1, 0xbf3, 0xbf4, 0xbfb, 0xbfe, 0xbff, 0xc00,
			0xc03, 0xc05, 0xc0a, 0xc0c, 0xc0f, 0xc10, 0xc11, 0xc13, 0xc16, 0xc17, 0xc1c, 0xc1f, 0xc20);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xc21, 0xc29, 0xc2b, 0xc2d, 0xc2f, 0xc35, 0xc38, 0xc3a, 0xc3d, 0xc3f, 0xc41, 0xc42, 0xc45,
			0xc49, 0xc50, 0xc52, 0xc54, 0xc55, 0xc56, 0xc57, 0xc58, 0xc59, 0xc5a, 0xc61, 0xc63, 0xc67,
			0xc71, 0xc72, 0xc74, 0xc76, 0xc78, 0xc7a, 0xc7f, 0xc81, 0xc84, 0xc86, 0xc8a, 0xc8c, 0xc92,
			0xc97, 0xc9c, 0xca4, 0xca5, 0xca7, 0xca8, 0xca9, 0xcae, 0xcaf, 0xcb0, 0xcb4, 0xcb9, 0xcbf,
			0xcc0, 0xcc1, 0xcce, 0xcd3, 0xcd4, 0xcd5, 0xcdc, 0xcdd, 0xcde, 0xcdf, 0xce2, 0xce3, 0xce5,
			0xce9, 0xcea, 0xceb, 0xced, 0xcee, 0xcf0, 0xcf5, 0xcf6, 0xcf7, 0xcf8, 0xcfe, 0xd03, 0xd05);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xd07, 0xd09, 0xd0f, 0xd10, 0xd11, 0xd12, 0xd19, 0xd1b, 0xd26, 0xd28, 0xd2a, 0xd2c, 0xd2f,
			0xd36, 0xd39, 0xd3a, 0xd3b, 0xd3e, 0xd3f, 0xd43, 0xd44, 0xd45, 0xd46, 0xd4b, 0xd4d, 0xd4e,
			0xd51, 0xd53, 0xd57, 0xd59, 0xd5c, 0xd5d, 0xd62, 0xd63, 0xd66, 0xd67, 0xd69, 0xd6c, 0xd6e,
			0xd73, 0xd74, 0xd7b, 0xd83, 0xd84, 0xd85, 0xd86, 0xd8a, 0xd8e, 0xd92, 0xd95, 0xd99, 0xd9b,
			0xd9c, 0xd9e, 0xd9f, 0xda1, 0xda2, 0xda5, 0xda9, 0xdac, 0xdad, 0xdb0, 0xdb2, 0xdb7, 0xdb9,
			0xdbc, 0xdbd, 0xdbf, 0xdc2, 0xdc4, 0xdc6, 0xdc9, 0xdcd, 0xdce, 0xdd0, 0xdd4, 0xdd5, 0xdd9);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xde0, 0xde1, 0xde2, 0xde3, 0xde5, 0xde7, 0xde9, 0xdf0, 0xdf1, 0xdf3, 0xdf8, 0xdf9, 0xdfb,
			0xe01, 0xe02, 0xe05, 0xe07, 0xe09, 0xe0e, 0xe0f, 0xe12, 0xe13, 0xe14, 0xe19, 0xe1b, 0xe1d,
			0xe21, 0xe25, 0xe26, 0xe28, 0xe2a, 0xe2b, 0xe2d, 0xe2e, 0xe30, 0xe36, 0xe38, 0xe3e, 0xe3f,
			0xe40, 0xe43, 0xe44, 0xe48, 0xe49, 0xe4a, 0xe4b, 0xe4f, 0xe50, 0xe52, 0xe59, 0xe5f, 0xe63,
			0xe64, 0xe68, 0xe6b, 0xe6c, 0xe70, 0xe71, 0xe7a, 0xe7e, 0xe82, 0xe84, 0xe85, 0xe86, 0xe8a,
			0xe8b, 0xe8e, 0xe92, 0xe95, 0xe98, 0xe9f, 0xea0, 0xea1, 0xea2, 0xea4, 0xea7, 0xeaf, 0xeb1);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xeb6, 0xeb7, 0xeb9, 0xebb, 0xebc, 0xec2, 0xec3, 0xec4, 0xec5, 0xec6, 0xec9, 0xecb, 0xecd,
			0xece, 0xed3, 0xed5, 0xed7, 0xeda, 0xede, 0xee0, 0xee1, 0xee4, 0xee7, 0xeeb, 0xeee, 0xef0,
			0xef7, 0xefa, 0xefc, 0xf01, 0xf02, 0xf03, 0xf04, 0xf07, 0xf0a, 0xf0b, 0xf0c, 0xf0e, 0xf0f,
			0xf10, 0xf15, 0xf17, 0xf19, 0xf1a, 0xf1c, 0xf1d, 0xf1e, 0xf1f, 0xf20, 0xf24, 0xf27, 0xf28,
			0xf29, 0xf2b, 0xf2c, 0xf2d, 0xf30, 0xf32, 0xf33, 0xf34, 0xf35, 0xf36, 0xf3c, 0xf43, 0xf46,
			0xf48, 0xf4f, 0xf55, 0xf5e, 0xf69, 0xf6a, 0xf6c, 0xf6e, 0xf74, 0xf77, 0xf78, 0xf82, 0xf83);
		RegisterOpCode(0x36, OPCODE_Nop,
			0xf84, 0xf85, 0xf87, 0xf8b, 0xf97, 0xf9a, 0xf9c, 0xf9e, 0xfa1, 0xfa2, 0xfa6, 0xfa9, 0xfad,
			0xfaf, 0xfb2, 0xfb5, 0xfb6, 0xfbb, 0xfbc, 0xfbf, 0xfc2, 0xfce, 0xfcf, 0xfd4, 0xfd6, 0xfd7,
			0xfd8, 0xfda, 0xfdb, 0xfe3, 0xfe5, 0xfe8, 0xfeb, 0xff8, 0xffc, 0xffd
		);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableCachedDebug, 0x8);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableRefCachedDebug, 0x9);
		RegisterOpCode(0x36, OPCODE_ClearParams, 0xc);
		RegisterOpCode(0x36, OPCODE_CheckClearParams, 0xd);
		RegisterOpCode(0x36, OPCODE_PreScriptCall, 0xe);
		RegisterOpCode(0x36, OPCODE_CallBuiltinFunction, 0xf);
		RegisterOpCode(0x36, OPCODE_CallBuiltinMethod, 0x10);
		RegisterOpCode(0x36, OPCODE_End, 0x11);
		RegisterOpCode(0x36, OPCODE_EmptyArray, 0x15, 0xbc, 0x1ab, 0x1c1, 0x449, 0x478, 0x479, 0x4b2, 0x582, 0x8c8, 0xb28, 0xb46, 0xbb9, 0xccf, 0xd0d, 0xfea);
		RegisterOpCode(0x36, OPCODE_WaitTill, 0x17, 0xc8, 0x167, 0x1ac, 0x568, 0x6d1, 0x80b, 0x9bc, 0xa6e, 0xc15, 0xf31);
		RegisterOpCode(0x36, OPCODE_ClearFieldVariableOnStack, 0x19, 0x1e9, 0x212, 0x284, 0x290, 0x2f3, 0x2ff, 0x32f, 0x405, 0x42e, 0x49a, 0x543, 0x599, 0x5cc,
			0x5e0, 0x74e, 0x74f, 0x7ca, 0x81a, 0x95c, 0x979, 0x97e, 0xbad, 0xbe6, 0xcd1, 0xd17, 0xdf5, 0xe2c, 0xf3a, 0xfd0);
		RegisterOpCode(0x36, OPCODE_ClearArray, 0x1b, 0xbe, 0x1e8, 0x208, 0x3bb, 0x463, 0x516, 0x6c0, 0x762, 0x7b9, 0x7dd, 0x871, 0x8ac, 0x9a1, 0x9b4, 0x9f3, 0xa6f, 0xd49, 0xe23, 0xea3);
		RegisterOpCode(0x36, OPCODE_ScriptMethodThreadCallPointer, 0x1c, 0x145, 0x1d3, 0x2b3, 0x335, 0x4c7, 0x524, 0x5d6, 0x631, 0x656, 0x6ea, 0x715, 0x7d6, 0x825, 0x931, 0x9a7, 0xa5a,
			0xb21, 0xbd2, 0xbf9, 0xcff, 0xdd2, 0xe20, 0xe51, 0xf7a, 0xf7d);
		RegisterOpCode(0x36, OPCODE_WaitTillMatchTimeout, 0x1d, 0x81, 0x1f5, 0x283, 0x2a3, 0x3b8, 0x452, 0x58a, 0x60c, 0x643, 0x65e, 0x694, 0x811, 0x878, 0x8a4, 0x8ef, 0x8f8, 0xaa4,
			0xc70, 0xccc, 0xcda, 0xd2d, 0xdb1, 0xeaa);
		RegisterOpCode(0x36, OPCODE_GetHash, 0x1f, 0x85, 0x107, 0x28f, 0x3b1, 0x4b0, 0x4ba, 0x4da, 0x5b3, 0x63f, 0x6d2, 0x7e0, 0x8a6, 0x8eb, 0x904, 0x96d, 0xa28, 0xa77, 0xaff, 0xbe9,
			0xc23, 0xc39, 0xc9d, 0xd31, 0xe1f, 0xe69, 0xed2, 0xff7);
		RegisterOpCode(0x36, OPCODE_WaitFrame, 0x20, 0xc5, 0x16d, 0x20f, 0x264, 0x280, 0x33a, 0x3b9, 0x4be, 0x4e4, 0x5a3, 0x716, 0x765, 0x898, 0x914, 0x96c, 0xa3e, 0xa92, 0xb13, 0xb90,
			0xcac, 0xd14, 0xd8c, 0xfab, 0xfb1);
		RegisterOpCode(0x36, OPCODE_ScriptMethodThreadCallPointerEndOn, 0x22, 0xa2, 0xa6, 0x1cf, 0x1da, 0x2c0, 0x2e2, 0x30c, 0x35e, 0x37b, 0x37d, 0x396, 0x3c9, 0x3f6, 0x4c4, 0x5ec,
			0x76a, 0x89f, 0x8d3, 0x906, 0x948, 0xbcf, 0xc6a, 0xc6f, 0xcc9, 0xe9b, 0xfbe);
		RegisterOpCode(0x36, OPCODE_WaitTillMatch, 0x24, 0x47, 0x58, 0x70, 0xdd, 0x21f, 0x251, 0x296, 0x2d9, 0x391, 0x4b7, 0x503, 0x57d, 0x6a0, 0x7a2, 0x97d, 0x991, 0xa48, 0xb58,
			0xb9d, 0xbf5, 0xcec, 0xd72, 0xd7c, 0xe47, 0xe93, 0xef5);
		RegisterOpCode(0x36, OPCODE_ScriptThreadCallEndOn, 0x26, 0xfe, 0x23f, 0x2a2, 0x3c8, 0x4d8, 0x4eb, 0x526, 0x629, 0x688, 0x70b, 0x788, 0x868, 0xa1f, 0xa64, 0xaeb, 0xbb8, 0xbd3,
			0xc4d, 0xd1f, 0xd35, 0xdb3, 0xe42, 0xeb3, 0xeb8, 0xf7f, 0xfe2);
		RegisterOpCode(0x36, OPCODE_Switch, 0x29, 0x2a, 0xa0, 0x2f6, 0x4b9, 0x7f5, 0x83b, 0x918, 0x9ad, 0x9cc, 0x9f7, 0xac6, 0xb38, 0xb92, 0xbf7, 0xc02, 0xe87, 0xee5, 0xf58, 0xf73);
		RegisterOpCode(0x36, OPCODE_ScriptFunctionCallPointer, 0x2e, 0x23c, 0x243, 0x2ed, 0x326, 0x345, 0x3d1, 0x424, 0x440, 0x447, 0x454, 0x473, 0x541, 0x5e2, 0x5fc, 0x622, 0x652,
			0x773, 0x78c, 0x794, 0x856, 0x8a8, 0x8af, 0xa0a, 0xadd, 0xe1e, 0xecf, 0xfa0, 0xffe);
		RegisterOpCode(0x36, OPCODE_DevblockBegin, 0x31, 0x147, 0x157, 0x1a9, 0x1b6, 0x262, 0x279, 0x2c2, 0x3e5, 0x44b, 0x672, 0x6f4, 0x85f, 0x8d2, 0x92b, 0x987, 0x9ca, 0xa29, 0xa71,
			0xadc, 0xb3d, 0xbb2, 0xd1d, 0xdee, 0xef1, 0xf00, 0xf41);
		RegisterOpCode(0x36, OPCODE_NotEqual, 0x32, 0x28b, 0x291, 0x2cf, 0x2f1, 0x379, 0x3cb, 0x48b, 0x49d, 0x51b, 0x53b, 0x6f2, 0x8db, 0x913, 0x9ed, 0xd77, 0xd79, 0xde6, 0xe9a, 0xf9d);
		RegisterOpCode(0x36, OPCODE_ScriptMethodCallPointer, 0x33, 0x3a, 0xb8, 0x238, 0x2be, 0x342, 0x638, 0x9b1, 0x9b6, 0xa0b, 0xa95, 0xc77, 0xf67);
		RegisterOpCode(0x36, OPCODE_JumpOnTrue, 0x34, 0x64, 0xb0, 0x374, 0x385, 0x3ff, 0x43d, 0x44c, 0x4f5, 0x623, 0x769, 0x905, 0x91c, 0x958, 0x9d9, 0xc4e, 0xcfa, 0xd8f, 0xe57);
		RegisterOpCode(0x36, OPCODE_Unknown35, 0x35, 0x4a, 0x175, 0x1c8, 0x235, 0x2f8, 0x3e3, 0x4a0, 0x4f7, 0x552, 0x604, 0x7f0, 0x8c7, 0x91b, 0x930, 0xa26, 0xc04, 0xca1, 0xddc, 0xed9);
		RegisterOpCode(0x36, OPCODE_ScriptMethodThreadCallEndOn, 0x36, 0x172, 0x38a, 0x621, 0x775, 0xa2d, 0xa5c, 0xdbe, 0xf4c, 0xfcb);
		RegisterOpCode(0x36, OPCODE_SafeCreateLocalVariables, 0x37, 0x89, 0x150, 0x1a8, 0x261, 0x26f, 0x334, 0x34c, 0x3cd, 0x489, 0x533, 0x640, 0x65d, 0x719, 0x807, 0x882, 0x955, 0xae5,
			0xb2f, 0xbbf, 0xbd4, 0xc6b, 0xc89, 0xdde, 0xe83, 0xebd, 0xf44, 0xf61, 0xfb7);
		RegisterOpCode(0x36, OPCODE_Unknown38, 0x38, 0x6f, 0x72, 0xca, 0xda, 0x178, 0x269, 0x316, 0x409, 0x578, 0x642, 0x797, 0x79d, 0x7e6, 0x98e, 0x997, 0x99b, 0xb3e, 0xbb0, 0xbdd,
			0xd94, 0xdb5, 0xddd, 0xe4e, 0xe58, 0xf4a);
		RegisterOpCode(0x36, OPCODE_GetNegUnsignedShort, 0x39, 0x14e, 0x1b2, 0x1f9, 0x202, 0x35f, 0x3db, 0x3f1, 0x406, 0x51a, 0x714, 0x76b, 0x799, 0x7fa, 0x815, 0x85c, 0x897, 0x8ce,
			0xa37, 0xad0, 0xaf3, 0xb1d, 0xb3b, 0xd64, 0xdff, 0xf7b, 0xfb8);
		RegisterOpCode(0x36, OPCODE_ClassFunctionCall, 0x3b, 0x5d, 0x14b, 0x27e, 0x29a, 0x58e, 0x61a, 0x70a, 0x78d, 0x78f, 0x850, 0x8a0, 0x94c, 0xa8a, 0xb14, 0xba1, 0xbcc, 0xbf8, 0xcd9, 0xdca, 0xf23);
		RegisterOpCode(0x36, OPCODE_Return, 0x3c, 0xb1, 0x26c, 0x288, 0x36b, 0x45e, 0x482, 0x547, 0x57e, 0x68c, 0x73f, 0x800, 0x885, 0x9ab, 0x9fb, 0x9fd, 0xa16, 0xb0b, 0xbee, 0xc07,
			0xd34, 0xe4d, 0xf08, 0xf1b, 0xf21, 0xf62, 0xfaa, 0xfb4);
		RegisterOpCode(0x36, OPCODE_EvalFieldVariableRef, 0x40, 0x7d, 0x1f0, 0x29c, 0x2b7, 0x487, 0x4ec, 0x4ed, 0x593, 0x5c0, 0x69e, 0x700, 0x72b, 0x786, 0x7ab, 0x80d, 0x8df, 0x9d5,
			0xa50, 0xaf5, 0xb48, 0xb94, 0xbfc, 0xc06, 0xc1d, 0xe79, 0xe88, 0xef2, 0xf9f);
		RegisterOpCode(0x36, OPCODE_SafeDecTop, 0x42, 0x60, 0x98, 0xb9, 0x3c6, 0x67b, 0x72f, 0x759, 0x805, 0x888, 0x88e, 0x902, 0x920, 0x946, 0x96a, 0xa0e, 0xb1a, 0xb1f, 0xeec, 0xfc5);
		RegisterOpCode(0x36, OPCODE_Bit_Or, 0x44, 0x197, 0x23a, 0x2de, 0x350, 0x3a0, 0x43b, 0x56a, 0x595, 0x68a, 0x6e9, 0x761, 0x8d1, 0x940, 0xa6b, 0xdeb, 0xed0, 0xf4e);
		RegisterOpCode(0x36, OPCODE_ScriptThreadCall, 0x45, 0x9d, 0xa4, 0x1aa, 0x223, 0x356, 0x392, 0x442, 0x8cd, 0x966, 0xa63, 0xabb, 0xb34, 0xb98, 0xd48, 0xd5a, 0xe10, 0xef4, 0xf53, 0xfdc);
		RegisterOpCode(0x36, OPCODE_Bit_Xor, 0x46, 0x213, 0x257, 0x33e, 0x36e, 0x4af, 0x8dd, 0x937, 0x956, 0x9c9, 0xaf7, 0xb76, 0xb79, 0xc5c, 0xc5e, 0xc75, 0xc83, 0xd41, 0xdc1);
		RegisterOpCode(0x36, OPCODE_GetSelfObject, 0x49, 0x59, 0x5a, 0x6b, 0x125, 0x129, 0x196, 0x3f5, 0x472, 0x4e7, 0x54d, 0x571, 0x62e, 0x6e8, 0x756, 0x7bf, 0x8ad, 0x91d, 0xa2c,
			0xa38, 0xd47, 0xea5, 0xf11, 0xf81, 0xf96, 0xfa4, 0xfdd);
		RegisterOpCode(0x36, OPCODE_GetNegByte, 0x4b, 0x199, 0x21e, 0x29d, 0x3b6, 0x42d, 0x549, 0x583, 0x6a3, 0x8ec, 0x9e5, 0xa24, 0xa3f, 0xbd9, 0xc19, 0xc79, 0xca2, 0xcb7, 0xd78,
			0xd81, 0xdfc, 0xe62, 0xf22, 0xf5a, 0xfd2);
		RegisterOpCode(0x36, OPCODE_ScriptThreadCallPointerEndOn, 0x4c, 0x57, 0x162, 0x35a, 0x35d, 0x371, 0x375, 0x414, 0x468, 0x4b3, 0x4dd, 0x5f1, 0x693, 0x6c6, 0x720, 0x77c, 0x7e2,
			0x824, 0x82e, 0xc30, 0xd5e, 0xe03, 0xe66, 0xe94, 0xfc4);
		RegisterOpCode(0x36, OPCODE_BoolComplement, 0x4d, 0x13a, 0x3b7, 0x42a, 0x514, 0x573, 0x5d0, 0x5f4, 0x668, 0x71b, 0x89e, 0x8b4, 0x9d7, 0xa88, 0xac7, 0xcf2, 0xe33, 0xe5d, 0xead);
		RegisterOpCode(0x36, OPCODE_IsDefined, 0x4e, 0x77, 0x38c, 0x3c3, 0x3ee, 0x481, 0x55c, 0x565, 0x5d2, 0x5dd, 0x5e4, 0x736, 0x74d, 0x79c, 0x7f1, 0x841, 0x94e, 0xaec, 0xb20, 0xb36,
			0xb51, 0xb93, 0xc08, 0xc14, 0xc26, 0xe74, 0xf5d, 0xf79);
		RegisterOpCode(0x36, OPCODE_AddToArray, 0x51, 0x119, 0x146, 0x180, 0x4e1, 0x510, 0x60a, 0x64f, 0x6d5, 0x777, 0x986, 0xa60, 0xaf4, 0xc7c, 0xe60, 0xfae);
		RegisterOpCode(0x36, OPCODE_Wait, 0x54, 0x10c, 0x17d, 0x324, 0x3e6, 0x67d, 0x6ec, 0x809, 0x923, 0xc5b, 0xc64, 0xded, 0xe5a, 0xee9, 0xf49, 0xf5f, 0xfc0);
		RegisterOpCode(0x36, OPCODE_SuperEqual, 0x55, 0xcc, 0x1bd, 0x30b, 0x31c, 0x361, 0x4a4, 0x522, 0x7b7, 0x7e1, 0x8c5, 0x93a, 0x9b0, 0x9c5, 0xa3d, 0xa45, 0xa69, 0xb72, 0xbdf, 0xd27,
			0xd6a, 0xd8b, 0xdae, 0xdd1, 0xdd8, 0xe16, 0xed4, 0xf3b, 0xf4d, 0xff6);
		RegisterOpCode(0x36, OPCODE_GetUndefined, 0x56, 0x1a3, 0x1cd, 0x358, 0x739, 0x84a, 0x9f6, 0xb6b, 0xdef, 0xe3c, 0xf92, 0xfa5, 0xff4);
		RegisterOpCode(0x36, OPCODE_ScriptFunctionCall, 0x5c, 0x68, 0xa7, 0x17e, 0x24c, 0x327, 0x37c, 0x75c, 0x814, 0x834, 0x880, 0x97f, 0xac8, 0xbb6, 0xc0e, 0xc9b, 0xcb5,
			0xcf1, 0xde4, 0xeca, 0xfd3);
		RegisterOpCode(0x36, OPCODE_EvalFieldVariableOnStackRef, 0x5f, 0x65, 0x93, 0x1d2, 0x219, 0x28c, 0x40e, 0x448, 0x450, 0x4d5, 0x6ac, 0x877, 0x970, 0x97a, 0x9b5, 0xb31, 0xbc7,
			0xc4f, 0xdb4, 0xe15, 0xe8c, 0xe96, 0xf64);
		RegisterOpCode(0x36, OPCODE_JumpOnTrueExpr, 0x61, 0x10a, 0x170, 0x17c, 0x2a9, 0x2fc, 0x303, 0x3bd, 0x618, 0x69f, 0x7bb, 0x8fa, 0x9f1, 0xa6d, 0xaf6, 0xb12, 0xb27, 0xbe8,
			0xbfa, 0xca6, 0xcc7, 0xe1c, 0xe78, 0xef8, 0xf06, 0xf98);
		RegisterOpCode(0x36, OPCODE_CreateArray, 0x62, 0x1fb, 0x255, 0x2fb, 0x39c, 0x461, 0x505, 0x58d, 0x6ba, 0x6ff, 0x75d, 0x832, 0x8e0, 0x9c8, 0x9cb, 0x9e3, 0xab6, 0xb5c, 0xb63,
			0xb83, 0xbce, 0xc09, 0xd1c, 0xd58, 0xe37, 0xe5e, 0xf70, 0xf7c);
		RegisterOpCode(0x36, OPCODE_Inc, 0x63, 0x8f, 0x1fe, 0x304, 0x35c, 0x36d, 0x3ba, 0x4cf, 0x4f1, 0x5aa, 0x7eb, 0x8b3, 0xa7e, 0xb19, 0xdc8, 0xf51, 0xfb0);
		RegisterOpCode(0x36, OPCODE_ShiftLeft, 0x6a, 0xb4, 0x179, 0x186, 0x249, 0x3b0, 0x3d4, 0x465, 0x483, 0x49c, 0x4b6, 0x584, 0x654, 0x6e4, 0x6f1, 0x75f, 0x85a, 0x9a8, 0xaea,
			0xaed, 0xb03, 0xb30, 0xba6, 0xc48, 0xc7e, 0xcc8, 0xcd7, 0xd06, 0xe34, 0xfc6);
		RegisterOpCode(0x36, OPCODE_JumpOnGreaterThan, 0x6c, 0x102, 0x164, 0x389, 0x435, 0x5b7, 0x650, 0x6c8, 0x796, 0x7b5, 0x953, 0xc9e, 0xce7, 0xe0b, 0xe6e, 0xe7c);
		RegisterOpCode(0x36, OPCODE_Plus, 0x6e, 0xae, 0x104, 0x106, 0x144, 0x2a6, 0x323, 0x51f, 0x596, 0x59a, 0x59e, 0x8e6, 0x975, 0xa56, 0xb4d, 0xb54, 0xbac, 0xd7e, 0xef3, 0xfca);
		RegisterOpCode(0x36, OPCODE_CastAndEvalFieldVariable, 0x71, 0x32b, 0x340, 0x512, 0x7a3, 0x80a, 0x8e1, 0xb4a, 0xb7e, 0xbaa, 0xbd7, 0xcd2, 0xe41, 0xedd, 0xf80);
		RegisterOpCode(0x36, OPCODE_ShiftRight, 0x76, 0x24a, 0x366, 0x3d3, 0x6b9, 0x707, 0x7fe, 0x86b, 0x8ed, 0xa02, 0xa35, 0xab5, 0xda4, 0xf71, 0xfba);
		RegisterOpCode(0x36, OPCODE_CreateStruct, 0x78, 0x1eb, 0x201, 0x2bc, 0x3f9, 0x455, 0x52b, 0x65f, 0x679, 0x72c, 0x873, 0x8b5, 0xa66, 0xbc2, 0xd75, 0xdc7, 0xe00, 0xeb0);
		RegisterOpCode(0x36, OPCODE_CastCanon, 0x7a, 0xd7, 0x15f, 0x265, 0x2b4, 0x2b6, 0x2f4, 0x39b, 0x5db, 0x722, 0x730, 0x7da, 0x8d0, 0x9a3, 0x9d3, 0xbe2, 0xc27);
		RegisterOpCode(0x36, OPCODE_GreaterThanOrEqualTo, 0x7b, 0x211, 0x29f, 0x315, 0x4c8, 0x5e9, 0x5eb, 0x69a, 0x87e, 0xa83, 0xad4, 0xb07, 0xb10, 0xb8e, 0xb91, 0xcbd, 0xd70,
			0xf14, 0xf45, 0xfed);
		RegisterOpCode(0x36, OPCODE_SetVariableFieldRef, 0x7c, 0xf7, 0x133, 0x154, 0x1ff, 0x388, 0x492, 0x57a, 0x8a2, 0x8d5, 0x954, 0xa33, 0xc47, 0xc96, 0xd55, 0xd6b, 0xe6f, 0xf40);
		RegisterOpCode(0x36, OPCODE_GetUIntPtr, 0x7e, 0xf9, 0x2c3, 0x35b, 0x3e8, 0x410, 0x47b, 0x525, 0x5a0, 0x5cb, 0x70c, 0xa47, 0xb60, 0xd15, 0xd22, 0xedf, 0xf76);
		RegisterOpCode(0x36, OPCODE_GetLongInteger, 0x82, 0x13d, 0x1df, 0x377, 0x39f, 0x602, 0x662, 0x69b, 0x801, 0x804, 0x9af, 0x9eb, 0xa4f, 0xafa, 0xb42, 0xb67, 0xb73, 0xb81,
			0xc0b, 0xc4b, 0xca3, 0xd8d, 0xdb8, 0xe17, 0xe65);
		RegisterOpCode(0x36, OPCODE_EvalArray, 0x8a, 0x12a, 0x1de, 0x278, 0x2df, 0x36c, 0x496, 0x4f8, 0x50e, 0x5ed, 0x65a, 0x6a2, 0x6eb, 0x9e4, 0x9ec, 0xa11, 0xae4, 0xaf9, 0xafd,
			0xc24, 0xc2c, 0xdda, 0xdf2, 0xe11, 0xf09, 0xf6d);
		RegisterOpCode(0x36, OPCODE_WaitTillFrameEnd, 0x8b, 0x11e, 0x285, 0x2ab, 0x2c1, 0x390, 0x3e0, 0x64d, 0x79f, 0x89a, 0x8a9, 0x8ab, 0x976, 0x9ff, 0xb65, 0xb6d, 0xb80, 0xbf0,
			0xc2a, 0xc37, 0xc80, 0xddf, 0xe08);
		RegisterOpCode(0x36, OPCODE_EndOnCallback, 0x8c, 0xd4, 0x56e, 0x605, 0x908, 0x9c4, 0x9ce, 0xb9f, 0xbd1, 0xefd);
		RegisterOpCode(0x36, OPCODE_FirstArrayKey, 0x8d, 0x22d, 0x30e, 0x57c, 0x78a, 0x899, 0x964, 0xa23, 0xb8a, 0xd01, 0xdf6, 0xfc7);
		RegisterOpCode(0x36, OPCODE_SetVariableField, 0x8e, 0xf3, 0x21b, 0x28e, 0x2ee, 0x830, 0x831, 0x9bf, 0xa96, 0xbcd, 0xbd6, 0xc18, 0xd08, 0xd9a, 0xda6, 0xf8f, 0xfd9, 0xfec);
		RegisterOpCode(0x36, OPCODE_EndOn, 0x91, 0xb5, 0xe6, 0x10d, 0x237, 0x246, 0x272, 0x341, 0x40d, 0x45b, 0x45d, 0x4d2, 0x667, 0x6be, 0x6e6, 0x6ee, 0x734, 0x80c, 0x92f, 0x960,
			0xa7d, 0xacb, 0xb89, 0xc1a, 0xd1a, 0xd23, 0xd9d, 0xe0d, 0xfa7);
		RegisterOpCode(0x36, OPCODE_SuperNotEqual, 0x92, 0x13e, 0x1ce, 0x2a5, 0x359, 0x426, 0x61c, 0x725, 0xa99, 0xb18, 0xb5a, 0xd90);
		RegisterOpCode(0x36, OPCODE_GetFloat, 0x94, 0x100, 0x183, 0x1e2, 0x20a, 0x381, 0x3d8, 0x3e4, 0x598, 0x5ad, 0x630, 0x70f, 0x74a, 0x7a5, 0x7ea, 0x883, 0x8f9, 0xaa7, 0xb50,
			0xb7f, 0xce1, 0xd3d, 0xe39, 0xf52, 0xfc9);
		RegisterOpCode(0x36, OPCODE_ProfileStart, 0x95, 0xba, 0x1d0, 0x228, 0x242, 0x2bd, 0x556, 0x5bf, 0x62d, 0x6cf, 0x7ee, 0x82d, 0xa3a, 0xa5d, 0xaa5, 0xaa9, 0xace, 0xad6, 0xba7,
			0xbc0, 0xd89, 0xdbb, 0xdc0, 0xe04, 0xe80, 0xec8, 0xf5b, 0xfe0);
		RegisterOpCode(0x36, OPCODE_GetString, 0x96, 0x1b0, 0x217, 0x231, 0x2af, 0x2d6, 0x380, 0x467, 0x601, 0x608, 0x6c1, 0x8b0, 0x9de, 0xc44, 0xd4c, 0xff1);
		RegisterOpCode(0x36, OPCODE_BoolNot, 0x9a, 0x13c, 0x19a, 0x1d8, 0x220, 0x566, 0x606, 0x6b2, 0x7d1, 0xaac, 0xc6c, 0xda0, 0xe73, 0xeab, 0xf39, 0xf3e, 0xf5c, 0xfd1, 0xff0, 0xffa);
		RegisterOpCode(0x36, OPCODE_CastBool, 0x9b, 0xed, 0x11b, 0x152, 0x1c4, 0x364, 0x464, 0x49e, 0x537, 0x585, 0x681, 0x78b, 0x881, 0x90c, 0x9e1, 0xa32, 0xa4b, 0xa59, 0xa5b, 0xc3b, 0xcb8, 0xe3a, 0xeff);
		RegisterOpCode(0x36, OPCODE_Unknown9e, 0x9e, 0xe7, 0x1a5, 0x1b1, 0x1f8, 0x274, 0x287, 0x28d, 0x31a, 0x372, 0x3fa, 0x40b, 0x41e, 0x4f3, 0x6ad, 0x6b1, 0x6d7, 0x839, 0x988, 0xa74,
			0xb66, 0xb82, 0xbc4, 0xc34, 0xc7d, 0xcbc, 0xd0e, 0xf18, 0xf8a, 0xfc1);
		RegisterOpCode(0x36, OPCODE_Equal, 0x9f, 0x11c, 0x21d, 0x24e, 0x2e5, 0x531, 0x5bb, 0x627, 0x717, 0x7db, 0x93f, 0x95e, 0xaa8, 0xb0c, 0xc8f, 0xddb, 0xea8, 0xf2e);
		RegisterOpCode(0x36, OPCODE_GetUnsignedInteger, 0xa1, 0x15a, 0x1bf, 0x330, 0x44e, 0x591, 0x5d9, 0x637, 0x768, 0x76d, 0x7fd, 0x80e, 0x879, 0x90a, 0x972, 0xd1e, 0xd6d, 0xd6f, 0xdf7, 0xe91, 0xf2a);
		RegisterOpCode(0x36, OPCODE_WaittillTimeout, 0xa9, 0xb7, 0x149, 0x189, 0x198, 0x293, 0x360, 0x3f8, 0x57b, 0x5f8, 0x703, 0x723, 0x7d8, 0x81b, 0x859, 0x8b8, 0x989, 0x9f8, 0xa79,
			0xb59, 0xbaf, 0xbbd, 0xbe3, 0xd71, 0xdb6, 0xdf4, 0xeb2, 0xf8d);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableCachedSafe, 0xad, 0x10f, 0x12d, 0x141, 0x696, 0x77d, 0xa3c, 0xb2a, 0xbfd, 0xdcb, 0xfbd);
		RegisterOpCode(0x36, OPCODE_GreaterThan, 0xbb, 0x110, 0x2dd, 0x3cf, 0x3f7, 0x4d1, 0x534, 0x5b2, 0x8bd, 0xa19, 0xb5b, 0xcb3, 0xdab, 0xf25, 0xfb3);
		RegisterOpCode(0x36, OPCODE_Jump, 0xc0, 0x151, 0x16a, 0x502, 0x5c8, 0x5f9, 0x73a, 0x75a, 0x86d, 0x8ca, 0x900, 0x924, 0x942, 0x9d0, 0xaf8, 0xcaa, 0xcdb, 0xdcc, 0xdfe, 0xfe9);
		RegisterOpCode(0x36, OPCODE_Divide, 0xc1, 0x2ca, 0x3c0, 0x469, 0x486, 0x826, 0x9e6, 0xc90, 0xe61, 0xea9, 0xfe4);
		RegisterOpCode(0x36, OPCODE_EndSwitch, 0xc2, 0x200, 0x23e, 0x2ef, 0x314, 0x386, 0x394, 0x40f, 0x41f, 0x43e, 0x462, 0x46d, 0x4b5, 0x574, 0x6d3, 0x792, 0x7a9, 0x7f8, 0x7fb,
			0x81f, 0x86e, 0xad9, 0xb53, 0xc3e, 0xcc2, 0xe45, 0xf4b, 0xfef);
		RegisterOpCode(0x36, OPCODE_SetLocalVariableCachedOnStack, 0xc4, 0xcf, 0xd0, 0x224, 0x26e, 0x2a8, 0x337, 0x349, 0x365, 0x4a2, 0x4f2, 0x54e, 0x647, 0x72e, 0x760, 0x91f, 0x998, 0x99e, 0xa6c,
			0xa8f, 0xb6f, 0xc82, 0xec1, 0xf59, 0xfa8);
		RegisterOpCode(0x36, OPCODE_Unknownc7, 0xc7, 0x3a7, 0x50c, 0x567, 0x624, 0x67c, 0x708, 0x776, 0x778, 0x780, 0x842, 0x88a, 0x8bb, 0xa2b, 0xa7c, 0xae2, 0xae9, 0xba4, 0xbb5,
			0xc43, 0xdaf, 0xdcf, 0xe46, 0xe54, 0xe6d, 0xeae, 0xeb5, 0xf99);
		RegisterOpCode(0x36, OPCODE_JumpOnFalse, 0xc9, 0x1c2, 0x204, 0x2d3, 0x3cc, 0x3dc, 0x430, 0x4e0, 0x6b6, 0x6da, 0x757, 0x7dc, 0xa08, 0xb25, 0xb4e, 0xc1b, 0xcc4, 0xdfd, 0xe22,
			0xe77, 0xe8d, 0xf0d, 0xf12, 0xfee);
		RegisterOpCode(0x36, OPCODE_JumpOnFalseExpr, 0xce, 0x275, 0x347, 0x594, 0x59d, 0x63a, 0x95d, 0x996, 0x9db, 0xafb, 0xb23, 0xb84, 0xcd0, 0xd20, 0xd5b, 0xe35, 0xe67, 0xe90,
			0xea6, 0xf7e);
		RegisterOpCode(0x36, OPCODE_EvalSelfFieldVariable, 0xd3, 0x134, 0x1f7, 0x46f, 0x59c, 0x657, 0x66b, 0x774, 0x88b, 0x8a3, 0x93b, 0xaaf, 0xbb7, 0xc2e, 0xcca, 0xce8, 0xd91);
		RegisterOpCode(0x36, OPCODE_Minus, 0xd9, 0x13b, 0x22a, 0x395, 0x520, 0x536, 0x6ae, 0x6fe, 0x771, 0x86a, 0x963, 0xa97, 0xb1c, 0xb24, 0xbc3, 0xbc9, 0xe5c, 0xe7f, 0xf68, 0xfdf);
		RegisterOpCode(0x36, OPCODE_ProfileStop, 0xdc, 0x20d, 0x59b, 0x875, 0x99f, 0xa51, 0xc6d, 0xce0, 0xf50, 0xf60, 0xfcd);
		RegisterOpCode(0x36, OPCODE_GetInteger, 0xe1, 0x1ec, 0x321, 0x3f2, 0x471, 0x4c9, 0x4df, 0x58b, 0x635, 0x749, 0x803, 0x837, 0x935, 0x95f, 0x9d2, 0xa0d, 0xa12, 0xa9a,
			0xe97, 0xe9d, 0xeb4, 0xf65);
		RegisterOpCode(0x36, OPCODE_ClassFunctionThreadCall, 0xe3, 0x114, 0x1a1, 0x1d6, 0x3b5, 0x451, 0x50a, 0x53e, 0x5fd, 0x6b4, 0x709, 0x793, 0xa55, 0xa81, 0xaad, 0xb69,
			0xbd0, 0xc46, 0xcbe, 0xd25, 0xd61, 0xd7f, 0xde8, 0xebf, 0xee8, 0xeed, 0xf6f);
		RegisterOpCode(0x36, OPCODE_VectorScale, 0xe4, 0x1f3, 0x2e7, 0x344, 0x3a2, 0x4a1, 0x4bd, 0x513, 0x542, 0x55d, 0x747, 0x790, 0x869, 0x926, 0x9bb, 0xa15, 0xa7b, 0xb52, 0xd37, 0xe56, 0xefe);
		RegisterOpCode(0x36, OPCODE_Modulus, 0xe9, 0x1a6, 0x1c9, 0x22b, 0x294, 0x300, 0x30f, 0x3be, 0x40c, 0x5e5, 0x5ea, 0x62f, 0x649, 0x66e, 0x712, 0x7ad, 0x7ef, 0x945, 0x973,
			0x9bd, 0xb5d, 0xbca, 0xc51, 0xc87, 0xd0c, 0xd82, 0xebe, 0xf37, 0xf75, 0xf86);
		RegisterOpCode(0x36, OPCODE_VectorConstant, 0xea, 0x105, 0x177, 0x415, 0x4c0, 0x8e9, 0x921, 0xa75, 0xae3, 0xb2d, 0xe9c, 0xef9);
		RegisterOpCode(0x36, OPCODE_SizeOf, 0xeb, 0x184, 0x1d9, 0x241, 0x27c, 0x2e1, 0x34b, 0x357, 0x55b, 0x727, 0x7a7, 0x7c8, 0x816, 0x89c, 0xa0c, 0xa67, 0xaee, 0xb22, 0xc62, 0xe0c);
		RegisterOpCode(0x36, OPCODE_Notify, 0xf0, 0x207, 0x2a7, 0x2eb, 0x3c4, 0x403, 0x625, 0x67e, 0x82a, 0x9dd, 0xc66, 0xcb2, 0xdc3, 0xdc5, 0xf2f, 0xf3d);
		RegisterOpCode(0x36, OPCODE_Vector, 0xf2, 0x112, 0x34e, 0x3fd, 0x6ed, 0x781, 0x7e9, 0x81d, 0x8a1, 0xa44, 0xb88, 0xd4a, 0xe7d, 0xf38, 0xf72);
		RegisterOpCode(0x36, OPCODE_Dec, 0xf5, 0x165, 0x1f6, 0x295, 0x31e, 0x3de, 0x41b, 0x4a7, 0x4d3, 0x645, 0x752, 0x779, 0x77a, 0x82c, 0x9df, 0xb04, 0xb5e, 0xb7a, 0xb85, 0xb95,
			0xbec, 0xcba, 0xccd, 0xdaa, 0xe55, 0xe99, 0xec0, 0xf93);
		RegisterOpCode(0x36, OPCODE_JumpOnLessThan, 0xfb, 0x130, 0x190, 0x48d, 0x572, 0x646, 0x663, 0x744, 0x861, 0x86f, 0x886, 0xb0f, 0xbbe, 0xbf2, 0xc25, 0xcf3, 0xd18, 0xedc, 0xfd5);
		RegisterOpCode(0x36, OPCODE_Bit_And, 0xfd, 0x4fd, 0x684, 0x6b7, 0x6bb, 0x6d4, 0xc12, 0xc9a, 0xd54, 0xe24, 0xfe7);
		RegisterOpCode(0x36, OPCODE_GetObjectType, 0x101, 0x194, 0x276, 0x2fe, 0x34a, 0x3b2, 0x40a, 0x47c, 0x58c, 0x644, 0x655, 0x721, 0x7f6, 0x828, 0x843, 0x934, 0x9b3,
			0x9b9, 0xaa2, 0xcd6, 0xcfd, 0xd33, 0xd7a, 0xda3, 0xe6a, 0xf89, 0xfff);
		RegisterOpCode(0x36, OPCODE_Multiply, 0x113, 0x206, 0x2ad, 0x3ce, 0x433, 0x484, 0x4d0, 0x529, 0x617, 0x673, 0x6c5, 0x76c, 0x7d0, 0x89b, 0x9f9, 0xa1a, 0xa36, 0xb37,
			0xba2, 0xc8e, 0xcc6, 0xcfb, 0xd00, 0xd88, 0xe27, 0xe4c, 0xf95, 0xffb);
		RegisterOpCode(0x36, OPCODE_EvalFieldVariableOnStack, 0x116, 0x118, 0x16f, 0x2dc, 0x3b3, 0x3fb, 0x4b4, 0x6df, 0x770, 0x7c3, 0x917, 0xa41, 0xca0, 0xee6);
		RegisterOpCode(0x36, OPCODE_GetTime, 0x117, 0x137, 0x19d, 0x253, 0x376, 0x45f, 0x475, 0x4a5, 0x4a6, 0x4c2, 0x4ef, 0x5a9, 0x753, 0x7c9, 0x9ba, 0xc53, 0xcd8, 0xd02, 0xda8);
		RegisterOpCode(0x36, OPCODE_SetLocalVariableCached, 0x11d, 0x1c0, 0x1e4, 0x1ee, 0x3e7, 0x4f0, 0x60f, 0x683, 0x687, 0x910, 0x936, 0x9a0, 0xd16, 0xd38, 0xd80, 0xdba);
		RegisterOpCode(0x36, OPCODE_AddToStruct, 0x11f, 0x1db, 0x5ac, 0x71a, 0xad5, 0xc5d, 0xc9f, 0xcbb, 0xd2b, 0xd30);
		RegisterOpCode(0x36, OPCODE_ClassFunctionThreadCallEndOn, 0x120, 0x17f, 0x210, 0x401, 0x4b8, 0x530, 0x5ba, 0x66a, 0x690, 0x6b8, 0x82f, 0x8b9, 0x8be, 0x8d6, 0x8ee,
			0x984, 0x9b2, 0xa25, 0xcab, 0xd21, 0xecc, 0xeea);
		RegisterOpCode(0x36, OPCODE_LessThanOrEqualTo, 0x122, 0x182, 0x2b1, 0x2e6, 0x333, 0x3ed, 0x446, 0x560, 0x5b4, 0x5c4, 0x5d7, 0x68d, 0x6fa, 0x985, 0x9a4, 0xc1e, 0xc5f,
			0xc88, 0xd76, 0xe31, 0xe8f);
		RegisterOpCode(0x36, OPCODE_FirstArrayKeyCached, 0x123, 0x1d4, 0x1dc, 0x7f9, 0x866, 0xab8, 0xb5f, 0xbea, 0xc40, 0xd29, 0xdfa, 0xe7b, 0xed6);
		RegisterOpCode(0x36, OPCODE_Unknown10e, 0x10e, 0x1d7, 0x3e9, 0x418, 0x557, 0x798, 0x7aa, 0x874, 0x977, 0xb29, 0xe0a, 0xe18);
		RegisterOpCode(0x36, OPCODE_Unknown126, 0x126, 0x142, 0x169, 0x21c, 0x2b9, 0x417, 0x4ca, 0x52f, 0x60b, 0x6ef, 0x7be, 0x862, 0x893, 0x8da, 0x9dc, 0xa4e, 0xa7f,
			0xaa3, 0xd68, 0xdd6, 0xe81, 0xeac, 0xf94);
		RegisterOpCode(0x36, OPCODE_GetGlobal, 0x12c, 0x4f9, 0x5ae, 0x6cd, 0x755, 0x7e4, 0x872, 0x980, 0x994, 0xaaa, 0xabc, 0xaef, 0xaf0, 0xb74, 0xbbc, 0xbf6, 0xc33,
			0xdec, 0xe72, 0xf13, 0xfb9);
		RegisterOpCode(0x36, OPCODE_GetZero, 0x136, 0x2c5, 0x56d, 0x5e1, 0x8e5, 0x9aa, 0xa8b, 0xb16, 0xc28, 0xd87, 0xfa3);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableRefCached, 0x138, 0x236, 0x33d, 0x4a3, 0x53c, 0x589, 0x5a5, 0x5a8, 0x686, 0x6f5, 0x6fd, 0x957, 0xa21, 0xa3b, 0xa86, 0xadb,
			0xb0e, 0xb49, 0xc65, 0xcf4, 0xd50, 0xe32, 0xe5b, 0xec7, 0xfde);
		RegisterOpCode(0x36, OPCODE_ClearFieldVariable, 0x14c, 0x27d, 0x4fb, 0x50d, 0x586, 0x5d4, 0x67f, 0x766, 0x852, 0x8bf, 0x97b, 0xb8f, 0xb97, 0xce6, 0xd3c, 0xd7d,
			0xd96, 0xe06, 0xe2f, 0xf6b, 0xff3);
		RegisterOpCode(0x36, OPCODE_EvalGlobalObjectFieldVariable, 0x155, 0x1ba, 0x25c, 0x25d, 0x2f2, 0x436, 0x47d, 0x48f, 0x4c5, 0x50b, 0x5fb, 0x616, 0x729, 0x7f7,
			0x891, 0x8b1, 0x90d, 0x98b, 0x9a5, 0xb45, 0xbb3, 0xd0a, 0xd2e, 0xd60, 0xf47);
		RegisterOpCode(0x36, OPCODE_EvalFieldObjectFromRef, 0x168, 0x171, 0x1b4, 0x2bf, 0x4d7, 0x509, 0x675, 0x6ab, 0x810, 0x87c, 0x8c6, 0x9e9, 0xa58, 0xb9b, 0xba8,
			0xc22, 0xe3b);
		RegisterOpCode(0x36, OPCODE_GetSelf, 0x16e, 0x1be, 0x205, 0x209, 0x252, 0x25a, 0x260, 0x5de, 0x653, 0x72a, 0x763, 0x767, 0x83a, 0x844, 0x846, 0xa54, 0xb4f,
			0xcf9, 0xda7, 0xe76, 0xf56, 0xf88);
		RegisterOpCode(0x36, OPCODE_GetResolveFunction, 0x181, 0x222, 0x230, 0x232, 0x2aa, 0x2e0, 0x34d, 0x402, 0x434, 0x4db, 0x4e6, 0x558, 0x670, 0x6f7, 0x745, 0x74c,
			0x7d3, 0x86c, 0x8c1, 0x9ee, 0xa62, 0xa8e, 0xc01, 0xc4a, 0xcb6, 0xcc3, 0xf42, 0xfcc);
		RegisterOpCode(0x36, OPCODE_GetGlobalObject, 0x187, 0x1bb, 0x250, 0x2db, 0x30a, 0x338, 0x39d, 0x470, 0x4bb, 0x4ea, 0x51c, 0x54c, 0x5da, 0x60d, 0x6a5, 0x6a9,
			0x8f6, 0x8ff, 0x92e, 0x947, 0xb1b, 0xc4c, 0xd24, 0xe29, 0xeef, 0xefb, 0xf26);
		RegisterOpCode(0x36, OPCODE_GetByte, 0x18a, 0x1ed, 0x476, 0x544, 0x5a6, 0x680, 0x692, 0x9c2, 0xa73, 0xc95, 0xd93, 0xed8, 0xf9b);
		RegisterOpCode(0x36, OPCODE_CastFieldObject, 0x18e, 0x193, 0x1f1, 0x39e, 0x3dd, 0x42f, 0x45c, 0x4aa, 0x5b6, 0x5e3, 0x607, 0x791, 0x7ff, 0x82b, 0x8b7, 0x97c,
			0xb62, 0xc69, 0xc7b, 0xc98, 0xc99, 0xccb, 0xd40, 0xd42);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableDefined, 0x192, 0x1e3, 0x24f, 0x270, 0x2f7, 0x48a, 0x63d, 0x789, 0x7c1, 0x932, 0xab3, 0xb17, 0xbd8, 0xc68, 0xcef,
			0xd0b, 0xd56, 0xd98);
		RegisterOpCode(0x36, OPCODE_ScriptThreadCallPointer, 0x1c5, 0x1f2, 0x21a, 0x325, 0x33b, 0x397, 0x3eb, 0x499, 0x52d, 0x71d, 0x74b, 0x7a1, 0x84c, 0x9ac, 0x9b8,
			0xa4d, 0xac1, 0xb05, 0xc6e, 0xd04, 0xd5f, 0xdd7, 0xe89, 0xeba, 0xfc3, 0xfe1);
		RegisterOpCode(0x36, OPCODE_LessThan, 0x1c6, 0x399, 0x54f, 0x5bd, 0x62a, 0x787, 0x92d, 0x93d, 0x99d, 0xab9, 0xbba, 0xc36, 0xe9e, 0xfac);
		RegisterOpCode(0x36, OPCODE_ScriptMethodCall, 0x1e6, 0x36f, 0x425, 0x6c4, 0x705, 0x7f2, 0x8b2, 0x8b6, 0x983, 0xa4c, 0xb78, 0xcad, 0xd52);
		RegisterOpCode(0x36, OPCODE_DecTop, 0x1f4, 0x53f, 0x561, 0x597, 0x732, 0x851, 0x8cf, 0x965, 0x99c, 0xdd3, 0xee2, 0xef6, 0xf3f, 0xf91);
		RegisterOpCode(0x36, OPCODE_GetVector, 0x22f, 0x3fc, 0x628, 0x702, 0x981, 0x9cd, 0xa00, 0xb11, 0xf57, 0xf90);
		RegisterOpCode(0x36, OPCODE_ScriptMethodThreadCall, 0x248, 0x53d, 0x590, 0x78e, 0x83d, 0xa34, 0xbe4, 0xc93, 0xcc5, 0xd97, 0xe75);
		RegisterOpCode(0x36, OPCODE_SetNextArrayKeyCached, 0x26b, 0x320, 0x331, 0x383, 0x491, 0x4c1, 0x4fc, 0x564, 0x610, 0x71e, 0x72d, 0x80f, 0x8ea, 0x929, 0x971,
			0x990, 0x9cf, 0xaa1, 0xae0, 0xbb4, 0xbef, 0xc8b, 0xcfc, 0xe3d, 0xe53, 0xee3, 0xf54, 0xf66, 0xfc8, 0xff5);
		RegisterOpCode(0x36, OPCODE_JumpPush, 0x2d2, 0x3ab, 0x61e, 0x70e, 0x90f, 0xc31, 0xc32, 0xc94, 0xf8c, 0xff9);
		RegisterOpCode(0x36, OPCODE_GetUnsignedShort, 0x307, 0x312, 0x354, 0x428, 0x4cc, 0x5c2, 0x64b, 0x735, 0x7c6, 0x96b, 0xa09, 0xa53, 0xacc, 0xb86, 0xc0d, 0xc73, 0xd13, 0xd65, 0xf63, 0xff2);
		RegisterOpCode(0x36, OPCODE_EvalLocalVariableCached, 0x332, 0x3ae, 0x528, 0x5ca, 0x5d1, 0x689, 0x6b5, 0x741, 0x829, 0x8cc, 0x8e2, 0x919, 0xa31, 0xac2, 0xc3c, 0xc60, 0xc8d, 0xd32, 0xf8e);
		RegisterOpCode(0x36, OPCODE_EvalArrayRef, 0x3c1, 0x3da, 0x4a8, 0x4ce, 0x527, 0x5c9, 0x6a8, 0x782, 0x884, 0x887, 0x9a2, 0xa9d, 0xaae, 0xae6, 0xb06, 0xb35, 0xc85, 0xce4, 0xdea, 0xf05, 0xfe6);
		RegisterOpCode(0x36, OPCODE_EvalFieldVariable, 0x400, 0x4a9, 0x548, 0x551, 0x68b, 0x746, 0x7b3, 0x7c4, 0xd4f, 0xe1a, 0xed1);
		RegisterOpCode(0x36, OPCODE_GetFunction, 0x432, 0x5d8, 0x6a1, 0x718, 0xb64, 0xb9c, 0xc91, 0xcb1, 0xedb, 0xf16);

		// T8-Compiler opcodes
		RegisterOpCode(0x36, OPCODE_T8C_GetLazyFunction, 0x16);
	});
}