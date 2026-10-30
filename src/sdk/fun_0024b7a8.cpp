typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024B7A8 {};                 /* size 0x0 */
s32 func_0024B7A8(s8 *arg0) {
    s8 *temp_v0;
    s8 *temp_v0_2;
    s8 *temp_v0_3;
    s8 *temp_v0_4;
    s8 *temp_v0_5;
    s8 *temp_v0_6;
    s8 *temp_v1;
    temp_v1 = M2C_FIELD(arg0, s8 **, 0x40);
    temp_v0 = M2C_FIELD(temp_v1, s8 **, 0x1C8);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s32 *, 0x28) = 0;
    }
    temp_v0_2 = M2C_FIELD(temp_v1, s8 **, 0x1D8);
    if (temp_v0_2 != NULL) {
        M2C_FIELD(temp_v0_2, s32 *, 0x28) = 0;
    }
    temp_v0_3 = M2C_FIELD(temp_v1, s8 **, 0x1E8);
    if (temp_v0_3 != NULL) {
        M2C_FIELD(temp_v0_3, s32 *, 0x28) = 0;
    }
    temp_v0_4 = M2C_FIELD(temp_v1, s8 **, 0x1CC);
    if (temp_v0_4 != NULL) {
        M2C_FIELD(temp_v0_4, s32 *, 0x28) = 0;
    }
    temp_v0_5 = M2C_FIELD(temp_v1, s8 **, 0x1DC);
    if (temp_v0_5 != NULL) {
        M2C_FIELD(temp_v0_5, s32 *, 0x28) = 0;
    }
    temp_v0_6 = M2C_FIELD(temp_v1, s8 **, 0x1EC);
    if (temp_v0_6 != NULL) {
        M2C_FIELD(temp_v0_6, s32 *, 0x28) = 0;
    }
    return 1;
}
}
