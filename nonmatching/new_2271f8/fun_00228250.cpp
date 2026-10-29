typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_00228250 {
    /* 0x00 */ char pad0[4];
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x34];                     /* maybe part of sp4[0xE]? */
    /* 0x3C */ s32 sp3C;                            /* inferred */
    /* 0x40 */ s32 sp40;                            /* inferred */
    /* 0x44 */ char pad44[0x2C];
};                                                  /* size = 0x70 */
#define sp4 (*(s32 *)(sp + 0x04))
#define sp3C (*(s32 *)(sp + 0x3C))
M2C_UNK CBinaryInputStream_Read_thunk(M2C_UNK, s8 *); /* extern */
s32 PvAllocSwCopyImpl__FiPv(s32 *, s8 *);         /* extern */
void func_00228250(s32 *arg1) {
    s8 sp[0x70] __attribute__((aligned(16)));
    s32 sp40;
    CBinaryInputStream_Read_thunk(0x40, sp);
    if (sp4 != sp3C) {
        sp40 = 0x40;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        *arg1 = PvAllocSwCopyImpl__FiPv(&sp40, sp);
        return;
    }
    *arg1 = 0;
}
}
