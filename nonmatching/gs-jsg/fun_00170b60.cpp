#include "sly2.h"

extern "C" void* PcmdAllocScript(void* pscript, int opcode, int a2);

void func_00170B60(void* pscript, const void* pu64Payload)
{
    void* pcmd = PcmdAllocScript(pscript, 1, -1);
    unsigned char* p = (unsigned char*)pcmd;
    // unaligned load of 8 bytes from pu64Payload via ldl/ldr pair, store via sdl/sdr to pcmd+0xF / pcmd+0x8
    // Need to mimic: load word at offset 7, word at offset 0, store at 0xF and 0x8? Actually ldl $v1, 0x7($s0) loads... 
}