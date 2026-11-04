#include "m2c_macros.h"

M2C_UNK ConvertAloPos(M2C_UNK, void *, M2C_UNK);    /* extern */
s32 PcgtPointInCbspQuick__FP4CBSPP6VECTOR(s32, M2C_UNK, M2C_UNK); /* extern */

s32 func_00227C90(void *arg0) {
    s32 var_v0;

    ConvertAloPos(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $a1 */));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x110($s0) */);
    var_v0 = 1;
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    if (!(M2C_FIELD(arg0, f32 *, 0x120) < M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */))) {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        return 0;
    }
    return PcgtPointInCbspQuick__FP4CBSPP6VECTOR(M2C_FIELD(arg0, s32 *, 0xEC), 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */)) != 0;
}
