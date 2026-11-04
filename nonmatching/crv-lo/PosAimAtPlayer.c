#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK DecomposeSphere(M2C_UNK, f32 *, f32 *, f32 *); /* extern */
f32 GetSuck(M2C_UNK *);                             /* extern */
f32 *PmatLoWorld(void *);                           /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
void *PpoSwFocusBase(M2C_UNK *);                    /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, M2C_UNK, s32); /* extern */
f32 RadNormalize__Ff(f32);                          /* extern */
M2C_UNK SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(f32, f32, f32); /* extern */
M2C_UNK VecCombo__FG8VU_FLOATG9VU_VECTORT0T1(M2C_UNK, M2C_UNK, M2C_UNK, s128); /* extern */
M2C_UNK __8VU_FLOATf(s128 *, f32);                  /* extern */
M2C_UNK __9VU_VECTORRC6VECTOR(s128 *, M2C_UNK *);   /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(f32 *, M2C_UNK);   /* extern */
f32 atan2f(f32, f32);                               /* extern */
M2C_UNK func_001B44D8(s32 *, s32 *);                /* extern */
extern M2C_UNK B_002DE578;
extern M2C_UNK B_003DD490;
extern M2C_UNK D_002BDC60;
extern M2C_UNK D_002BDC80;
extern M2C_UNK D_FLT_002BDC70;
extern M2C_UNK D_FLT_002BDC90;
extern f32 D_FLT_002BDC98;
extern f32 D_FLT_002BDCA0;
extern f32 RO_FLT_002A513C;

s128 PosAimAtPlayer(s32 arg0, s128 arg1) {
    f32 saved_reg_f22;
    M2C_UNK sp14;
    M2C_UNK sp140;
    M2C_UNK sp18;
    f32 sp10;
    f32 sp20;
    f32 sp24;
    M2C_UNK sp40;
    M2C_UNK sp50;
    s128 spB0;
    s128 spC0;
    s128 spD0;
    s128 spE0;
    f32 spF0;
    f32 spF4;
    f32 spF8;
    s32 spFC;
    s32 sp100;
    s128 sp110;
    s128 sp130;
    f32 *temp_s0;
    f32 *var_s0;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_v0_2;
    f32 temp_v0_4;
    f32 var_f21;
    f32 var_f22;
    s32 temp_v0_3;
    s32 var_v0;
    u32 var_s1;
    void *temp_a1;
    void *temp_v0;

    var_f22 = saved_reg_f22;
    sp110 = arg1;
    temp_v0 = PpoSwFocusBase(&B_003DD490);
    PosLoWorld(temp_v0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f21 = GetSuck(&B_002DE578);
    PosLoWorld(temp_v0);
    temp_a1 = M2C_FIELD(temp_v0, void **, 0xC);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    sp130 = M2C_FIELD(temp_a1, s128 (**)(void *, void *, M2C_UNK), 0x10C)(temp_v0 + M2C_FIELD(temp_a1, s16 *, 0x108), temp_a1, M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf2 */));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    var_v0 = 1;
    if (!(D_FLT_002BDC98 < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        temp_f20 = 1.0f - temp_f21;
        __8VU_FLOATf(&spB0, temp_f20);
        __9VU_VECTORRC6VECTOR(&spC0, &D_002BDC60);
        __8VU_FLOATf(&spD0, temp_f21);
        __9VU_VECTORRC6VECTOR(&spE0, &D_002BDC80);
        VecCombo__FG8VU_FLOATG9VU_VECTORT0T1(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s3 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s2 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */), spE0);
        __as__6VECTORG9VU_VECTOR(&sp10, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        temp_f3 = (temp_f20 * M2C_FIELD(&D_FLT_002BDC70, f32 *, 0)) + (temp_f21 * M2C_FIELD(&D_FLT_002BDC90, f32 *, 0));
        temp_f2 = sp10 + (temp_v0_2 * (sp14 + (temp_v0_2 * sp18)));
        temp_f1 = (temp_f20 * M2C_FIELD(&D_FLT_002BDC70, f32 *, 4)) + (temp_f21 * M2C_FIELD(&D_FLT_002BDC90, f32 *, 4));
        sp20 = temp_f3;
        sp24 = temp_f1;
        if (temp_f2 < temp_f3) {

        } else if (temp_f1 < temp_f2) {

        }
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x130($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    } else {
        temp_s0 = PmatLoWorld(temp_v0);
        SetVectorCylind__FP6VECTORfff(atan2f(M2C_FIELD(temp_s0, f32 *, 4), *PmatLoWorld(temp_v0)), D_FLT_002BDC98, 0);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x120($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
    var_s1 = 0;
    DecomposeSphere(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf2 */), &spF0, &spF4, &spF8);
    CStackFrame_Construct(&sp40);
    func_001B44D8(&spFC, &sp100);
    var_f21 = RO_FLT_002A513C;
    var_s0 = &D_FLT_002BDCA0;
loop_11:
    temp_f0 = RadNormalize__Ff(spF0 + *var_s0);
    SetVectorSphere__FP6VECTORfff(temp_f0, spF4, spF8);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf4 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf3, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x150($sp) */);
    temp_v0_3 = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp110, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), spFC);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x150($sp) */);
    if (temp_v0_3 != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x110($sp) */);
    if (temp_v0_3 != 0) {
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_v0_4 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
        var_s1 += 1;
        if (var_f21 < temp_v0_4) {
            var_f21 = temp_v0_4;
            var_f22 = temp_f0;
        }
        var_s0 += 4;
        if (var_s1 < 0xBU) {
            goto loop_11;
        }
    } else {
        var_f22 = temp_f0;
    }
    SetVectorSphere__FP6VECTORfff(var_f22, spF4, spF8);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x110($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x140($sp) */);
    CStackFrame_Destructor(&sp40, 2);
    return sp140;
}
