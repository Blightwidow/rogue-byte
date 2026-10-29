typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_SetEpselHint {
    /* 0x00 */ char pad0[0x30];
};                                                  /* size = 0x30 */
M2C_UNK func_00213B00(...);             /* extern */
extern f32 g_2ddf0c;
void SetEpselHint(s8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x12C) != arg1) {
        if (arg1 != 0) {
            if (arg1 == 1) {
                func_00213B00(arg0, 0x5BD);
            }
        } else {
            func_00213B00(arg0, 0x5BE);
        }
        M2C_FIELD(arg0, s32 *, 0x12C) = arg1;
        M2C_FIELD(arg0, f32 *, 0x130) = (f32) g_2ddf0c;
    }
}
}
