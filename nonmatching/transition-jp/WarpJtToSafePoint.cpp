typedef signed char s8; typedef short s16; typedef int s32; typedef long s64;
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32; typedef unsigned long u64;
typedef float f32; typedef double f64; typedef int s128 __attribute__((mode(TI)));
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32; typedef s64 M2C_UNK64;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define NULL 0
extern "C" {
struct _m2c_stack_WarpJtToSafePoint {
    /* 0x00 */ s32 sp0;                             /* inferred */
    /* 0x04 */ s32 sp4;                             /* inferred */
    /* 0x08 */ char pad8[0x18];                     /* maybe part of sp4[7]? */
    /* 0x20 */ s128 sp20;                           /* inferred */
    /* 0x30 */ char pad30[0x70];
};                                                  /* size = 0xA0 */
#define sp0 (*(s32 *)(sp + 0x00))
#define sp4 (*(s32 *)(sp + 0x04))
f32 DtSolveJumpLaunch(M2C_UNK, s128, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
s32 FIsBasicDerivedFrom(s32, M2C_UNK);
void FindBestSafePoint(s32, s8 *);
void JtbsChooseJtLanding(s8 *, s32);
s32 PpoSwFocusBase(M2C_UNK *);
void SetJmpState(s8 *, M2C_UNK, M2C_UNK, M2C_UNK);
s32 SetResetFlag__FP2CM(M2C_UNK *);
void SetStepRadTargetDir(s8 *, s128);
s32 StartFade(s32);
void func_00148300(M2C_UNK *, s32);
s32 func_0019F3F8(s8 *, s8 *, M2C_UNK);
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BF940;
void WarpJtToSafePoint(s8 *arg0, s8 *arg1) {
    s8 sp[0x40] __attribute__((aligned(16)));
    s128 sp20;
    s32 temp_s0;
    s8 *temp_s2;
    s8 *temp_v0;
    s8 *temp_v1;
    s8 *var_s0;
    var_s0 = arg1;
    if (var_s0 == NULL) {
        FindBestSafePoint((int)(arg0 + 0x9E0), sp);
        var_s0 = sp;
        if ((s32)arg0 == PpoSwFocusBase(&B_003DD490)) {
            sp20 = func_0019F3F8(arg0, sp, 0);
            asm volatile("lqc2 vf1, 0x70(%0)" : : "r"(M2C_FIELD(arg0, s32 *, 0x58)));
            asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
            asm volatile("vsub.xyzw vf2, vf2, vf1");
            temp_s2 = arg0 + 0x2C0;
            s32 vu_1;
            asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_1));
            if (D_FLT_002BF940 < DtSolveJumpLaunch(vu_1, M2C_FIELD(M2C_FIELD(arg0, s8 **, 0xE8), s128 *, 0x80), 0x447A0000, 0xC47A0000, 0x3F800000, 0xBF800000)) {
                temp_v1 = M2C_FIELD(arg0, s8 **, 0xC);
                asm volatile("lqc2 vf1, 0x240(%0)" : : "r"(arg0));
                asm volatile("lqc2 vf2, 0x20(%0)" : : "r"(sp));
                asm volatile("vsub.xyzw vf2, vf2, vf1");
                temp_s0 = M2C_FIELD(arg0, s32 *, 0x9E4);
                s32 vu_2;
                asm volatile("qmfc2.ni %0, vf2" : "=r"(vu_2));
                M2C_FIELD(temp_v1, M2C_UNK (**)(s8 *, M2C_UNK), 0xEC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xE8), vu_2);
                M2C_FIELD(arg0, s32 *, 0x9E4) = temp_s0;
                SetStepRadTargetDir(arg0, M2C_FIELD(&B_002DDF40, s128 *, 0x60));
                temp_v0 = M2C_FIELD(arg0, s8 **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(s8 *, s8 *), 0xF4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xF0), arg0 + 0x1B0);
                SetResetFlag__FP2CM(&B_002DDF40);
                SetJmpState(temp_s2, 0xB, 0, 0);
                if ((sp4 != 0) && ((FIsBasicDerivedFrom(sp0, 0x13) != 0) || (FIsBasicDerivedFrom(sp0, 0xB) != 0) || (FIsBasicDerivedFrom(sp0, 0xD) != 0) || (FIsBasicDerivedFrom(sp0, 0x27) != 0) || (FIsBasicDerivedFrom(sp0, 0xC) != 0) || (FIsBasicDerivedFrom(sp0, 0x22) != 0) || (FIsBasicDerivedFrom(sp0, 0x26) != 0))) {
                    func_00148300(&B_003DD490, sp0);
                    JtbsChooseJtLanding(temp_s2, sp0);
                }
                StartFade(M2C_FIELD(&B_003DD490, s32 *, 0x3E60));
                return;
            }
        }
    }
    M2C_FIELD(arg0, s128 *, 0x490) = (s128) M2C_FIELD(var_s0, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x4A0) = (s128) M2C_FIELD(var_s0, s128 *, 0x10);
    SetJmpState(arg0 + 0x2C0, 0xA, 0, 0);
}
}
