#include "m2c_macros.h"

M2C_UNK AddSoXa__FP2SOP2XA(void *, void *);         /* extern */
s32 CploFindSwObjectsByClass(M2C_UNK *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 FCanSetGuardMode(void *, M2C_UNK);              /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK PostGuardStunCommand(void *, M2C_UNK);      /* extern */
M2C_UNK RemoveSoXa__FP2SOP2XA(void *, void *);      /* extern */
M2C_UNK SetGadgetObjState(void *, s32);             /* extern */
M2C_UNK func_0012D108(s32, s128);                   /* extern */
M2C_UNK func_0017A8C8(s32, M2C_UNK);                /* extern */
s32 func_00205458(void *, M2C_UNK);                 /* extern */
extern M2C_UNK B_003DD490;
extern f32 D_FLT_002C43F4;
extern s128 RO_002A2DE0;

void SetDyshState(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp80;
    f32 sp88;
    s128 spA0;
    f32 temp_v0_3;
    f32 var_f20;
    s128 var_v0;
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s3;
    void **var_s1;
    void *temp_a0;
    void *temp_a0_3;
    void *temp_s0;
    void *temp_v0_4;
    void *temp_v1_2;
    void *var_s2;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if (arg1 != temp_v1) {
        if (temp_v1 == 5) {
            temp_a0 = M2C_FIELD(arg0, void **, 0x1B4);
            if (temp_a0 != NULL) {
                RemoveSoXa__FP2SOP2XA(temp_a0, arg0 + 0x1B8);
                temp_v0 = func_00205458(M2C_FIELD(arg0, void **, 0x1B4), 0xB0);
                if (temp_v0 != 0) {
                    func_0017A8C8(temp_v0, 2);
                }
                temp_a0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x1B4), s32 *, 0xFC4);
                if (temp_a0_2 != 0) {
                    func_0012D108(temp_a0_2, RO_002A2DE0);
                }
                M2C_FIELD(arg0, void **, 0x1B4) = NULL;
            }
        }
        SetGadgetObjState(arg0, arg1);
        if (arg1 == 5) {
            temp_a0_3 = M2C_FIELD(arg0, void **, 0x1B0);
            if (temp_a0_3 != NULL) {
                var_v0 = PosLoWorld(temp_a0_3);
            } else {
                var_v0 = PosLoWorld(arg0);
            }
            spA0 = var_v0;
            temp_v0_2 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x38, 0);
            var_f20 = 400.0f;
            var_s2 = NULL;
            if (temp_v0_2 > 0) {
                var_s3 = temp_v0_2;
                var_s1 = sp;
                do {
                    temp_s0 = *var_s1;
                    if (FCanSetGuardMode(temp_s0, 0xB) == 0) {
                        var_s3 -= 1;
                    } else {
                        PosLoWorld(temp_s0);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                        var_s3 -= 1;
                        if (temp_v0_3 < var_f20) {
                            var_f20 = temp_v0_3;
                            var_s2 = temp_s0;
                        }
                    }
                    var_s1 += 4;
                } while (var_s3 != 0);
            }
            if (var_s2 != NULL) {
                M2C_FIELD(arg0, void **, 0x1B4) = var_s2;
                M2C_FIELD(arg0, void **, 0x1B8) = arg0;
                M2C_FIELD(arg0, void **, 0x1BC) = var_s2;
                AddSoXa__FP2SOP2XA(var_s2, arg0 + 0x1B8);
                temp_v1_2 = M2C_FIELD(var_s2, void **, 0xC);
                M2C_FIELD(temp_v1_2, M2C_UNK (**)(void *), 0x10C)(var_s2 + M2C_FIELD(temp_v1_2, s16 *, 0x108));
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x80($sp) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf1, $vf2, $vf3x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x80($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x90($sp) */);
                sp88 = D_FLT_002C43F4;
                temp_v0_4 = M2C_FIELD(var_s2, void **, 0xC);
                M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, s128), 0x11C)(var_s2 + M2C_FIELD(temp_v0_4, s16 *, 0x118), sp80);
                PostGuardStunCommand(var_s2, 0);
            }
        }
    }
}
