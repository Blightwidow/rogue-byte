#include "m2c_macros.h"

s32 FGoalAnimDone();                             /* extern */
M2C_UNK PosLoWorld();                   /* extern */
M2C_UNK func_0017E0E0();                      /* extern */
M2C_UNK func_0017E278();             /* extern */
s128 func_001C1EC0();                   /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8();                          /* extern */
s32 func_00208B38();                     /* extern */
f32 func_00208BB0();                          /* extern */
s32 func_00209098();                          /* extern */
extern f32 D_FLT_002BE760;
extern f32 D_FLT_002BE764;
extern f32 D_FLT_002BE768;
extern M2C_UNK g_2dded0;

void func_0017DE50(void *arg0) {
    f32 temp_f0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_s2;
    void *temp_a1;
    void *temp_v1_2;

    func_001EEF98();
loop_19:
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x30);
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x30);
    if (func_001EF0A8(arg0) == 0) {
        switch (temp_v1) {                          /* irregular */
        case 0:
            if (FGoalAnimDone(M2C_FIELD(arg0, s32 *, 0x18)) != 0) {
                func_0017E278(arg0, 1);
            }
            break;
        case 1:
            if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) != 0) {
                func_0017E278(arg0, 2);
            } else {
                temp_f0 = M2C_FIELD(arg0, f32 *, 0x40) - M2C_FIELD(&g_2dded0, f32 *, 4);
                M2C_FIELD(arg0, f32 *, 0x40) = temp_f0;
                if (temp_f0 <= 0.0f) {
                    temp_a1 = M2C_FIELD(arg0, void **, 0x10);
                    temp_v1_2 = M2C_FIELD(temp_a1, void **, 0xC);
                    temp_v0 = M2C_FIELD(temp_v1_2, s32 (**)(void *, void *), 0x2C4)(temp_a1 + M2C_FIELD(temp_v1_2, s16 *, 0x2C0), temp_a1);
                    if ((temp_v0 == M2C_FIELD(arg0, void **, 0x38)) && (func_00208B38(M2C_FIELD(arg0, void **, 0x10), temp_v0) != 0)) {
                        M2C_FIELD(arg0, f32 *, 0x40) = func_00208BB0(M2C_FIELD(arg0, void **, 0x10));
                    } else {
                        func_0017E278(arg0, -1);
                    }
                }
            }
            break;
        case 2:
            if (func_00209098(M2C_FIELD(arg0, void **, 0x10)) == 0) {
                func_0017E278(arg0, 1);
            }
            break;
        }
        if (M2C_FIELD(arg0, s32 *, 0x30) != temp_s0) {
            goto loop_19;
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x30) == 1) {
        if (D_FLT_002BE760 < (M2C_FIELD(&g_2dded0, f32 *, 0) - M2C_FIELD(arg0, f32 *, 0x3C))) {
            temp_s0_2 = M2C_FIELD(arg0, s32 *, 0x18) + 0x40;
            var_s2 = 0;
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10), func_001C1EC0(temp_s0_2, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if ((M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < D_FLT_002BE764) || (PosLoWorld(M2C_FIELD(arg0, void **, 0x10)), M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */), M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */), PosLoWorld(M2C_FIELD(arg0, void **, 0x38)), M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */), M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */), M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */), M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */), M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */), M2C_ERROR(/* unknown instruction: vwaitq */), M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */), (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < D_FLT_002BE768))) {
                var_s2 = 1;
            }
            if (var_s2 != 0) {
                func_0017E0E0(arg0);
            }
        }
    }
}
