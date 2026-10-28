#include "m2c_macros.h"

s32 ApplyConstrLocal(void *arg0, void *arg1) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x10);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf7 */);
    if (temp_v1 != 2) {
        if (temp_v1 < 3) {
            if (temp_v1 != 1) {
                return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
            }
            if (M2C_FIELD(arg1, s32 *, 0xA0) != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($a0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($a1) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf4, $vf3z */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf6, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf6, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf7, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
            } else {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf7, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
            }
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf7, $vf2 */);
            var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
            /* Duplicate return node #13. Try simplifying control flow for better match */
            return var_v0;
        }
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
        if (temp_v1 == 3) {
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf7, $vf0, $vf0 */);
            return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
        }
        return var_v0;
    }
    if (M2C_FIELD(arg1, s32 *, 0xA0) != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($a0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($v0) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($a1) */);
        M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf2x */);
        M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
        M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf4, $vf2z */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf6, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf6, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf7, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf4, $vf3z */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf7, $vf1, $vf3x */);
        return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf7, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf7, $vf1, $vf2x */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf7 */);
}
