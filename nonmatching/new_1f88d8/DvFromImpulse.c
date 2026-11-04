#include "m2c_macros.h"

M2C_UNK ApplyConstrLocal(void *, s32, M2C_UNK);     /* extern */

void DvFromImpulse(void *arg0) {
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    ApplyConstrLocal(M2C_FIELD(arg0, void **, 0xE8) + 0xB0, M2C_FIELD(arg0, s32 *, 0x58), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */));
}
