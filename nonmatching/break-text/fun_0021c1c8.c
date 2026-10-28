#include "m2c_macros.h"

M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK ProjectSoTransform();                       /* extern */
M2C_UNK func_0021C5F8(void *, M2C_UNK);             /* extern */
extern f32 g_2dded0;

void func_0021C1C8(void *arg0) {
    f32 temp_f1;
    s32 temp_a0;
    s32 temp_hi;
    void *temp_s1;
    void *temp_v0;
    void *temp_v1;

    ProjectSoTransform();
    if (M2C_FIELD(arg0, s32 *, 0x154) == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x160);
        temp_hi = (s32) (temp_a0 + 1) % (s32) M2C_FIELD(arg0, s32 *, 0x158);
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x15C) + (temp_a0 * 0x50);
        M2C_FIELD(arg0, s32 *, 0x160) = temp_hi;
        M2C_FIELD(temp_s1, f32 *, 0) = (f32) g_2dded0;
        M2C_FIELD(temp_s1, f32 *, 4) = (f32) M2C_FIELD(arg0, f32 *, 0x12C);
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        temp_v0 = M2C_FIELD(temp_v1, void *(**)(void *, M2C_UNK, s32, f32 *), 0xFC)(arg0 + M2C_FIELD(temp_v1, s16 *, 0xF8), 0x50, temp_hi, &g_2dded0);
        M2C_FIELD(temp_s1, s128 *, 0x10) = (s128) M2C_FIELD(temp_v0, s128 *, 0);
        M2C_FIELD(temp_s1, s128 *, 0x20) = (s128) M2C_FIELD(temp_v0, s128 *, 0x10);
        M2C_FIELD(temp_s1, s128 *, 0x30) = (s128) M2C_FIELD(temp_v0, s128 *, 0x20);
        M2C_FIELD(temp_s1, s128 *, 0x40) = (s128) M2C_FIELD(temp_v0, s128 *, 0x30);
        if (!(M2C_FIELD(arg0, f32 *, 0x12C) <= 0.0f)) {
            M2C_FIELD(arg0, s32 *, 0x164) = 0;
        } else {
            M2C_FIELD(arg0, s32 *, 0x164) = (s32) (M2C_FIELD(arg0, s32 *, 0x164) + 1);
        }
        if (M2C_FIELD(arg0, void **, 0x180) != NULL) {
            if (M2C_FIELD(arg0, f32 *, 0x12C) == 0.0f) {
                M2C_FIELD(arg0, f32 *, 0x188) = -4.0f;
            }
            PosLoWorld(M2C_FIELD(arg0, void **, 0x180));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x190($s0) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x190($s0) */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            temp_f1 = M2C_FIELD(arg0, f32 *, 0x188) + (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / M2C_FIELD(arg0, f32 *, 0x184));
            M2C_FIELD(arg0, f32 *, 0x188) = temp_f1;
            M2C_FIELD(temp_s1, f32 *, 8) = temp_f1;
        }
        PosLoWorld(arg0);
        func_0021C5F8(arg0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    }
}
