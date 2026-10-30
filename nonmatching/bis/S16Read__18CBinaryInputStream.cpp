typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_S16Read__18CBinaryInputStream {
    /* 0x00 */ s16 sp0;                             /* inferred */
    /* 0x02 */ char pad2[0x1E];
};                                                  /* size = 0x20 */
#define sp0 (*(s16 *)(sp + 0x00))
M2C_UNK CBinaryInputStream_Read_thunk(s8 *, M2C_UNK, s8 *, s8 *); /* extern */
s16 S16Read__18CBinaryInputStream(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 temp_a0;
    s8 *temp_v1;
    temp_a0 = M2C_FIELD(arg0, s32 *, 8);
    if (temp_a0 < 2) {
        CBinaryInputStream_Read_thunk(arg0, 2, sp, arg0);
        return sp0;
    }
    temp_v1 = M2C_FIELD(arg0, s8 **, 4);
    M2C_FIELD(arg0, s32 *, 8) = (s32) (temp_a0 - 2);
    M2C_FIELD(arg0, s8 **, 4) = (s8 *) (temp_v1 + 2);
    return M2C_FIELD(temp_v1, u8 *, 0) | (s16) (M2C_FIELD(temp_v1, u8 *, 1) << 8);
}
}
