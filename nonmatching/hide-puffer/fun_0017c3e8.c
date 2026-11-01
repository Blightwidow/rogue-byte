#include "m2c_macros.h"

M2C_UNK DecomposeCylind(M2C_UNK, void *, f32 *, M2C_UNK); /* extern */
s32 FCheckLm__FP2LMf(void *, f32);                  /* extern */
M2C_UNK FFindPathzoneCrv(s32, M2C_UNK, M2C_UNK, void *); /* extern */
f32 GetAlertPan(void *);                            /* extern */
M2C_UNK GoalFollowCrv_SetCrv(void *, void *, M2C_UNK); /* extern */
s128 PosLoWorld(void *);                            /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK func_0017BFF8(void *, s32, s128, f32);      /* extern */
M2C_UNK func_001EEF98();                            /* extern */
extern f32 D_FLT_002BE748;

void func_0017C3E8(void *arg0) {
    char sp[0x400];
    M2C_UNK sp0;
    f32 sp4;
    s128 sp10;
    f32 temp_f20;
    s32 var_s4;
    void *temp_a0;
    void *temp_s0;
    void *temp_s2;
    void *temp_s3;
    void *temp_s5;
    void *temp_v0;
    void *var_v1;

    func_001EEF98();
    var_v1 = NULL;
    if (M2C_FIELD(arg0, s32 *, 0x30) != 0) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x10);
        temp_v0 = M2C_FIELD(temp_a0, void **, 0xE8);
        temp_s3 = M2C_FIELD(temp_a0, void **, 0x294);
        if (temp_v0 != NULL) {
            var_v1 = M2C_FIELD(temp_v0, void **, 0xDC);
        }
        var_s4 = 0;
        if (var_v1 != NULL) {
            var_s4 = M2C_FIELD(var_v1, s32 *, 0x10);
        }
        temp_s2 = M2C_FIELD(temp_a0, void **, 0x3CC);
        temp_s0 = M2C_FIELD(temp_s2, void **, 0xC);
        temp_f20 = GetAlertPan(temp_s2);
        sp10 = PosLoWorld(temp_s0);
        temp_s5 = M2C_FIELD(arg0, void **, 0x18);
        if ((D_FLT_002BE748 < M2C_FIELD(temp_s5, f32 *, 0x70)) || (M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */), M2C_ERROR(/* unknown instruction: lqc2 $vf1, -0x10($v0) */), M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */), DecomposeCylind(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), sp, &sp4, 0), (M2C_FIELD(temp_s2, f32 *, 0x18) < fabsf(RadNormalize__Ff(sp0 - temp_f20)))) || (FCheckLm__FP2LMf(M2C_FIELD(arg0, void **, 0x10) + 0x324, sp4) == 0)) {
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10));
            M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
            func_0017BFF8(arg0, var_s4, sp10, temp_f20);
            FFindPathzoneCrv(var_s4, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), temp_s3);
            GoalFollowCrv_SetCrv(temp_s5, temp_s3, 0);
        }
    }
}
