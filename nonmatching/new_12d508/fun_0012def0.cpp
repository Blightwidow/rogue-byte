typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0012DEF0 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ s128 sp40;                          /* inferred */
    /* 0x050 */ s128 sp50;                          /* inferred */
    /* 0x060 */ s128 sp60;                          /* inferred */
    /* 0x070 */ s128 sp70;                          /* inferred */
    /* 0x080 */ s128 sp80;                          /* inferred */
    /* 0x090 */ char pad90[0x30];                   /* maybe part of sp80[4]? */
    /* 0x0C0 */ s128 spC0;                          /* inferred */
    /* 0x0D0 */ char padD0[0x80];
};                                                  /* size = 0x150 */
#define sp50 (*(s128 *)(sp + 0x050))
#define sp60 (*(s128 *)(sp + 0x060))
#define sp70 (*(s128 *)(sp + 0x070))
s128 GetXfDofValue(s8 *, s8 *); /* extern */
M2C_UNK InvertMatrix4Affine(s128 *, s32);           /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(s128 *, s128 *, s8 *); /* extern */
extern s128 g_2a2dd0;
void func_0012DEF0(s8 *arg0) {
    s8 sp[0xe0] __attribute__((aligned(16)));
    s128 sp40;
    s128 sp80;
    s128 spC0;
    s128 *var_a1;
    s32 temp_a1;
    s8 *temp_s0;
    s8 *var_a2;
    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s32 *, 0xA0);
    if (temp_a1 != 0) {
        InvertMatrix4Affine(&spC0, temp_a1 + 0x40);
        __ml__FRC7MATRIX4T0(&sp80, &spC0, (s8 *)(M2C_FIELD(arg0, s32 *, 0x1C) + 0x40));
        var_a1 = &sp80;
        var_a2 = arg0 + 0x20;
    } else {
        var_a2 = arg0 + 0x20;
        var_a1 = (s128 *)(M2C_FIELD(arg0, s32 *, 0x1C) + 0x40);
    }
    __ml__FRC7MATRIX4T0(&sp40, var_a1, var_a2);
    temp_s0 = M2C_FIELD(arg0, s8 **, 8);
    M2C_FIELD(temp_s0, s128 *, 0xC0) = GetXfDofValue(temp_s0, sp);
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s128 *, 0xD0) = (s128) g_2a2dd0;
    M2C_FIELD(M2C_FIELD(arg0, s8 **, 8), s16 *, 0x9A) = 3;
}
}
