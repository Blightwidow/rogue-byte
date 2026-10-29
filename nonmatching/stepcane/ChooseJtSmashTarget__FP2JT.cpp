typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_ChooseJtSmashTarget__FP2JT {
    /* 0x00 */ s128 sp0;                            /* inferred */
    /* 0x10 */ s32 sp10;                            /* inferred */
    /* 0x14 */ char pad14[0x2C];
};                                                  /* size = 0x40 */
#define sp0 (*(s128 *)(sp + 0x00))
void ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(s8 *, M2C_UNK, M2C_UNK *, s32 *, f32, M2C_UNK, f32);
void FixStepAngularVelocity__FP4STEP(s8 *);
M2C_UNK SetStepRadTargetDir(s8 *, s128);
extern M2C_UNK D_002BF4E0;
void ChooseJtSmashTarget__FP2JT(s8 *arg0) {
    s8 sp[0x10] __attribute__((aligned(16)));
    s32 sp10;
    ChooseJtAttackTarget__FP2JTiP6VECTORffPP6TARGETT2(arg0, 4, &D_002BF4E0, &sp10, M2C_FIELD(arg0, f32 *, 0x1A8), 0x3E800000, 0x4049999A);
    M2C_FIELD(arg0, s32 *, 0x18C0) = sp10;
    if (sp10 != 0) {
        SetStepRadTargetDir(arg0, sp0);
        FixStepAngularVelocity__FP4STEP(arg0);
    }
}
}
