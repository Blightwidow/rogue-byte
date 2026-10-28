#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *); /* extern */
s32 FFindPathzoneCrv(s32, M2C_UNK, s128, void *);   /* extern */
M2C_UNK GoalGoto_SetState(void *, s32);             /* extern */
M2C_UNK MeasureCrv(void *);                         /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK func_0017D8A8(void *);                      /* extern */
M2C_UNK func_001C1EC0(void *, M2C_UNK);             /* extern */
s32 func_001EF0A8();                                /* extern */
M2C_UNK func_002562A8(void *);                      /* extern */
extern void *B_003E1A5C;
extern f32 g_2dded0;

void GoalGoto_Replan(void *arg0) {
    char sp[0x400];
    M2C_UNK sp28;
    s128 sp0;
    s128 sp10;
    M2C_UNK sp20;
    f32 sp30;
    s128 temp_a2;
    s32 var_a0;
    s32 var_s4;
    s32 var_v1;
    void *temp_a0;
    void *temp_s1;
    void *temp_s1_2;
    void *temp_v0;
    void *var_v1_2;

    if (M2C_FIELD(arg0, s32 *, 0x30) != -1) {
        if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xFE8) & 2) {
            if (func_001EF0A8() == 0) {
                GoalGoto_SetState(arg0, 0);
                func_0017D8A8(arg0);
                func_002562A8(sp);
                if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
                    temp_s1 = M2C_FIELD(arg0, void **, 0xB8);
                    sp0 = M2C_FIELD(temp_s1, s128 *, 0x60);
                    sp10 = M2C_FIELD(temp_s1, s128 *, 0x70);
                    var_s4 = 2;
                    if (M2C_FIELD(temp_s1, s32 *, 0x120) == 0) {
                        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
                        M2C_ERROR(/* unknown instruction: por $s2, $zero, $v0 */);
                        func_001C1EC0(temp_s1 + 0x60, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */));
                        M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
                        func_001C1EC0(temp_s1 + 0x80, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */));
                        ClosestPointOnSegment(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), &sp20);
                        var_v1 = 0;
                        if ((sp30 > 0.0f) && (M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($sp) */), (sp30 < 1.0f))) {
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $s2, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 50.0f) {
                                if (fabsf(sp28 - M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $s2 */)) < 300.0f) {
                                    var_v1 = 1;
                                }
                            }
                        }
                        var_s4 = (var_v1 != 0) ? 3 : 2;
                    }
                } else {
                    var_s4 = 1;
                    sp0 = M2C_FIELD(arg0, s128 *, 0x60);
                    sp10 = M2C_FIELD(arg0, s128 *, 0x70);
                }
                if (var_s4 > 0) {
                    if (var_s4 < 3) {
                        temp_a0 = M2C_FIELD(arg0, void **, 0x10);
                        temp_s1_2 = M2C_FIELD(temp_a0, void **, 0x294);
                        PosLoWorld(temp_a0);
                        func_001C1EC0(sp, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
                        temp_a2 = M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */);
                        if (M2C_FIELD(arg0, s32 *, 0xBC) != 0) {
                            M2C_FIELD(temp_s1_2, s32 *, 0xE8) = 2;
                            M2C_FIELD(M2C_FIELD(temp_s1_2, void **, 0xF4), s128 *, 0) = (s128) M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
                            M2C_FIELD(M2C_FIELD(temp_s1_2, void **, 0xF4), s128 *, 0x10) = temp_a2;
                            MeasureCrv(temp_s1_2);
                        } else {
                            temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xE8);
                            var_v1_2 = NULL;
                            if (temp_v0 != NULL) {
                                var_v1_2 = M2C_FIELD(temp_v0, void **, 0xDC);
                            }
                            var_a0 = 0;
                            if (var_v1_2 != NULL) {
                                var_a0 = M2C_FIELD(var_v1_2, s32 *, 0x10);
                            }
                            if (FFindPathzoneCrv(var_a0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), temp_a2, temp_s1_2) == 0) {
                                var_s4 = 5;
                                M2C_FIELD(arg0, s128 *, 0x80) = sp0;
                                M2C_FIELD(arg0, s128 *, 0x90) = sp10;
                            }
                        }
                    }
                }
                GoalGoto_SetState(arg0, var_s4);
                M2C_FIELD(arg0, f32 *, 0xA0) = (f32) g_2dded0;
                M2C_FIELD(arg0, s32 *, 0xA4) = (s32) M2C_FIELD(B_003E1A5C, s32 *, 0x28);
            }
        }
    }
}
