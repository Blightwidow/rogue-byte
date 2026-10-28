#include "m2c_macros.h"

M2C_UNK CRef_ConstructVectorValue(s32, M2C_UNK, s128, s128); /* extern */

s32 RefOpNearClipCenter(s32 arg0) {
    s128 temp_a2;

    M2C_ERROR(/* unknown instruction: pextlw $a2, $a0, $a2 */);
    M2C_ERROR(/* unknown instruction: pcpyld $a2, $a0, $a2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x60($v0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v1) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v1) */);
    temp_a2 = M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf5 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf5x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf5y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf5z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf3, $vf0w */);
    CRef_ConstructVectorValue(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf5 */), temp_a2, temp_a2);
    return arg0;
}
