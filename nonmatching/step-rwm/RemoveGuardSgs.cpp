typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_RemoveGuardSgs {
    /* 0x00 */ char pad0[0x10];
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ s32 sp14;                            /* inferred */
    /* 0x18 */ char pad18[0x28];
};                                                  /* size = 0x40 */
s32 GrfsgsFromSgs(s32, s32);
void SetGuardGrfsgs(s8 *, s32);
void RemoveGuardSgs(s8 *arg0, s32 arg1) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    s32 sp14;
    s8 *temp_v1;
    sp14 = arg1;
    SetGuardGrfsgs(arg0, M2C_FIELD(arg0, s64 *, 0x2C0) & ~GrfsgsFromSgs(arg1, arg1));
    temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
    sp10 = -1;
    M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK, M2C_UNK, M2C_UNK, s8 *, M2C_UNK, s32 *, s32 *), 0x1C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x18), 7, 0, 2, sp, 0, &sp10, &sp14);
}
}
