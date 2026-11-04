#include "m2c_macros.h"

M2C_UNK CRef_ConstructVectorValue(void *, M2C_UNK); /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */

s32 RefOpVectorProjectNormal(s32 arg0, void *arg2) {
    char sp[0x400];
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
    CRef_ConstructVectorValue(sp, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
