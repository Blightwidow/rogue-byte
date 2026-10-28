#include "m2c_macros.h"

M2C_UNK CRef_ConstructVectorValue(void *, M2C_UNK); /* extern */
M2C_UNK CRef_CopyConstruct(s32, void *);            /* extern */
M2C_UNK CRef_Destruct(void *);                      /* extern */

s32 RefOpVectorCrossProduct(s32 arg0, void *arg2) {
    char sp[0x400];
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf1 */);
    CRef_ConstructVectorValue(sp, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    CRef_CopyConstruct(arg0, sp);
    CRef_Destruct(sp);
    return arg0;
}
