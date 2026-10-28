#include "m2c_macros.h"

void *PcmdAllocScript(M2C_UNK, s32);                /* extern */

void AddScriptRun(s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PcmdAllocScript(6, arg1);
    M2C_FIELD(temp_v0, s32 *, 8) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
}
