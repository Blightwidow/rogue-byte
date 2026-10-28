#include "m2c_macros.h"

void *PcmdAllocScript(M2C_UNK, s32);                /* extern */

void AddScriptGoto(s32 arg1, s32 arg2, f32 fparg0) {
    void *temp_v0;

    temp_v0 = PcmdAllocScript(7, arg1);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg2;
    M2C_FIELD(temp_v0, f32 *, 0x14) = fparg0;
}
