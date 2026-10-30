typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_F32Read__18CBinaryInputStream {
    /* 0x00 */ f32 sp0;                             /* inferred */
    /* 0x04 */ char pad4[0x1C];
};                                                  /* size = 0x20 */
#define sp0 (*(f32 *)(sp + 0x00))
M2C_UNK CBinaryInputStream_Read_thunk(s8 *, M2C_UNK, s8 *, s32); /* extern */
f32 F32Read__18CBinaryInputStream(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_a3;
    s8 *temp_v0;
    temp_a3 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a3 < 4) {
        CBinaryInputStream_Read_thunk(arg0, 4, sp, temp_a3);
        return sp0;
    }
    temp_v0 = M2C_FIELD(arg0, s8 **, 4);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a3 - 4);
    M2C_FIELD(arg0, s8 **, 4) = (s8 *) (temp_v0 + 4);
    M2C_BITWISE(f32, (M2C_FIELD(temp_v0, u8 *, 0) + (M2C_FIELD(temp_v0, u8 *, 1) << 8) + (M2C_FIELD(temp_v0, u8 *, 2) << 0x10) + (M2C_FIELD(temp_v0, u8 *, 3) << 0x18)));
}
}
