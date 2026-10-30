typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_BuildClutGifs__FP4CLUTiP4GIFS {
    /* 0x00 */ char pad0[0x10];
};                                                  /* size = 0x10 */
M2C_UNK BuildImageGifs__FiiiiiiP4GIFS(s32, M2C_UNK, M2C_UNK, s32, s32, s32, s32); /* extern */
void BuildClutGifs__FP4CLUTiP4GIFS(s8 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a3;
    u16 temp_v0;
    temp_v0 = M2C_FIELD(arg0, u16 *, 8);
    temp_a3 = (temp_v0 >= 0x11U) ? 0x10 : 8;
    BuildImageGifs__FiiiiiiP4GIFS(arg1, 1, 0, temp_a3, (s32) ((temp_v0 - 1 + temp_a3) & -temp_a3) / temp_a3, M2C_FIELD(arg0, s32 *, 0x10), arg2);
}
}
