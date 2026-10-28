#include "m2c_macros.h"

f32 DtSolveJumpLaunch(M2C_UNK, s128, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK FindBestSafePoint(s32, void *);             /* extern */
M2C_UNK JtbsChooseJtLanding(void *, s32);           /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
M2C_UNK SetJmpState(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK SetResetFlag__FP2CM(M2C_UNK *);             /* extern */
M2C_UNK SetStepRadTargetDir(void *, s128);          /* extern */
M2C_UNK StartFade(s32);                             /* extern */
M2C_UNK func_00148300(M2C_UNK *, s32);              /* extern */
s128 func_0019F3F8(void *, void *, M2C_UNK);        /* extern */
extern M2C_UNK B_002DDF40;
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002BF940;

void WarpJtToSafePoint(void *arg0, void *arg1) {
    char sp[0x400];
    M2C_UNK sp0;
    M2C_UNK sp4;
    s128 sp20;
    s32 temp_s0;
    void *temp_s2;
    void *temp_v0;
    void *temp_v1;
    void *var_s0;

    var_s0 = arg1;
    if (var_s0 == NULL) {
        FindBestSafePoint(arg0 + 0x9E0, sp);
        var_s0 = sp;
        if (arg0 == PpoSwFocusBase(&B_003DD490)) {
            sp20 = func_0019F3F8(arg0, sp, 0);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
            temp_s2 = arg0 + 0x2C0;
            if (D_FLT_002BF940 < DtSolveJumpLaunch(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), M2C_FIELD(M2C_FIELD(arg0, void **, 0xE8), s128 *, 0x80), 0x447A0000, 0xC47A0000, 0x3F800000, 0xBF800000)) {
                temp_v1 = M2C_FIELD(arg0, void **, 0xC);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x240($s3) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                temp_s0 = M2C_FIELD(arg0, s32 *, 0x9E4);
                M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK), 0xEC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xE8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
                M2C_FIELD(arg0, s32 *, 0x9E4) = temp_s0;
                SetStepRadTargetDir(arg0, M2C_FIELD(&B_002DDF40, s128 *, 0x60));
                temp_v0 = M2C_FIELD(arg0, void **, 0xC);
                M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0xF4)(arg0 + M2C_FIELD(temp_v0, s16 *, 0xF0), arg0 + 0x1B0);
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
