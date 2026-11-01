#include "m2c_macros.h"

M2C_UNK AdjustSoXpVelocity(void *, s32, void *, s32); /* extern */
s32 bevy_player_p4_144068(void *, s32);             /* extern */
extern s32 g_2dd5bc;
extern s32 g_2e1e40;
extern s32 g_2f7900;

void AdjustJtXpVelocity(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s128 sp10;
    s32 temp_a2;

    sp10 = M2C_FIELD(arg2, s128 *, 0x40);
    temp_a2 = M2C_FIELD((M2C_FIELD(arg2, s32 *, 0x50) + ((1 - M2C_ERROR(/* Read from unset register $t0 */)) << 6)), s32 *, 8);
    if (((temp_a2 == g_2e1e40) || (temp_a2 == g_2dd5bc) || (temp_a2 == g_2f7900)) && ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s32 *, 0x80) != 1) || (bevy_player_p4_144068(arg0, temp_a2) != 0))) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf3, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x40($s1) */);
    }
    AdjustSoXpVelocity(arg0, arg1, arg2, arg3);
    M2C_FIELD(arg2, s128 *, 0x40) = sp10;
}
