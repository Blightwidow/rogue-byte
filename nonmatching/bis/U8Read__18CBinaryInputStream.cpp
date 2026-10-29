typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_U8Read__18CBinaryInputStream {
    /* 0x00 */ u8 sp0;                              /* inferred */
    /* 0x01 */ char pad1[0x1F];
};                                                  /* size = 0x20 */
#define sp0 (*(u8 *)(sp + 0x00))
M2C_UNK CBinaryInputStream_Read_thunk(s8 *, M2C_UNK, s8 *); /* extern */
u8 U8Read__18CBinaryInputStream(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_a0;
    u8 *temp_v1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a0 > 0) {
        temp_v1 = M2C_FIELD(arg0, u8 **, 4);
        M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a0 - 1);
        M2C_FIELD(arg0, u8 **, 4) = (u8 *) (temp_v1 + 1);
        return *temp_v1;
    }
    CBinaryInputStream_Read_thunk(arg0, 1, sp);
    return sp0;
}
}
