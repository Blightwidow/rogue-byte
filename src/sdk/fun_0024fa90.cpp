typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024FA90 {
    /* 0x000 */ char pad0[0x120];
};                                                  /* size = 0x120 */
M2C_UNK func_00236918(s8 *, M2C_UNK, s32, s32);   /* extern */
M2C_UNK func_0024FA38(s32, s8 *);                 /* extern */
void func_0024FA90(s32 arg0, s32 arg1, s32 arg2) {
    s8 sp[0x100] __attribute__((aligned(16)));
    func_00236918(sp, 0x100, arg1, arg2);
    func_0024FA38(arg0, sp);
}
}
