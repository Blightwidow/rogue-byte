#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
f32 SWrapCrv(s32, f32);                             /* extern */
M2C_UNK SetAsegaSpeed(s32, f32);                    /* extern */
f32 atan2f(void *, f32, f32);                       /* extern */
M2C_UNK func_0017CD00(void *, M2C_UNK);             /* extern */
s32 func_0017CE30(void *);                          /* extern */
M2C_UNK func_001EEF98();                            /* extern */
M2C_UNK func_00209818(void *, f32);                 /* extern */
extern f32 D_FLT_002BE74C;

void PresetPuffcAccel__FP5PUFFCf(void *arg0) {
    M2C_UNK sp0;
    M2C_UNK sp4;
    f32 sp20;
    f32 temp_f0;
    f32 var_f12;
    s32 temp_s2;
    s32 var_v1;
    void *temp_s0;
    void *temp_v0;

    func_001EEF98();
loop_1:
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        temp_v0 = M2C_FIELD(arg0, void **, 0x10);
        var_v1 = 1;
        temp_f0 = M2C_FIELD(temp_v0, f32 *, 0xF88);
        temp_s2 = M2C_FIELD(temp_v0, s32 *, 0xF84);
        sp20 = temp_f0;
        if (!(temp_f0 < M2C_FIELD(arg0, f32 *, 0x3C))) {
            var_v1 = 0;
        }
        M2C_FIELD(temp_v0, s32 *, 0xF8C) = var_v1;
        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
        M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF8C) != 0) {
            var_f12 = sp20 + D_FLT_002BE74C;
        } else {
            var_f12 = sp20 - D_FLT_002BE74C;
        }
        FindCrvClosestPointFromS(temp_s2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), 0, 0, SWrapCrv(temp_s2, var_f12));
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0xF88) = sp20;
        if (func_0017CE30(arg0) != 0) {
            func_0017CD00(arg0, 1);
        } else {
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF8C) == 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $s5, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            }
            temp_s0 = M2C_FIELD(arg0, void **, 0x10) + 0xFD0;
            func_00209818(temp_s0, atan2f(arg0, sp4, sp0));
            SetAsegaSpeed(M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), void **, 0x40), s32 *, 8), M2C_FIELD(arg0, f32 *, 0x38));
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) != M2C_FIELD(arg0, s32 *, 0x30)) {
        goto loop_1;
    }
}
