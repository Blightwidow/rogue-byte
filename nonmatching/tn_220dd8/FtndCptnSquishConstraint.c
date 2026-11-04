#include "m2c_macros.h"

M2C_UNK func_002564B8();             /* extern */

f32 FtndCptnSquishConstraint(s128 arg1, void *arg3) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp20;
    s128 sp30;
    s128 temp_a3;

    sp20 = arg1;
    temp_a3 = M2C_FIELD(arg3, s128 *, 0x10);
    sp30 = temp_a3;
    func_002564B8(sp, temp_a3);
    func_002564B8(&sp10);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.x $acc, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: vmsubw.x $vf2, $vf1, $vf3w */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
    return M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
}
