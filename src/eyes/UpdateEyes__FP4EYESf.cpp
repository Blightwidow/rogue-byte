typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_UpdateEyes__FP4EYESf {
    /* 0x00 */ char pad0[0x20];
};                                                  /* size = 0x20 */
s32 FIsSlEmpty(s32);                                /* extern */
M2C_UNK SetEyesEyess__FP4EYES5EYESS(s8 *, s32);   /* extern */
M2C_UNK SetSaiIframe(s8 *, s32);                  /* extern */
extern f32 g_2dded0;
extern f32 g_2dded4;
void UpdateEyes__FP4EYESf(s8 *arg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_a0;
    s32 var_a1;
    if (FIsSlEmpty((int)(arg0 + 0x34)) == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x1C);
        if (temp_a0 >= 2) {
            var_a1 = M2C_FIELD(arg0, s32 *, 0x64);
            switch (var_a1) {                       /* irregular */
            case 0:
                if (M2C_FIELD(arg0, f32 *, 0x6C) <= (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x68))) {
                    var_a1 = 1;
                }
                break;
            case 1:
                temp_f2 = M2C_FIELD(arg0, f32 *, 0x70) * g_2dded4;
                temp_f0 = M2C_FIELD(arg0, f32 *, 0x74) + temp_f2;
                M2C_FIELD(arg0, f32 *, 0x74) = temp_f0;
                if ((f32) temp_a0 <= temp_f0) {
                    temp_f0_2 = temp_f0 - temp_f2;
                    M2C_FIELD(arg0, f32 *, 0x74) = temp_f0_2;
                    var_a1 = (((s32) temp_f0_2 ^ (temp_a0 - 1)) == 0) ? 2 : 3;
                }
                break;
            case 2:
                if (M2C_FIELD(arg0, f32 *, 0x78) < 1.0f) {
                    var_a1 = 3;
                }
                break;
            case 3:
                temp_f1 = M2C_FIELD(arg0, f32 *, 0x74) - (M2C_FIELD(arg0, f32 *, 0x70) * g_2dded4);
                M2C_FIELD(arg0, f32 *, 0x74) = temp_f1;
                if (temp_f1 <= ((f32) temp_a0 * M2C_FIELD(arg0, f32 *, 0x78))) {
                    var_a1 = 0;
                }
                break;
            }
            SetEyesEyess__FP4EYES5EYESS(arg0, var_a1);
            SetSaiIframe(arg0, (s32) M2C_FIELD(arg0, f32 *, 0x74));
        }
    }
}
}
