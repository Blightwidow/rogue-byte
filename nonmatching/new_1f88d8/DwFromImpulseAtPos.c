#include "m2c_macros.h"

M2C_UNK DwFromTorque(s32, M2C_UNK);                 /* extern */
M2C_UNK PosLoWorld(s128, s128);                     /* extern */

void DwFromImpulseAtPos(s32 arg0, s128 arg1, s128 arg2) {
    PosLoWorld(arg1, arg2);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf2, $vf2, $vf1 */);
    DwFromTorque(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
}
