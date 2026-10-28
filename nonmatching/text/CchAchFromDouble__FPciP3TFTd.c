#include "m2c_macros.h"

u8 ChDigitFromG__Fdii();               /* extern */
s32 ExpFirstFromG__Fd();                    /* extern */
s32 __adddf3();                             /* extern */
s32 __fixdfsi();                                 /* extern */
s64 __floatsidf();                               /* extern */
s32 __muldf3();                             /* extern */
s32 pow();                                  /* extern */
M2C_UNK strcpy();                     /* extern */
s32 strlen();                                    /* extern */
extern M2C_UNK D_002C40C8;

s32 CchAchFromDouble__FPciP3TFTd(u32 arg0, void *arg2, s32 arg3) {
    M2C_UNK *var_a1;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_a1_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s2;
    s32 var_s3;
    s32 var_s7;
    s64 temp_v1;
    s8 var_v0;
    u8 *var_s1;
    u8 temp_a0;
    u8 temp_v0_3;
    void *temp_v0_2;
    void *var_a1_2;
    void *var_v1;

    temp_v1 = 0xFFE0 << 0x2F;
    if ((arg3 & temp_v1) == temp_v1) {
        if (arg3 & (-1U >> 0xC)) {
            var_a1 = "(nan)";
        } else {
            var_a1 = "(inf)";
        }
        strcpy(arg0, var_a1);
        return strlen(arg0);
    }
    var_s1 = arg0;
    temp_a0 = M2C_FIELD(arg2, u8 *, 0x2C);
    temp_s3 = ExpFirstFromG__Fd(arg3, arg3);
    var_s7 = temp_a0 == 0x65;
    if (temp_a0 == 0x67) {
        if ((temp_s3 < -4) || (temp_s3 >= M2C_FIELD(arg2, s32 *, 0x1C))) {
            var_s7 = 1;
            M2C_FIELD(arg2, s32 *, 0x1C) = (s32) (M2C_FIELD(arg2, s32 *, 0x1C) - 1);
        }
    }
    temp_v0 = __adddf3(arg3, __muldf3(pow(0x8048 << 0x2F, __floatsidf(((var_s7 != 0) ? temp_s3 : 0) - M2C_FIELD(arg2, s32 *, 0x1C))), 0xFF80 << 0x2E));
    temp_s0 = ExpFirstFromG__Fd(temp_v0);
    var_s3 = (temp_s3 < ExpFirstFromG__Fd(temp_v0)) ? temp_s0 : temp_s3;
    if (var_s7 != 0) {
        var_s0 = 1;
        var_s2 = var_s3;
    } else {
        var_s2 = var_s3;
        if (var_s3 >= 0) {
            var_s0 = var_s3 + 1;
        } else {
            var_s0 = 1;
            var_s2 = 0;
        }
    }
    var_s0_2 = var_s0 - 1;
    if (var_s0 > 0) {
        do {
            temp_a2 = var_s2;
            var_s2 -= 1;
            *var_s1 = ChDigitFromG__Fdii(temp_v0, var_s3, temp_a2);
            var_s1 += 1;
            var_s0_2 -= 1;
        } while (var_s0_2 > 0);
    }
    if (M2C_FIELD(arg2, s32 *, 0x14) == 0) {
        *var_s1 = 0x2E;
        var_s1 += 1;
        temp_s0_2 = M2C_FIELD(arg2, s32 *, 0x1C);
        var_s0_3 = temp_s0_2 - 1;
        if (temp_s0_2 > 0) {
            do {
                temp_a2_2 = var_s2;
                var_s2 -= 1;
                *var_s1 = ChDigitFromG__Fdii(temp_v0, var_s3, temp_a2_2);
                var_s1 += 1;
                var_s0_3 -= 1;
            } while (var_s0_3 > 0);
        }
        if (M2C_FIELD(arg2, u8 *, 0x2C) == 0x67) {
            temp_v0_2 = var_s1 - 0x8000;
            if (arg0 < var_s1) {
                var_a1_2 = temp_v0_2;
                if (M2C_FIELD(temp_v0_2, u8 *, 0x7FFF) == 0x30) {
                    var_v1 = var_a1_2;
loop_25:
                    var_s1 -= 1;
                    var_v1 -= 1;
                    if (arg0 < var_s1) {
                        var_a1_2 = var_v1;
                        if (M2C_FIELD(var_v1, u8 *, 0x7FFF) != 0x30) {
                            goto block_27;
                        }
                        goto loop_25;
                    }
                } else {
block_27:
                    if (arg0 < var_s1) {
                        var_s1 = ((M2C_FIELD(var_a1_2, u8 *, 0x7FFF) ^ 0x2E) == 0) ? (var_s1 - 1) : var_s1;
                    }
                }
            }
        }
    }
    if (var_s7 != 0) {
        M2C_FIELD(var_s1, s8 *, 0) = 0x65;
        if (var_s3 < 0) {
            var_v0 = 0x2D;
            var_s3 = -var_s3;
        } else {
            var_v0 = 0x2B;
        }
        M2C_FIELD(var_s1, s8 *, 1) = var_v0;
        var_s1 = var_s1 + 1 + 1;
        temp_a2_3 = __fixdfsi(pow(0x8048 << 0x2F, 0x8000 << 0x2F));
        var_a1_3 = 2;
        do {
            if (temp_a2_3 == 0) {
                M2C_BREAK(0);
            }
            var_a1_3 -= 1;
            temp_v0_3 = *((var_s3 / temp_a2_3) + &D_002C40C8);
            var_s3 = (var_s3 % temp_a2_3) * 0xA;
            *var_s1 = temp_v0_3;
            if (temp_a2_3 == 0) {
                M2C_BREAK(0);
            }
            var_s1 += 1;
        } while (var_a1_3 >= 0);
    }
    return var_s1 - arg0;
}
