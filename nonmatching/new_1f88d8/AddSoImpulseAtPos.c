#include "m2c_macros.h"

M2C_UNK ConvertXfVec(M2C_UNK, s32, M2C_UNK, s128);  /* extern */
M2C_UNK DvFromImpulse(M2C_UNK);                     /* extern */
M2C_UNK DwFromImpulseAtPos(void *, M2C_UNK, M2C_UNK); /* extern */

s32 AddSoImpulseAtPos(void *arg0) {
    void *temp_s0;
    void *temp_s0_2;

    M2C_ERROR(/* unknown instruction: por $s0, $zero, $a2 */);
    M2C_ERROR(/* unknown instruction: por $s1, $zero, $a1 */);
    DvFromImpulse(M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
    M2C_ERROR(/* unknown instruction: por $s2, $zero, $v0 */);
    DwFromImpulseAtPos(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s1 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */));
    temp_s0 = M2C_FIELD(arg0, void **, 0x58);
    M2C_ERROR(/* unknown instruction: por $s1, $zero, $v0 */);
    ConvertXfVec(0, M2C_FIELD(temp_s0, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s2 */), M2C_FIELD(temp_s0, s128 *, 0xF0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s0) */);
    temp_s0_2 = M2C_FIELD(arg0, void **, 0x5C);
    ConvertXfVec(0, M2C_FIELD(temp_s0_2, s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s1 */), M2C_FIELD(temp_s0_2, s128 *, 0xF0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xf0($s0) */);
    return M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
}
