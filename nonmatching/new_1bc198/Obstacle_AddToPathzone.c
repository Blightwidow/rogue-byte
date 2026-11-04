#include "m2c_macros.h"

M2C_UNK AddPathzoneObstacle(s32, void *);           /* extern */
M2C_UNK CStackFrame_Construct(void *);              /* extern */
M2C_UNK CStackFrame_Destructor(void *, M2C_UNK);    /* extern */
M2C_UNK PosLoWorld(void *, s32);                    /* extern */
s32 PpathzoneFindPos(M2C_UNK, M2C_UNK);             /* extern */
s32 PvAllocStackImpl__Fi(s32 *, M2C_UNK);           /* extern */
extern f32 RO_FLT_002A76D4;

void Obstacle_AddToPathzone(void *arg0) {
    char sp[0x400];
    s32 sp10;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    void *temp_v1;

    CStackFrame_Construct(sp);
    sp10 = (M2C_FIELD(arg0, s32 *, 0xE8) * 0x10) - 1;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_v1 = M2C_FIELD(arg0, void **, 0xC);
    temp_s1 = PvAllocStackImpl__Fi(&sp10, 0x10);
    M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
    var_a1 = 1;
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x20($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($v0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf4, $vf1z */);
    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf2, $vf3, $vf0w */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1a0($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1b0($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s1) */);
    M2C_FIELD(((M2C_FIELD(arg0, s32 *, 0xE8) * 0x10) + temp_s1), s128 *, -0x10) = (s128) M2C_FIELD(arg0, s128 *, 0x1A0);
    if ((M2C_FIELD(arg0, s32 *, 0xE8) - 1) > 1) {
        do {
            temp_v0 = var_a1 * 0x10;
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x50($sp) */);
            var_a1 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x30($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf3, $vf4z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf5, $vf1, $vf0w */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1a0($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1b0($s0) */);
            M2C_ERROR(/* unknown instruction: vmini.xyz $vf2, $vf2, $vf5 */);
            M2C_ERROR(/* unknown instruction: vmax.xyz $vf1, $vf1, $vf5 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x1a0($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x1b0($s0) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf5, ($a0) */);
        } while (var_a1 < (M2C_FIELD(arg0, s32 *, 0xE8) - 1));
    }
    M2C_FIELD(arg0, f32 *, 0x1A8) = -3.4028235e38f;
    M2C_FIELD(arg0, f32 *, 0x1B8) = (f32) RO_FLT_002A76D4;
    PosLoWorld(arg0, var_a1);
    temp_v0_2 = PpathzoneFindPos(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), 0);
    if (temp_v0_2 == 0) {
        CStackFrame_Destructor(sp, 2);
        return;
    }
    AddPathzoneObstacle(temp_v0_2, arg0);
    CStackFrame_Destructor(sp, 2);
}
