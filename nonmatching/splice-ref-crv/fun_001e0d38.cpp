typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_001E0D38 {
    /* 0x00 */ char pad0[0x60];
};                                                  /* size = 0x60 */
s8 *PjsgeAllocJsg(M2C_UNK, M2C_UNK);              /* extern */
void func_001E0D38(s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0, f32 fparg1) {
    s8 *temp_v0;
    temp_v0 = PjsgeAllocJsg(0x28, 0);
    M2C_FIELD(temp_v0, s32 *, 0x24) = arg4;
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, f32 *, 0x14) = fparg0;
    M2C_FIELD(temp_v0, s32 *, 0x18) = arg2;
    M2C_FIELD(temp_v0, f32 *, 0x1C) = fparg1;
    M2C_FIELD(temp_v0, s32 *, 0x20) = arg3;
}
}
