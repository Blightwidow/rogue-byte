typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefSetArgsFromSplice__FiP4CRefP4OTYPe {
    /* 0x000 */ char pad0[0xD0];
    /* 0x0D0 */ f32 spD0;                           /* inferred */
    /* 0x0D4 */ f32 spD4;                           /* inferred */
    /* 0x0D8 */ f32 spD8;                           /* inferred */
    /* 0x0DC */ f32 spDC;                           /* inferred */
    /* 0x0E0 */ s64 spE0;                           /* inferred */
    /* 0x0E8 */ s64 spE8;                           /* inferred */
    /* 0x0F0 */ s64 spF0;                           /* inferred */
    /* 0x0F8 */ s64 spF8;                           /* inferred */
};                                                  /* size = 0x100 */
M2C_UNK RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(s32, s32 *); /* extern */
s32 RefSetArgsFromSplice__FiP4CRefP4OTYPe(s32 arg0, s32 arg1, s64 arg4, s64 arg5, s64 arg6, s64 arg7, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    s8 sp[0x70] __attribute__((aligned(16)));
    f32 spD0;
    f32 spD4;
    f32 spD8;
    f32 spDC;
    s64 spE0;
    s64 spE8;
    s64 spF0;
    s64 spF8;
    s32 *var_a0;
    s32 var_v1;
    s64 *var_a4;
    spE0 = arg4;
    var_a4 = &spE0;
    spE8 = arg5;
    spF0 = arg6;
    spF8 = arg7;
    spD0 = fparg0;
    spD4 = fparg2;
    spD8 = fparg4;
    spDC = fparg6;
    if (arg1 > 0) {
        var_a0 = (s32 *)(sp);
        var_v1 = arg1;
        do {
            var_a4 += 8;
            var_v1 -= 1;
            *var_a0 = M2C_FIELD(var_a4, s32 *, -8);
            var_a0 += 4;
        } while (var_v1 != 0);
    }
    RefSetPvsFromSplice__FiP4CRefP4OTYPPPv(arg0, (s32 *)(sp));
    return arg0;
}
}
