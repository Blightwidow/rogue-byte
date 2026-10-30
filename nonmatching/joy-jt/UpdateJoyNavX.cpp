typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateJoyNavX {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 FJoyButtonPressed(M2C_UNK);                     /* extern */
extern M2C_UNK g_2dded0;
extern f32 g_2ddf0c;
s32 UpdateJoyNavX(s8 *arg0) {
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
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x1024);
    if (temp_v0 == 0) {
        temp_v0_2 = FJoyButtonPressed(0xA000);
        var_v0_2 = -1;
        if (!(temp_v0_2 & 0x8000)) {
            if (!(temp_v0_2 & 0x2000)) {
                if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.8f) {
                    temp_f2 = M2C_FIELD(arg0, f32 *, 0x103C);
                    if (fabsf(M2C_FIELD(arg0, f32 *, 0x1040)) < fabsf(temp_f2)) {
                        var_v0_2 = -1;
                        if (!(temp_f2 < 0.0f)) {
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
            M2C_FIELD(arg0, s32 *, 0x1024) = var_v0_2;
        }
        if (M2C_FIELD(arg0, s32 *, 0x1024) != 0) {
            var_f1 = 0.3333f;
            M2C_FIELD(arg0, f32 *, 0x1030) = 0.3333f;
            var_f0 = g_2ddf0c;
            goto block_28;
        }
        goto block_29;
    }
    var_v1 = 0;
    if (temp_v0 < 0) {
        if (!(M2C_FIELD(arg0, s32 *, 0x10B4) & 0x8000)) {
            if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.25f) {
                temp_f2_2 = M2C_FIELD(arg0, f32 *, 0x103C);
                if (fabsf(M2C_FIELD(arg0, f32 *, 0x1040)) < fabsf(temp_f2_2)) {
                    var_condition_bit = temp_f2_2 < 0.0f;
                    goto block_19;
                }
            }
        } else {
            goto block_20;
        }
    } else if (!(M2C_FIELD(arg0, s32 *, 0x10B4) & 0x2000)) {
        if (M2C_FIELD(arg0, f32 *, 0x1044) >= 0.25f) {
            temp_f2_3 = M2C_FIELD(arg0, f32 *, 0x103C);
            if (fabsf(M2C_FIELD(arg0, f32 *, 0x1040)) < fabsf(temp_f2_3)) {
                var_condition_bit = temp_f2_3 > 0.0f;
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
        M2C_FIELD(arg0, s32 *, 0x1024) = 0;
        goto block_29;
    }
    var_v0 = 0;
    if (M2C_FIELD(arg0, f32 *, 0x102C) <= M2C_FIELD(&g_2dded0, f32 *, 0x3C)) {
        temp_f0 = 2.0f * M2C_FIELD(arg0, f32 *, 0x1030) * 0.33333334f;
        var_f1 = 0.1f;
        if (!(temp_f0 < 0.1f)) {
            var_f1 = temp_f0;
            if (temp_f0 > 0.3333f) {
                var_f1 = 0.3333f;
            }
        }
        M2C_FIELD(arg0, f32 *, 0x1030) = var_f1;
        var_f0 = M2C_FIELD(&g_2dded0, f32 *, 0x3C);
block_28:
        M2C_FIELD(arg0, f32 *, 0x102C) = (f32) (var_f0 + var_f1);
block_29:
        var_v0 = M2C_FIELD(arg0, s32 *, 0x1024);
    }
    return var_v0;
}
}
