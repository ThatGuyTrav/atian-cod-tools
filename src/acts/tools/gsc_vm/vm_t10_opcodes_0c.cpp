#include <includes.hpp>
#include <tools/gsc_vm.hpp>
#include <tools/gsc.hpp>
#include <tools/gsc_opcodes.hpp>

namespace {
	using namespace tool::gsc::opcode;
	void OpCode() {
		VmInfo* t10c = RegisterVM(VMI_T10_0C, "Call of Duty: Black Ops 6 (0C)", "t10", "bo6_c", VmFlags::VMF_CRC_DUMP | VmFlags::VMF_FOREACH_IW | VmFlags::VMF_EXPORT_CRC32 | VmFlags::VMF_HASH64 | VmFlags::VMF_HASH_CER | VmFlags::VMF_HASH_PATH_IW | VmFlags::VMF_CALL_NO_PARAMS | VmFlags::VMF_IW_LIKE); // VmFlags::VMF_IW_CALLS | VmFlags::VMF_NO_PARAM_FLAGS
		t10c->RegisterVmName("cerc", "t10_c", "blackops6_c");
		t10c->AddPlatform(PLATFORM_PC);
		t10c->RegisterVMGlobalVariable("level", OPCODE_IW_GetLevel);
		t10c->RegisterVMGlobalVariable("game", OPCODE_IW_GetGame);
		t10c->RegisterVMGlobalVariable("anim", OPCODE_IW_GetAnim);
		t10c->RegisterVMOperatorFunction("waittill", "<caller> waittill(event, var*)", OPCODE_IW_SingleWaitTill, VPFD_SELF_PARAM | VPFD_UNPACK, 1);
		t10c->RegisterVMOperatorFunction("isdefined", "isdefined(object) -> bool", OPCODE_IsDefined, VPFD_RETURN_VALUE, 1, 1);
		t10c->RegisterVMOperatorFunction("notify", "<caller> notify(event, param*)", OPCODE_IW_Notify, VPFD_SELF_PARAM | VPFD_USE_PRE_SCRIPT_CALL, 1);
		t10c->RegisterVMOperatorFunction("endon", "<caller> endon(event+)", OPCODE_EndOn, VPFD_SELF_PARAM | VPFD_USE_COUNT, 1);
		t10c->RegisterVMOperatorFunction("wait", "wait(time)", OPCODE_Wait, VPFD_NONE, 1, 1);
		t10c->RegisterVMOperatorFunction("waitframe", "waitframe()", OPCODE_IW_WaitFrame, VPFD_NONE, 0, 0);
		t10c->RegisterVMOperatorFunction("getthread", "getthread() -> thread", OPCODE_IW_GetThread, VPFD_RETURN_VALUE, 0, 0);
		t10c->RegisterVMOperatorFunction("istrue", "istrue(object) -> bool", OPCODE_IW_IsTrue, VPFD_RETURN_VALUE, 1, 1);
		t10c->RegisterVMOperatorFunction("flat_args", "flat_args(array, count) -> bool", OPCODE_T10_FlatArgs, VPFD_RETURN_VALUE, 2, 2);
		t10c->RegisterVMOperatorFunction("waittillframeend", "waittillframeend()", OPCODE_WaitTillFrameEnd, VPFD_NONE, 0, 0);
		t10c->RegisterVMHashOPCode('#', OPCODE_GetHash, 8, [](const char* str) { return hash::Hash64A(str); });
		t10c->RegisterVMHashOPCode('@', OPCODE_IW_GetDVarHash, 8, [](const char* str) { return hash::HashIWDVar(str); });
		t10c->RegisterVMHashOPCode('%', OPCODE_IW_GetResourceHash, 8, [](const char* str) { return hash::HashIWAsset(str); });
		t10c->RegisterVMHashOPCode('r', OPCODE_IW_GetLocalizedHash, 8, [](const char* str) { return hash::HashIWAsset(str); });
		t10c->RegisterVMHashOPCode('t', OPCODE_IW_GetTagHash, 4, [](const char* str) { return hash::HashX32(str); });
		t10c->RegisterVMHashOPCode('s', OPCODE_T10_GetScrHash, 8, [](const char* str) { return hash::HashT10Scr(str); });
		t10c->RegisterDevCall("assert", "assertmsg", "function_79901b4637c83c86", "assertex", "println", "print");
		t10c->RegisterDatatype("builtinfunction", "builtinmethod", "function", "string", "istring", "struct", "int", "float", "vector");
		t10c->RegisterOpCode(PLATFORM_PC, OPCODE_CheckClearParams, 0x24);
		t10c->RegisterOpCode(PLATFORM_PC, OPCODE_SafeCreateLocalVariables, 0x20);
		t10c->RegisterOpCode(PLATFORM_PC, OPCODE_IW_RegisterMultipleVariables, 0x93);
	}
}
REGISTER_GSC_VM_OPCODES(bo6, OpCode);