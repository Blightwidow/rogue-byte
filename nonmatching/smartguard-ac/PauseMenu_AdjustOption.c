#include "m2c_macros.h"

f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK SeekBlotLabel(s32, M2C_UNK, f32);           /* extern */
M2C_UNK SetSndbankVolumeFactor(M2C_UNK *, M2C_UNK, M2C_UNK, f32); /* extern */
s32 UpdateJoyNavX(s32, s32);                        /* extern */
s32 UpdateJoyNavY(s32);                             /* extern */
s32 func_0023E1C8(f32 *, f32);                      /* extern */
extern M2C_UNK B_002DEB80;
extern M2C_UNK B_003DD040;
extern f32 B_FLT_002F6468;
extern f32 B_FLT_002F646C;
extern f32 D_FLT_002C01C8;
extern f32 D_FLT_002C01CC;
extern M2C_UNK g_2bbb60;
extern f32 g_2ddf10;

void PauseMenu_AdjustOption(void *arg0, void *arg1, s32 *arg2) {
    M2C_UNK var_a1;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 var_f20;
    f32 var_f20_2;
    f32 var_f2;
    s32 temp_a0;
    s32 temp_a2;
    s64 temp_s0;
    s64 temp_s1;
    s64 temp_v1;

    temp_a2 = *arg2;
    switch (temp_a2) {                              /* irregular */
    case 0x67:
        temp_f2 = (f32) UpdateJoyNavX(M2C_FIELD(arg0, s32 *, 0x10), temp_a2);
        if (temp_f2 != 0.0f) {
            var_f20 = GLimitLm__FP2LMf(&g_2bbb60, M2C_FIELD(&B_003DD040, f32 *, 0x150) + (temp_f2 * g_2ddf10 * 1.5f));
            var_a1 = 1;
block_10:
            SetSndbankVolumeFactor(&B_003DD040, var_a1, 1, var_f20);
            SeekBlotLabel(M2C_FIELD(arg1, s32 *, 8), 0x315, var_f20);
        }
        break;
    case 0x68:
        temp_f2_2 = (f32) UpdateJoyNavX(M2C_FIELD(arg0, s32 *, 0x10), temp_a2);
        if (temp_f2_2 != 0.0f) {
            var_f20 = GLimitLm__FP2LMf(&g_2bbb60, M2C_FIELD(&B_003DD040, f32 *, 0x14C) + (temp_f2_2 * g_2ddf10 * 1.5f));
            SetSndbankVolumeFactor(&B_003DD040, 0, 1, var_f20);
            var_a1 = 3;
            goto block_10;
        }
        break;
    case 0x3F:
        temp_f20 = (f32) UpdateJoyNavX(M2C_FIELD(arg0, s32 *, 0x10), temp_a2);
        temp_f4 = (f32) UpdateJoyNavY(M2C_FIELD(arg0, s32 *, 0x10));
        if (temp_f20 == 0.0f) {
            if (temp_f4 != 0.0f) {
                goto block_14;
            }
        } else {
block_14:
            var_f2 = 424.0f;
            temp_f0 = B_FLT_002F6468 + (temp_f20 * D_FLT_002C01C8);
            if (!(temp_f0 < 424.0f)) {
                var_f2 = temp_f0;
                if (temp_f0 > 848.0f) {
                    var_f2 = 848.0f;
                }
            }
            B_FLT_002F6468 = var_f2;
            temp_f12 = B_FLT_002F646C + (temp_f4 * D_FLT_002C01CC);
            if (temp_f12 < 10.0f) {
                var_f20_2 = 10.0f;
            } else {
                var_f20_2 = temp_f12;
                if (temp_f12 > 90.0f) {
                    var_f20_2 = 90.0f;
                }
            }
            B_FLT_002F646C = var_f20_2;
            temp_a0 = func_0023E1C8(&B_FLT_002F6468, B_FLT_002F6468) & 0xFFF;
            temp_s1 = (M2C_FIELD(&B_002DEB80, s64 *, 0x40) & ~0xFFF) | temp_a0;
            temp_s0 = (M2C_FIELD(&B_002DEB80, s64 *, 0x18) & ~0xFFF) | temp_a0;
            M2C_FIELD(&B_002DEB80, s64 *, 0x40) = temp_s1;
            M2C_FIELD(&B_002DEB80, s64 *, 0x18) = temp_s0;
            temp_v1 = func_0023E1C8((f32 *) temp_a0, var_f20_2) & 0x7FE;
            M2C_FIELD(&B_002DEB80, s64 *, 0x40) = (s64) ((temp_s1 & 0xFF800FFF) | (temp_v1 << 0xC));
            M2C_FIELD(&B_002DEB80, s64 *, 0x18) = (s64) ((temp_s0 & 0xFF800FFF) | (temp_v1 << 0xC));
        }
        break;
    }
}
