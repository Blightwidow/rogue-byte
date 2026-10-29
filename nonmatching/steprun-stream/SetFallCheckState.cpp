typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetFallCheckState {
    /* 0x00 */ char pad0[0x80];
};                                                  /* size = 0x80 */

M2C_UNK PaloAbsorbWkr(s8 *, s32, s32, s32, s32);  /* extern */
M2C_UNK memset(s8 *, M2C_UNK, M2C_UNK);           /* extern */
extern f32 g_2dded0;

void SetFallCheckState(s8 *arg0, s32 arg1) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s32 temp_v1;

    if (M2C_FIELD(arg0, s32 *, 4) != arg1) {
        M2C_FIELD(arg0, s32 *, 4) = arg1;
        M2C_FIELD(arg0, f32 *, 8) = (f32) g_2dded0;
        if (arg1 == 2) {
            memset(sp, 0, 0x60);
            temp_v1 = M2C_FIELD(arg0, s32 *, 0);
            PaloAbsorbWkr(sp, temp_v1, temp_v1, 0x4000, 0);
        }
    }
}

}
