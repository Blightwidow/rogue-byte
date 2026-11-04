#include "m2c_macros.h"

M2C_UNK FlushCache(M2C_UNK, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_00232FE8(s32, s32, s32, s32);          /* extern */
s32 sceSifDmaStat(s32);                             /* extern */
s32 sceSifSetDma(void *, M2C_UNK);                  /* extern */

s32 CQueueOutputIop_SendToIop(void *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a1;

    var_a1 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) != 0x10) {
        var_a1 = M2C_FIELD(arg0, s32 *, 0x1C);
    }
    FlushCache(0, var_a1, arg2, M2C_FIELD(arg0, s32 *, 0x14) + var_a1, arg1, 0);
    temp_s0 = sceSifSetDma(sp, 1);
    do {

    } while (sceSifDmaStat(temp_s0) >= 0);
    if (M2C_FIELD(arg0, s32 *, 4) == 0x10) {
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x2C);
        temp_a2 = M2C_FIELD(arg0, s32 *, 0xC);
        temp_v0 = (s32) ((temp_a1 > -1) ? temp_a1 : (temp_a1 + 0x3FF)) >> 0xA;
        temp_lo = temp_v0 / temp_a2;
        temp_a3 = (temp_v0 % temp_a2) << 0xC;
        func_00232FE8(arg1, ((temp_lo - (((s32) ((temp_lo > -1) ? temp_lo : (temp_lo + 3)) >> 2) * 4)) << 0xA) + temp_a3, temp_a2, temp_a3);
    }
    return arg1;
}
