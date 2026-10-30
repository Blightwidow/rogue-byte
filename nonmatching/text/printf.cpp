typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_printf {
    /* 0x00 */ char pad0[0x48];
    /* 0x48 */ f32 sp48;                            /* inferred */
    /* 0x4C */ f32 sp4C;                            /* inferred */
    /* 0x50 */ f32 sp50;                            /* inferred */
    /* 0x54 */ f32 sp54;                            /* inferred */
    /* 0x58 */ s64 sp58;                            /* inferred */
    /* 0x60 */ s64 sp60;                            /* inferred */
    /* 0x68 */ s64 sp68;                            /* inferred */
    /* 0x70 */ s64 sp70;                            /* inferred */
    /* 0x78 */ s64 sp78;                            /* inferred */
    /* 0x80 */ s64 sp80;                            /* inferred */
    /* 0x88 */ s64 sp88;                            /* inferred */
};                                                  /* size = 0x90 */
M2C_UNK vprintf(s64 *);                             /* extern */
void printf(s64 arg1, s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    f32 sp54;
    s64 sp58;
    s64 sp60;
    s64 sp68;
    s64 sp70;
    s64 sp78;
    s64 sp80;
    s64 sp88;
    sp58 = arg1;
    sp60 = arg2;
    sp68 = arg3;
    sp70 = arg4;
    sp78 = arg5;
    sp80 = arg6;
    sp88 = arg7;
    sp48 = fparg0;
    sp4C = fparg2;
    sp50 = fparg4;
    sp54 = fparg6;
    vprintf(&sp58);
}
}
