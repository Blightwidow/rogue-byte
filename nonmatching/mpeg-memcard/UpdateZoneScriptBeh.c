#include "m2c_macros.h"

s32 FIsGuardInSgs(void *, M2C_UNK);                 /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK SetZoneScriptState(void *, M2C_UNK);        /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(void *);                          /* extern */
void *func_00205458(void *, M2C_UNK);               /* extern */
s32 func_00227C90(s32, M2C_UNK);                    /* extern */
extern f32 g_2dded0;
extern void *g_2e1e40;

void UpdateZoneScriptBeh(void *arg0) {
    f32 temp_a0;
    f32 temp_f3;
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f20;
    s32 temp_s2;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s0_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;

    func_001EEF98();
loop_11:
    if (func_001EF0A8(arg0) == 0) {
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x30);
        switch (temp_s2) {                          /* irregular */
        case 0:
            temp_s0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xF64);
            PosLoWorld(g_2e1e40);
            if (func_00227C90(M2C_FIELD(temp_s0, s32 *, 0xEC), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) == 0) {
                SetZoneScriptState(arg0, 1);
            }
            break;
        case 1:
            temp_s0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), void **, 0xF64);
            PosLoWorld(g_2e1e40);
            if (func_00227C90(M2C_FIELD(temp_s0_2, s32 *, 0xE8), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */)) != 0) {
                SetZoneScriptState(arg0, 0);
            } else if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), f32 *, 0x1088) < (g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34))) {
                SetZoneScriptState(arg0, 2);
            }
            break;
        }
        if (temp_s2 != M2C_FIELD(arg0, s32 *, 0x30)) {
            goto loop_11;
        }
    }
    if ((M2C_FIELD(arg0, s32 *, 0x30) == 0) && (FIsGuardInSgs(M2C_FIELD(arg0, void **, 0x10), 9) != 0)) {
        PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        PosLoWorld(g_2e1e40);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        temp_v1 = M2C_FIELD(arg0, void **, 0x10);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
        temp_v0 = temp_v1 + 0x1070;
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_a0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
        temp_f4 = M2C_FIELD(temp_v1, f32 *, 0x1080);
        temp_f3 = M2C_FIELD(temp_v1, f32 *, 0x1070) + (temp_a0 * (M2C_FIELD(temp_v0, f32 *, 4) + (temp_a0 * M2C_FIELD(temp_v0, f32 *, 8))));
        temp_f5 = M2C_FIELD(temp_v1, f32 *, 0x1084);
        if (temp_f3 < temp_f4) {
            var_f20 = temp_f4;
        } else {
            var_f20 = temp_f3;
            if (temp_f5 < temp_f3) {
                var_f20 = temp_f5;
            }
        }
        temp_s0_3 = func_00205458(M2C_FIELD(arg0, void **, 0x10), 0xA7);
        temp_v0_2 = func_00205458(M2C_FIELD(arg0, void **, 0x10), 0xB8);
        if (temp_s0_3 != NULL) {
            M2C_FIELD(temp_s0_3, f32 *, 0xC4) = var_f20;
        } else if (temp_v0_2 != NULL) {
            M2C_FIELD(temp_v0_2, f32 *, 0x38) = var_f20;
        }
    }
}
