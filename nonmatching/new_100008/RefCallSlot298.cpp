typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RefCallSlot298 {
    /* 0x00 */ char pad0[0x40];
};                                                  /* size = 0x40 */
M2C_UNK CRef_CopyConstruct(s32, s8 *);            /* extern */
M2C_UNK CRef_Destruct(s8 *);                      /* extern */
M2C_UNK RefSetArgsFromSplice__FiP4CRefP4OTYPe(s8 *, M2C_UNK, s32, M2C_UNK); /* extern */
M2C_UNK SetTag__4CRef4TAGK(s8 *, M2C_UNK);        /* extern */
s32 RefCallSlot298(s32 arg0, s8 *arg1, s32 arg3) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s8 *temp_v0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(sp, 0, arg3, 0);
    CRef_Destruct(sp);
    SetTag__4CRef4TAGK(sp, 0x24);
    temp_v0 = M2C_FIELD(arg1, s8 **, 0xC);
    M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *), 0x29C)(arg1 + M2C_FIELD(temp_v0, s16 *, 0x298));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
}
