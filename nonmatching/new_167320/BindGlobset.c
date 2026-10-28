#include "m2c_macros.h"

M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
void *PloFindSwObject_thunk(M2C_UNK *, M2C_UNK, s32, s32); /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(M2C_UNK *, M2C_UNK *, void *); /* extern */
M2C_UNK func_0022B7A0(void *, void *);              /* extern */
M2C_UNK memset(void *, M2C_UNK, M2C_UNK);           /* extern */
extern M2C_UNK B_003DD490;
extern s32 B_003E11EC;

void BindGlobset(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp10;
    M2C_UNK sp20;
    M2C_UNK sp30;
    M2C_UNK sp40;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 var_a0;
    s32 var_a2;
    s32 var_s4;
    s32 var_s6;
    void *temp_a0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s3;
    void *temp_s7;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *var_s0;

    if (M2C_FIELD(arg0, s32 *, 0x4C) != -1) {
        M2C_FIELD(arg0, s32 *, 0x4C) = (s32) B_003E11EC;
    }
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x38) > 0) {
        do {
            var_s4 = 0;
            temp_s7 = M2C_FIELD(arg0, s32 *, 0x3C) + (var_a0 * 0x14);
            temp_s3 = M2C_FIELD(arg0, s32 *, 0x40) + (var_a0 * 0x28);
            if (M2C_FIELD(temp_s7, s8 *, 1) > 0) {
                var_s6 = 0;
                do {
                    temp_s1 = M2C_FIELD(temp_s3, s32 *, 0x18) + var_s6;
                    temp_v0 = PloFindSwObject_thunk(&B_003DD490, 4, M2C_FIELD(temp_s1, s32 *, 0), M2C_FIELD(arg0, s32 *, 0));
                    M2C_FIELD(temp_s1, void **, 4) = temp_v0;
                    if (temp_v0 != NULL) {
                        temp_v1 = M2C_FIELD(temp_v0, void **, 0xC);
                        M2C_FIELD(temp_s1, s32 *, 0xC) = M2C_FIELD(temp_v1, s32 (**)(void *, s32, void *), 0x19C)(temp_v0 + M2C_FIELD(temp_v1, s16 *, 0x198), M2C_FIELD(temp_s1, s32 *, 8), temp_v0);
                    }
                    temp_a1 = M2C_FIELD(temp_s1, s32 *, 0xC);
                    if (temp_a1 == 0) {
                        temp_a0 = M2C_FIELD(temp_s3, void **, 4);
                        temp_s0 = temp_s1 + 0x10;
                        if (temp_a0 != NULL) {
                            M2C_FIELD(temp_s1, s128 *, 0x10) = (s128) M2C_FIELD(temp_a0, s128 *, 0x40);
                            M2C_FIELD(temp_s1, s128 *, 0x20) = (s128) M2C_FIELD(temp_a0, s128 *, 0x50);
                            M2C_FIELD(temp_s1, s128 *, 0x30) = (s128) M2C_FIELD(temp_a0, s128 *, 0x60);
                            M2C_FIELD(temp_s1, s128 *, 0x40) = (s128) M2C_FIELD(temp_a0, s128 *, 0x70);
                        } else {
                            memset(temp_s0, 0, 0x40);
                            M2C_FIELD(temp_s0, f32 *, 0x14) = 1.0f;
                            M2C_FIELD(temp_s0, f32 *, 0x3C) = 1.0f;
                            M2C_FIELD(temp_s0, f32 *, 0x28) = 1.0f;
                            M2C_FIELD(temp_s1, s128 *, 0x10) = 1.0f;
                        }
                    } else {
                        temp_a1_2 = temp_a1 + 0x40;
                        if (M2C_FIELD(temp_s3, void **, 4) != NULL) {
                            InvertMatrix4Affine(&sp40, temp_a1_2);
                            __ml__FRC7MATRIX4T0(sp, &sp40, M2C_FIELD(temp_s3, void **, 4) + 0x40);
                        } else {
                            InvertMatrix4Affine(sp, temp_a1_2);
                        }
                        M2C_FIELD(temp_s1, s128 *, 0x10) = sp0;
                        M2C_FIELD(temp_s1, s128 *, 0x20) = sp10;
                        M2C_FIELD(temp_s1, s128 *, 0x30) = sp20;
                        M2C_FIELD(temp_s1, s128 *, 0x40) = sp30;
                    }
                    var_s4 += 1;
                    var_s6 += 0x50;
                } while (var_s4 < M2C_FIELD(temp_s7, s8 *, 1));
            }
            var_a0 += 1;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 0x38));
    }
    var_s0 = M2C_FIELD(arg0, void **, 0x58);
    if (var_s0 != NULL) {
        var_a2 = M2C_FIELD(var_s0, s32 *, 8);
loop_22:
        temp_v0_2 = PloFindSwObject_thunk(&B_003DD490, 4, var_a2, M2C_FIELD(arg0, s32 *, 0));
        if (temp_v0_2 != NULL) {
            func_0022B7A0(temp_v0_2, var_s0);
        }
        var_s0 = M2C_FIELD(var_s0, void **, 0x9C);
        if (var_s0 != NULL) {
            var_a2 = M2C_FIELD(var_s0, s32 *, 8);
            goto loop_22;
        }
    }
}
