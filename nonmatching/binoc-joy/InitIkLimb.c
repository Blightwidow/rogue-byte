#include "m2c_macros.h"

s128 ConvertXfVec(M2C_UNK, s32, s128);              /* extern */
f32 RadBetweenVectors__FP6VECTORN20(M2C_UNK, M2C_UNK, s32, s32); /* extern */

void InitIkLimb(void *arg0) {
    void *temp_a0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 4);
    temp_a0 = M2C_FIELD(arg0, void **, 8);
    M2C_FIELD(arg0, s128 *, 0x10) = (s128) M2C_FIELD(temp_a1, s128 *, 0);
    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xb0($s0) */);
    M2C_FIELD(arg0, s128 *, 0x20) = (s128) M2C_FIELD(temp_a1, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x30) = (s128) M2C_FIELD(temp_a1, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x40) = (s128) M2C_FIELD(temp_a1, s128 *, 0x30);
    M2C_FIELD(arg0, s128 *, 0x50) = (s128) M2C_FIELD(temp_a0, s128 *, 0);
    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_FIELD(temp_a0, s128 *, 0x10);
    M2C_FIELD(arg0, s128 *, 0x70) = (s128) M2C_FIELD(temp_a0, s128 *, 0x20);
    M2C_FIELD(arg0, s128 *, 0x80) = (s128) M2C_FIELD(temp_a0, s128 *, 0x30);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($a3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($a3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($a3) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($t0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($a0) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf6x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf6y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf6z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf5, $vf0w */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x70($a1) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf5, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf5, $vf3z */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf3, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf4, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf6, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf4, $vf4y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf4, $vf6, $vf4z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf4, $vf0, $q */);
    M2C_FIELD(arg0, s32 *, 0xC4) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */);
    M2C_FIELD(arg0, s32 *, 0xC0) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
    M2C_FIELD(arg0, f32 *, 0xC8) = RadBetweenVectors__FP6VECTORN20(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */), arg0 + 0x90, M2C_FIELD(arg0, s32 *, 0xC) + 0x40);
    M2C_FIELD(arg0, s128 *, 0x90) = ConvertXfVec(0, M2C_FIELD(M2C_FIELD(arg0, void **, 8), s32 *, 0xA0), M2C_FIELD(arg0, s128 *, 0x90));
}
