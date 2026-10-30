typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ConvertXfMatrix4 {
    /* 0x000 */ char pad0[0x40];
    /* 0x040 */ M2C_UNK sp40;                       /* inferred */
    /* 0x040 */ char pad40[0x40];
    /* 0x080 */ M2C_UNK sp80;                       /* inferred */
    /* 0x080 */ char pad80[0xA0];
};                                                  /* size = 0x120 */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, s32);        /* extern */
M2C_UNK __ml__FRC7MATRIX4T0(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK memcpy(s32, M2C_UNK *, M2C_UNK);            /* extern */
s32 ConvertXfMatrix4(s32 arg0, s32 arg1, s32 arg2, M2C_UNK *arg3) {
    s8 sp[0xb0] __attribute__((aligned(16)));
    M2C_UNK sp40;
    M2C_UNK sp80;
    M2C_UNK *var_a1;
    if (arg1 != 0) {
        if (arg2 != 0) {
            InvertMatrix4Affine(&sp80, arg2 + 0x40);
            __ml__FRC7MATRIX4T0(&sp40, &sp80, (M2C_UNK *)(arg1 + 0x40));
            var_a1 = &sp40;
        } else {
            var_a1 = (M2C_UNK *)(arg1 + 0x40);
        }
        goto block_6;
    }
    if (arg2 != 0) {
        InvertMatrix4Affine(&sp40, arg2 + 0x40);
        var_a1 = &sp40;
block_6:
        __ml__FRC7MATRIX4T0((M2C_UNK *)(sp), var_a1, arg3);
        memcpy(arg0, (M2C_UNK *)(sp), 0x40);
    } else {
        memcpy(arg0, arg3, 0x40);
    }
    return arg0;
}
}
