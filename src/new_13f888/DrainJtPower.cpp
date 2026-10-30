typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_DrainJtPower {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
s32 GetJtPower(f32);                                /* extern */
M2C_UNK SetJtPower(s8 *, s32);                    /* extern */
extern f32 g_2dded4;
void DrainJtPower(s8 *arg0, f32 fparg0) {
    f32 temp_f12;
    f32 temp_f1;
    s32 temp_f0;
    s32 temp_v0;
    temp_f12 = fparg0 * g_2dded4;
    temp_f1 = M2C_FIELD(arg0, f32 *, 0x1308) + temp_f12;
    temp_f0 = (s32) temp_f1;
    M2C_FIELD(arg0, f32 *, 0x1308) = temp_f1;
    if (temp_f0 != 0) {
        M2C_FIELD(arg0, f32 *, 0x1308) = (f32) (temp_f1 - (f32) temp_f0);
        temp_v0 = GetJtPower(temp_f12) - temp_f0;
        SetJtPower(arg0, (temp_v0 > -1) ? temp_v0 : 0);
    }
}
}
