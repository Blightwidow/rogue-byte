typedef signed char s8; typedef short s16; typedef int s32; typedef long long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001B4478 {
    /* 0x000 */ char pad0[0x430];
};                                                  /* size = 0x430 */

M2C_UNK InitRenderNodeStack(s8 *);                /* extern */
M2C_UNK RenderGlobset(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK RenderGlobsetTree(s8 *, s8 *);          /* extern */

void func_001B4478(s8 *arg0) {
    s8 sp[0x430] __attribute__((aligned(16)));
    if (M2C_FIELD(arg0, s32 *, 0xC8) != 0) {
        InitRenderNodeStack(sp);
        RenderGlobsetTree(sp, arg0 + 0x80);
        return;
    }
    RenderGlobset(arg0 + 0x80, 0, 0, 0x3F800000, 0x3F800000);
}

}
