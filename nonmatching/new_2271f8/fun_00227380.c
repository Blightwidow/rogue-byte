#include "m2c_macros.h"

M2C_UNK CBinaryInputStream_ReadBspc(s32, s32, void *); /* extern */
M2C_UNK CBinaryInputStream_ReadGeom(s32, s32);      /* extern */
M2C_UNK LoadOptionsFromBrx__FPvP18CBinaryInputStream(void *, s32); /* extern */
M2C_UNK LoadXfmBaseFromBrx();                       /* extern */
s32 U32Read__18CBinaryInputStream(s32);             /* extern */

void func_00227380(void *arg0, s32 arg1) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xF8;
    LoadXfmBaseFromBrx();
    M2C_FIELD(arg0, s32 *, 0xE0) = U32Read__18CBinaryInputStream(arg1);
    CBinaryInputStream_ReadGeom(arg1, temp_s2);
    CBinaryInputStream_ReadBspc(arg1, temp_s2, arg0 + 0xE8);
    LoadOptionsFromBrx__FPvP18CBinaryInputStream(arg0, arg1);
}
