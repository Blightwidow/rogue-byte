#include "m2c_macros.h"

s32 ConvertAloVec(M2C_UNK, M2C_UNK *, M2C_UNK);     /* extern */
f32 GLimitLm__FP2LMf(M2C_UNK *, f32);               /* extern */
M2C_UNK PosLoWorld(s32);                            /* extern */
s32 PpoSwFocus(M2C_UNK *, s128);                    /* extern */
f32 atan2f(f32, s32);                               /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK g_2bbb60;
extern M2C_UNK g_2ddfa0;

f32 CalculateVolPan(s32 arg0, s128 arg1, void *arg2, f32 *arg3) {
    f32 *temp_s1;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 var_f2;
    s32 temp_v0;

    temp_s1 = M2C_ERROR(/* Read from unset register $t0 */);
    temp_v0 = PpoSwFocus(&B_003DD490, arg1);
    if (temp_v0 == 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($v0) */);
    } else {
        PosLoWorld(temp_v0);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    temp_f0 = M2C_FIELD(arg2, f32 *, 4);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    var_f0 = GLimitLm__FP2LMf(&g_2bbb60, (temp_f0 - M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */)) / (temp_f0 - M2C_FIELD(arg2, f32 *, 0)));
    temp_f1 = var_f0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
    if (arg3 != NULL) {
        *arg3 = temp_f1;
    }
    if (temp_s1 != NULL) {
        var_f0 = 0.0f;
        if (temp_f1 > 0.0f) {
            var_f2 = atan2f(-M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), ConvertAloVec(0, &g_2ddfa0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */)));
            temp_f1_2 = M2C_FIELD(arg2, f32 *, 0);
            if (M2C_FIELD(arg2, f32 *, 4) < temp_f1_2) {
                var_f2 += 3.1415927f;
            }
            *temp_s1 = temp_f1_2;
            return var_f2 * 57.295776f;
        }
        *temp_s1 = 0.0f;
        /* Duplicate return node #13. Try simplifying control flow for better match */
        return var_f0;
    }
    return var_f0;
}
