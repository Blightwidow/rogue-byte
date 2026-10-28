#include "m2c_macros.h"

M2C_UNK CQueueOutputIop_Deinterleave(void *, s32, s32); /* extern */
s32 CQueueOutputIop_SendToIop(void *, s32, void *, s32); /* extern */

s32 CQueueOutputIop_CbWrite(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s8 temp_v1_2;
    void *temp_a2;

    var_s1 = arg1;
    var_s2 = 0;
    if ((var_s1 <= 0) || (M2C_FIELD(arg0, s32 *, 0x24) < var_s1)) {
        var_s1 = M2C_FIELD(arg0, s32 *, 0x24);
    }
    if (M2C_FIELD(arg0, s32 *, 4) == 0x10) {
        var_s1_2 = var_s1 & -(M2C_FIELD(arg0, s32 *, 0xC) << 0xA);
        CQueueOutputIop_Deinterleave(arg0, var_s1_2, arg2);
    } else {
        var_s1_2 = var_s1 & ~0x3FF;
    }
    if (var_s1_2 != 0) {
loop_8:
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x18) - M2C_FIELD(arg0, s32 *, 0x1C);
        var_a3 = (var_s1_2 >= temp_v1) ? temp_v1 : var_s1_2;
        temp_a2 = arg2 + var_s2;
        if (M2C_FIELD(arg0, s32 *, 4) == 0x10) {
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x2C);
            var_a3 = 0x400;
            temp_lo = (s32) ((s32) ((temp_a0 > -1) ? temp_a0 : (temp_a0 + 0x3FF)) >> 0xA) / (s32) M2C_FIELD(arg0, s32 *, 0xC);
            temp_v1_2 = temp_lo - (((s32) ((temp_lo > -1) ? temp_lo : (temp_lo + 3)) >> 2) * 4);
            if (temp_v1_2 == 0) {
                M2C_FIELD(temp_a2, s8 *, 1) = 6;
                M2C_FIELD(temp_a2, s8 *, 0x11) = 2;
            } else if (temp_v1_2 == 3) {
                M2C_FIELD(temp_a2, s8 *, 0x3F1) = temp_v1_2;
            }
        }
        temp_v0 = CQueueOutputIop_SendToIop(arg0, var_a3, temp_a2, var_a3);
        var_s1_2 -= temp_v0;
        if (temp_v0 != 0) {
            var_s2 += temp_v0;
            temp_v0_2 = M2C_FIELD(arg0, s32 *, 0x1C) + temp_v0;
            M2C_FIELD(arg0, s32 *, 0x1C) = temp_v0_2;
            M2C_FIELD(arg0, s32 *, 0x28) = (s32) (M2C_FIELD(arg0, s32 *, 0x28) + temp_v0);
            M2C_FIELD(arg0, s32 *, 0x24) = (s32) (M2C_FIELD(arg0, s32 *, 0x24) - temp_v0);
            M2C_FIELD(arg0, s32 *, 0x2C) = (s32) (M2C_FIELD(arg0, s32 *, 0x2C) + temp_v0);
            M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (temp_v0_2 % (s32) M2C_FIELD(arg0, s32 *, 0x18));
            if (arg1 > 0) {
                if (var_s1_2 != 0) {
                    goto loop_8;
                }
            }
        }
    }
    return var_s2;
}
