#include "m2c_macros.h"

M2C_UNK Carry_Init();                         /* extern */
M2C_UNK func_0020B840();        /* extern */

void InitAttach(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0) = arg1;
    M2C_FIELD(arg0, s32 *, 0x4FC) = -1;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    M2C_FIELD(arg0, s32 *, 0xC) = -1;
    func_0020B840(arg0 + 0x180, 0x6F);
    func_0020B840(arg0 + 0x240, arg1, 0x6F);
    Carry_Init(arg0 + 0x440);
}
