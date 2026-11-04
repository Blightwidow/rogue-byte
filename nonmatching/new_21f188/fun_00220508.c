#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32);                            /* extern */
extern f32 g_2dded0;

void func_00220508(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_v1 < 7) && (temp_v1 >= 4)) {
        PosLoWorld(arg1);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xe0($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x110($s0) */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x100($s0) */);
        M2C_FIELD(arg0, s32 *, 0x128) = 1;
        M2C_FIELD(arg0, f32 *, 0x120) = (f32) g_2dded0;
        M2C_FIELD(arg0, f32 *, 0x124) = (f32) (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / M2C_FIELD(arg0, f32 *, 0x28));
    }
}
