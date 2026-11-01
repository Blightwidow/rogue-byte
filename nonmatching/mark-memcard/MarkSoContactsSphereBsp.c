#include "m2c_macros.h"

s32 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(s128, s32, M2C_UNK, f32); /* extern */
M2C_UNK PxpAdd(s32, void *, s32, s128, M2C_UNK, s32); /* extern */
M2C_UNK func_002564B8(M2C_UNK *);                   /* extern */

void MarkSoContactsSphereBsp(s32 arg0, void *arg1, s32 arg2) {
    M2C_UNK sp10;
    M2C_UNK spC10;
    M2C_UNK spC20;
    s128 spC30;
    s128 spC40;
    s32 var_s1;
    void *var_s0;

    var_s1 = CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_FIELD(M2C_FIELD(arg1, void **, 0), s128 *, 0x70), arg2, 0x7FFFFFFF, M2C_FIELD(arg1, f32 *, 8)) - 1;
    if (var_s1 >= 0) {
        var_s0 = &sp10 + (var_s1 * 0x30);
        do {
            var_s1 -= 1;
            spC30 = M2C_FIELD(var_s0, s128 *, 0);
            spC40 = M2C_FIELD(var_s0, s128 *, 0x10);
            func_002564B8(&spC10);
            func_002564B8(&spC20);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc40($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0xc30($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf1, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmsubw.x $vf2, $vf1, $vf3w */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc10($sp) */);
            var_s0 -= 0x30;
            PxpAdd(arg0, arg1, arg2, spC30, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */), M2C_ERROR(/* Read from unset register $t1 */));
        } while (var_s1 >= 0);
    }
}
