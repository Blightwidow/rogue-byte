#include "m2c_macros.h"

M2C_UNK PosLoWorld(s32, M2C_UNK);                   /* extern */
extern f32 D_FLT_002BD2D0;
extern f32 D_FLT_002BD2D8;
extern f32 g_2dded0;

void func_001448F0(void *arg0) {
    s32 var_v0;

    if (M2C_FIELD(arg0, s32 *, 0x28) == 0) {
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($s0) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        var_v0 = 1;
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < D_FLT_002BD2D8)) {
            var_v0 = 0;
        }
        if (var_v0 == 0) {
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($s0) */);
            PosLoWorld(M2C_FIELD(arg0, s32 *, 0), M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf3 */));
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s0) */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_FIELD(arg0, s32 *, 0x20) = (s32) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
            M2C_FIELD(arg0, f32 *, 0x24) = (f32) (g_2dded0 + D_FLT_002BD2D0);
        }
    }
}
