#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(); /* extern */
M2C_UNK ConvertXfVec();           /* extern */
s32 CploFindSwObjectsByClass(); /* extern */
M2C_UNK DecomposeRotateMatrixEuler(); /* extern */
s32 FGadgetObjIsKindB();              /* extern */
M2C_UNK FadeAloOut();                /* extern */
M2C_UNK PosLoWorld();                         /* extern */
M2C_UNK RecalcSwOxfFilterForObject(); /* extern */
M2C_UNK SetSmaGoalIfReachable();            /* extern */
M2C_UNK SetSoCnstrForce();           /* extern */
M2C_UNK SetSoCnstrTorque();          /* extern */
s32 func_0012DC18(); /* extern */
M2C_UNK func_0012E460();                      /* extern */
M2C_UNK func_001A58D0();    /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002C4398;
extern s128 g_2a2dc0;
extern f32 g_2dded0;
extern void *g_2e1e40;

void SetGadgetObjState(void *arg0, s32 arg1) {
    char sp[0x400];
    M2C_UNK sp40;
    M2C_UNK sp50;
    f32 sp8;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    void *sp60;
    f32 temp_v0_7;
    f32 var_f20;
    s32 temp_a0_2;
    s32 temp_s0;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_s1;
    void **var_s4;
    void *temp_a0;
    void *temp_a1;
    void *temp_s0_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v0_5;
    void *temp_v1_2;
    void *temp_v1_3;
    void *var_s3;

    temp_s0 = M2C_FIELD(arg0, s32 *, 0x150);
    if (arg1 != temp_s0) {
        M2C_FIELD(arg0, s32 *, 0x150) = arg1;
        M2C_FIELD(arg0, s32 *, 0x158) = -1;
        M2C_FIELD(arg0, f32 *, 0x154) = (f32) g_2dded0;
        func_0012E460(arg0 + 0x180);
        func_0012E460(arg0 + 0x17C);
        if ((temp_s0 == 0) || (temp_s0 == 4)) {
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
        switch (temp_v1) {                          /* irregular */
        case 0:
            SetSoCnstrForce(arg0, 0);
            SetSoCnstrTorque(arg0, 0);
            temp_v1_2 = M2C_FIELD(arg0, void **, 0x58);
            temp_v0 = temp_v1_2 + 0xB0;
            M2C_FIELD(temp_v0, s32 *, 4) = 0;
            M2C_FIELD(temp_v0, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_2, s32 *, 0xB0) = 0;
            temp_a0 = M2C_FIELD(arg0, void **, 0x5C);
            temp_v0_2 = temp_a0 + 0xB0;
            M2C_FIELD(temp_v0_2, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_2, s32 *, 8) = 0;
            M2C_FIELD(temp_a0, s32 *, 0xB0) = 0;
            DecomposeRotateMatrixEuler(M2C_FIELD(arg0, void **, 0x5C));
            M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */);
            M2C_ERROR(/* unknown instruction: por $t1, $zero, $s0 */);
            M2C_ERROR(/* unknown instruction: por $t1, $zero, $s1 */);
            M2C_FIELD(arg0, s32 *, 0x180) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x58), 0, 7);
            M2C_FIELD(arg0, s32 *, 0x17C) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x5C), 0, 7);
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
            break;
        case 2:
            SetSoCnstrForce(arg0, 1);
            SetSoCnstrTorque(arg0, 1);
            temp_a1 = M2C_FIELD(arg0, void **, 0x58);
            temp_v0_3 = temp_a1 + 0xB0;
            M2C_FIELD(temp_v0_3, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_3, s32 *, 8) = 0;
            M2C_FIELD(temp_a1, s32 *, 0xB0) = 0;
            temp_v1_3 = M2C_FIELD(arg0, void **, 0x5C);
            temp_v0_4 = temp_v1_3 + 0xB0;
            M2C_FIELD(temp_v0_4, s32 *, 4) = 0;
            M2C_FIELD(temp_v0_4, s32 *, 8) = 0;
            M2C_FIELD(temp_v1_3, s32 *, 0xB0) = 0;
            if (FGadgetObjIsKindB(arg0, temp_a1) != 0) {
                temp_v0_5 = M2C_FIELD(arg0, void **, 0x5C);
                if (temp_v0_5 != NULL) {
                    ConvertXfVec(0, M2C_FIELD(temp_v0_5, s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x190));
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf2, $vf3z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf3, $vf0, $q */);
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf3x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf1, $q */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xf0($sp) */);
                    ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0xA0), g_2a2dc0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xf0($sp) */);
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf2, $q */);
                    BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */));
                    sp10 = sp40;
                    sp20 = sp50;
                    DecomposeRotateMatrixEuler(sp, sp30, sp30);
                    M2C_ERROR(/* unknown instruction: por $t1, $zero, $v0 */);
                    M2C_FIELD(arg0, s32 *, 0x17C) = func_0012DC18(arg0, M2C_FIELD(arg0, void **, 0x5C), 0, 7);
                }
            }
            break;
        case 1:
            func_001A58D0(arg0, 0, 0xF);
            SetSoCnstrForce(arg0, 0);
            if (M2C_FIELD(arg0, s32 *, 0x15C) != 0x29) {
                SetSoCnstrTorque(arg0, 0);
            } else {
                SetSoCnstrTorque(arg0, 1);
                temp_v0_6 = CploFindSwObjectsByClass(&B_003DD490, 0x105, 0x38, 0);
                var_f20 = 3.4028235e38f;
                var_s3 = g_2e1e40;
                if (temp_v0_6 > 0) {
                    var_s4 = &sp60;
                    var_s1 = temp_v0_6;
                    do {
                        temp_s0_2 = *var_s4;
                        PosLoWorld(temp_s0_2);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xe0($sp) */);
                        PosLoWorld(arg0);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xe0($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
                        sp8 *= 2.0f;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        temp_v0_7 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                        var_s1 -= 1;
                        if (temp_v0_7 < var_f20) {
                            var_f20 = temp_v0_7;
                            var_s3 = temp_s0_2;
                        }
                        var_s4 += 4;
                    } while (var_s1 != 0);
                }
                M2C_FIELD(arg0, void **, 0x160) = var_s3;
            }
            break;
        case 4:
            RecalcSwOxfFilterForObject(&B_003DD490, arg0);
            FadeAloOut(arg0, 0x3E800000);
            break;
        }
        temp_a0_2 = M2C_FIELD(arg0, s32 *, 0x168);
        if (temp_a0_2 != 0) {
            temp_v1_4 = M2C_FIELD(arg0, s32 *, 0x150);
            if (temp_v1_4 >= 0) {
                SetSmaGoalIfReachable(temp_a0_2, *((temp_v1_4 * 4) + &D_002C4398));
            }
        }
    }
}
