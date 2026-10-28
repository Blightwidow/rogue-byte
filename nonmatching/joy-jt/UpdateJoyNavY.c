#include "m2c_macros.h"

s32 FJoyButtonPressed(M2C_UNK);                     /* extern */
extern M2C_UNK g_2dded0;
extern f32 g_2ddf0c;

s32 UpdateJoyNavY(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f0;
    f32 var_f1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_condition_bit;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v1;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1028);
    if (temp_v0 == 0) {
        temp_v0_2 = FJoyButtonPressed(0x5000);
        var_v0_2 = -1;
        if (!(temp_v0_2 & 0x1000)) {
            if (!(temp_v0_2 & 0x4000)) {
                if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.8f) {
                    temp_f2 = M2C_FIELD(arg0, f32 *, 0x1040);
                    if (fabsf(M2C_FIELD(arg0, f32 *, 0x103C)) < fabsf(temp_f2)) {
                        var_v0_2 = -1;
                        if (!(temp_f2 > 0.0f)) {
                            goto block_6;
                        }
                        goto block_7;
                    }
                }
            } else {
block_6:
                var_v0_2 = 1;
                goto block_7;
            }
        } else {
block_7:
            M2C_FIELD(arg0, s32 *, 0x1028) = var_v0_2;
        }
        if (M2C_FIELD(arg0, s32 *, 0x1028) != 0) {
            var_f1 = 0.3333f;
            M2C_FIELD(arg0, f32 *, 0x1038) = 0.3333f;
            var_f0 = g_2ddf0c;
            goto block_28;
        }
        goto block_29;
    }
    var_v1 = 0;
    if (temp_v0 < 0) {
        if (!(M2C_FIELD(arg0, s32 *, 0x10B4) & 0x1000)) {
            if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.25f) {
                temp_f2_2 = M2C_FIELD(arg0, f32 *, 0x1040);
                if (fabsf(M2C_FIELD(arg0, f32 *, 0x103C)) < fabsf(temp_f2_2)) {
                    var_condition_bit = temp_f2_2 > 0.0f;
                    goto block_19;
                }
            }
        } else {
            goto block_20;
        }
    } else if (!(M2C_FIELD(arg0, s32 *, 0x10B4) & 0x4000)) {
        if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.25f) {
            temp_f2_3 = M2C_FIELD(arg0, f32 *, 0x1040);
            if (fabsf(M2C_FIELD(arg0, f32 *, 0x103C)) < fabsf(temp_f2_3)) {
                var_condition_bit = temp_f2_3 < 0.0f;
block_19:
                if (var_condition_bit) {
                    goto block_20;
                }
            }
        }
    } else {
block_20:
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s32 *, 0x1028) = 0;
        goto block_29;
    }
    var_v0 = 0;
    if (M2C_FIELD(arg0, f32 *, 0x1034) <= M2C_FIELD(&g_2dded0, f32 *, 0x3C)) {
        temp_f0 = 2.0f * M2C_FIELD(arg0, f32 *, 0x1038) * 0.33333334f;
        var_f1 = 0.1f;
        if (!(temp_f0 < 0.1f)) {
            var_f1 = temp_f0;
            if (temp_f0 > 0.3333f) {
                var_f1 = 0.3333f;
            }
        }
        M2C_FIELD(arg0, f32 *, 0x1038) = var_f1;
        var_f0 = M2C_FIELD(&g_2dded0, f32 *, 0x3C);
block_28:
        M2C_FIELD(arg0, f32 *, 0x1034) = (f32) (var_f0 + var_f1);
block_29:
        var_v0 = M2C_FIELD(arg0, s32 *, 0x1028);
    }
    return var_v0;
}
