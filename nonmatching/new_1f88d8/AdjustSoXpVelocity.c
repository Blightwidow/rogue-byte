#include "m2c_macros.h"

s128 DvFromImpulse(void *, M2C_UNK);                /* extern */
s128 DwFromImpulseAtPos(void *, s128, M2C_UNK);     /* extern */

void AdjustSoXpVelocity(void *arg0, s32 arg1, void *arg2) {
    s32 temp_s1;
    void *temp_s0;
    void *temp_s5;

    temp_s1 = M2C_ERROR(/* Read from unset register $t0 */);
    temp_s0 = M2C_FIELD(arg0, void **, 0xE8);
    if (temp_s0 != NULL) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x40($s2) */);
        if (temp_s1 != 0) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf2, $vf1x */);
        }
        temp_s5 = arg2 + (temp_s1 << 5);
        if (M2C_FIELD(temp_s0, s32 *, 0xC0) != 3) {
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            M2C_FIELD(temp_s5, s128 *, 0) = DvFromImpulse(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf2 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
        }
        if (M2C_FIELD(temp_s0, s32 *, 0xA0) != 3) {
            M2C_FIELD(temp_s5, s128 *, 0x10) = DwFromImpulseAtPos(arg0, M2C_FIELD(((temp_s1 << 6) + M2C_FIELD(arg2, s32 *, 0x50)), s128 *, 0x10), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */));
        }
    }
}
