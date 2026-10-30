typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_sprintf {
    /* 0x00 */ char pad0[0x40];
    /* 0x40 */ f32 sp40;                            /* inferred */
    /* 0x44 */ f32 sp44;                            /* inferred */
    /* 0x48 */ f32 sp48;                            /* inferred */
    /* 0x4C */ f32 sp4C;                            /* inferred */
    /* 0x50 */ s64 sp50;                            /* inferred */
    /* 0x58 */ s64 sp58;                            /* inferred */
    /* 0x60 */ s64 sp60;                            /* inferred */
    /* 0x68 */ s64 sp68;                            /* inferred */
    /* 0x70 */ s64 sp70;                            /* inferred */
    /* 0x78 */ s64 sp78;                            /* inferred */
};                                                  /* size = 0x80 */
M2C_UNK vsprintf(s64 *);                            /* extern */
void sprintf(s64 arg2, s64 arg3, s64 arg4, s64 arg5, s64 arg6, s64 arg7, f32 fparg0, f32 fparg2, f32 fparg4, f32 fparg6) {
    f32 sp40;
    f32 sp44;
    f32 sp48;
    f32 sp4C;
    s64 sp50;
    s64 sp58;
    s64 sp60;
    s64 sp68;
    s64 sp70;
    s64 sp78;
    sp50 = arg2;
    sp58 = arg3;
    sp60 = arg4;
    sp68 = arg5;
    sp70 = arg6;
    sp78 = arg7;
    sp40 = fparg0;
    sp44 = fparg2;
    sp48 = fparg4;
    sp4C = fparg6;
    vsprintf(&sp50);
}
}
