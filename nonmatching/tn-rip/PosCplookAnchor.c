#include "m2c_macros.h"

s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
s128 PosLoWorld(s32);                               /* extern */

s128 PosCplookAnchor(s32 *arg0) {
    s128 sp10;

    sp10 = PosLoWorld(*arg0);
    if (FIsBasicDerivedFrom(*arg0, 0x34) != 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
    }
    return sp10;
}
