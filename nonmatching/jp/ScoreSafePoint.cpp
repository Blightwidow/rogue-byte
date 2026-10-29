#include "m2c_macros.h"
extern "C" {

M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK IntersectSwBoundingSphere(M2C_UNK *, s128, M2C_UNK *, s32, f32); /* extern */
s32 PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(M2C_UNK, s128, s128, s32); /* extern */
s128 func_0019F3F8(void *, M2C_UNK);                /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK FFilterOxa;
extern f32 g_2bf944;
extern M2C_UNK g_2bf9d0;
extern M2C_UNK g_2bf9e0;

f32 ScoreSafePoint(void **arg0, void *arg1, s32 arg2, void **arg3) {
    char sp[0x90];
    M2C_UNK sp58;
    M2C_UNK sp70;
    M2C_UNK unksp18;
    M2C_UNK unksp28;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    s32 sp90;
    s32 sp94;
    s128 spA0;
    f32 temp_f0;
    f32 temp_v0;
    f32 var_f20;
    s32 var_a2;
    u32 var_s0;
    void **var_a3;

    var_f20 = 0.0f;
    spA0 = func_0019F3F8(*arg0, 0);
    if (M2C_FIELD(arg1, s32 *, 8) != 0) {
        CStackFrame_Construct(sp);
        IntersectSwBoundingSphere(&B_003DD490, spA0, &FFilterOxa, M2C_FIELD(*arg0, s32 *, 0xEC), g_2bf944);
        sp10 = spA0;
        sp20 = spA0;
        unksp18 += 125.0f;
        unksp28 -= 175.0f;
        if ((PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp20, sp90) == 0) || (sp70 == 0.0f) || (sp58 < 0.7f)) {
            var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
        } else {
            spA0 = sp30;
        }
        sp20 = spA0;
        sp10 = spA0;
        unksp18 += 180.0f;
        unksp28 += 5.0f;
        if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp20, sp90) != 0) {
            var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
        }
        var_s0 = 0;
loop_10:
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s1) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xa0($sp) */);
        M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf1 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x20($sp) */);
        unksp18 += 50.0f;
        unksp28 -= 30.0f;
        var_s0 += 1;
        if (PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, sp10, sp20, sp90) != 0) {
            if (var_s0 < 8U) {
                goto loop_10;
            }
        } else {
            var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
        }
        CStackFrame_Destructor(sp, 2);
    }
    if (arg2 > 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xa0($sp) */);
        var_a3 = arg3;
        var_a2 = arg2;
        do {
            if (*var_a3 != *arg0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                temp_f0 = M2C_FIELD(&g_2bf9d0, f32 *, 0) + (temp_v0 * (M2C_FIELD(&g_2bf9d0, f32 *, 4) + (temp_v0 * M2C_FIELD(&g_2bf9d0, f32 *, 8))));
                if (temp_f0 < M2C_FIELD(&g_2bf9e0, f32 *, 0)) {

                } else if (M2C_FIELD(&g_2bf9e0, f32 *, 4) < temp_f0) {

                }
                var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
            }
            var_a2 -= 1;
            var_a3 += 4;
        } while (var_a2 != 0);
    }
    return var_f20;
}
}
