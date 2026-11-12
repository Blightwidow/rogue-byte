typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_func_0024C4B0 {
    /* 0x00 */ char pad0[0x20];
    /* 0x20 */ s32 sp20;                            /* inferred */
    /* 0x24 */ s32 sp24;                            /* inferred */
    /* 0x28 */ s32 sp28;                            /* inferred */
    /* 0x2C */ s32 sp2C;                            /* inferred */
    /* 0x30 */ s32 sp30;                            /* inferred */
    /* 0x34 */ char pad34[0x4C];
};                                                  /* size = 0x80 */
s32 AddDmacHandler_2(M2C_UNK, M2C_UNK *, M2C_UNK, s32 *); /* extern */
M2C_UNK RemoveDmacHandler(M2C_UNK, s32);            /* extern */
M2C_UNK func_002351E0(M2C_UNK);                     /* extern */
M2C_UNK func_00235248(M2C_UNK);                     /* extern */
s32 func_00239450();                                /* extern */
M2C_UNK func_002394A0(M2C_UNK, M2C_UNK);            /* extern */
M2C_UNK func_0024B670(s32, s8 *, M2C_UNK, s32);   /* extern */
M2C_UNK func_0024FA38(s8 *, M2C_UNK *);           /* extern */
extern M2C_UNK func_0024CB48;
void func_0024C4B0(s8 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x80] __attribute__((aligned(16)));
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 temp_s2;
    s32 temp_v0;
    sp28 = arg2;
    sp2C = (arg1 + 0xFFC00) & 0x0FFFFFFF;
    sp24 = 0;
    sp20 = 0;
    sp30 = (arg2 / 1023) + 1;
    do {
    } while (*(s32 *)0x10002010 < 0);
    temp_s2 = AddDmacHandler_2(3, &func_0024CB48, 0, &sp20);
    *(s32 *)0x1000E010 = 8;
    func_00235248(3);
    temp_v0 = func_00239450();
    *(s32 *)0x1000B010 = arg1 & 0x0FFFFFFF;
    *(s32 *)0x1000B020 = 0xFFC0;
    *(s32 *)0x1000B000 = 0x100;
    if (temp_v0 != 0) {
        func_002394A0(0x1000B000, 0x1000B020);
    }
    *(s32 *)0x10002000 = 0x700003FF;
    func_0024B670(M2C_FIELD(arg0, s32 *, 0x868), sp, 4, 4);
    do {
    } while (sp20 < sp30);
    if (sp24 != 0) {
        func_0024FA38(arg0, (M2C_UNK *)("CSC handler error\n"));
    }
    do {
    } while (*(s8 *)0x10002010 < 0);
    func_002351E0(3);
    RemoveDmacHandler(3, temp_s2);
}
}
