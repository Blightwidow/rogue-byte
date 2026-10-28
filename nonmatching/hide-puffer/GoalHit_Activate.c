#include "m2c_macros.h"

f32 *PmatLoWorld();                           /* extern */
M2C_UNK PosLoWorld();                   /* extern */
s32 PpoSwFocusBase();                      /* extern */
f32 RadNormalize__Ff();                          /* extern */
M2C_UNK ReplaceSwHitFx(); /* extern */
M2C_UNK SetJumperTarget();              /* extern */
s128 SetVectorCylind__FP6VECTORfff(); /* extern */
M2C_UNK TriggerJoyRumbleRumk__FP3JOY4RUMKf(); /* extern */
f32 atan2f();                               /* extern */
M2C_UNK func_00174950();                            /* extern */
s32 func_001A6AF8();                        /* extern */
M2C_UNK func_001EEFC0();                      /* extern */
M2C_UNK func_00209818();                 /* extern */
M2C_UNK func_0020AB68(); /* extern */
extern M2C_UNK B_002DFC00;
extern M2C_UNK B_003DD490;
extern s128 g_2a2dd0;
extern f32 g_2dded0;
extern s32 g_2f7900;

void GoalHit_Activate(void *arg0) {
    f32 *temp_s0;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_v0;
    s32 var_v0;
    void *temp_v1;

    func_00174950();
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($s1) */);
    var_v0 = 0;
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) > 0.0001f) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x5C) != 0x40000;
    }
    if (var_v0 != 0) {
        var_f0 = atan2f(-M2C_FIELD(arg0, f32 *, 0x84), -M2C_FIELD(arg0, f32 *, 0x80));
    } else {
        temp_s0 = PmatLoWorld(M2C_FIELD(arg0, void **, 0x10));
        var_f0 = atan2f(M2C_FIELD(temp_s0, f32 *, 4), *PmatLoWorld(M2C_FIELD(arg0, void **, 0x10)));
    }
    func_00209818(M2C_FIELD(arg0, void **, 0x10) + 0xFD0, var_f0);
    temp_v1 = M2C_FIELD(arg0, void **, 0x40);
    if (temp_v1 != NULL) {
        if (M2C_FIELD(temp_v1, s32 *, 0) == 2) {
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10), SetVectorCylind__FP6VECTORfff(RadNormalize__Ff(M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0x1A8) + 3.1415927f), M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), void **, 4), f32 *, 0x1C), 0));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
            M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf1, $vf2 */);
            SetJumperTarget(M2C_FIELD(M2C_FIELD(arg0, void **, 0x40), s32 *, 8), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */));
        }
    }
    func_0020AB68(M2C_FIELD(arg0, void **, 0x10), 0, 0, g_2a2dd0);
    if (M2C_FIELD(arg0, s32 *, 0x30) == 0) {
        func_001EEFC0(arg0);
    }
    PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
    ReplaceSwHitFx(&B_003DD490, 1, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), M2C_FIELD(arg0, void **, 0x10));
    M2C_FIELD(arg0, f32 *, 0xB0) = 3.4028235e38f;
    M2C_FIELD(arg0, f32 *, 0xB4) = 3.4028235e38f;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xF04) = 0;
    if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x334) != 0) {
        temp_v0 = PpoSwFocusBase(&B_003DD490);
        var_f0_2 = g_2dded0;
        if (temp_v0 != 0) {
            if (func_001A6AF8(M2C_FIELD(arg0, s32 *, 0x50), temp_v0) != 0) {
                if ((temp_v0 == g_2f7900) || (var_f0_2 = g_2dded0, ((M2C_FIELD(arg0, s32 *, 0x5C) & 0x40000) != 0))) {
                    TriggerJoyRumbleRumk__FP3JOY4RUMKf(&B_002DFC00, 3, 0x3E19999A);
                    M2C_FIELD(arg0, f32 *, 0xB0) = (f32) (g_2dded0 + 0.050000004f);
                    goto block_17;
                }
            } else {
block_17:
                var_f0_2 = g_2dded0;
            }
        }
        M2C_FIELD(arg0, f32 *, 0xB4) = (f32) (var_f0_2 + 0.13333334f);
    }
}
