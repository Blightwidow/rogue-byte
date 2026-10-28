#include "m2c_macros.h"

M2C_UNK FindCrvClosestPointFromS(s32, M2C_UNK, M2C_UNK, void *, f32); /* extern */
s128 PosLoWorld();                                  /* extern */
f32 atan2f(M2C_UNK, M2C_UNK);                       /* extern */
extern M2C_UNK g_2c20d0;
extern M2C_UNK g_2c20e0;

void func_001D2490(void *arg0) {
    char sp[0x400];
    M2C_UNK sp10;
    s128 sp30;
    M2C_UNK var_v0;
    f32 temp_f3;
    f32 temp_v0;

    sp30 = PosLoWorld();
    FindCrvClosestPointFromS(M2C_FIELD(arg0, s32 *, 0x5AC), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */), 0, sp, M2C_FIELD(arg0, f32 *, 0x5B0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    temp_f3 = M2C_FIELD(&g_2c20d0, f32 *, 0) + (temp_v0 * (M2C_FIELD(&g_2c20d0, f32 *, 4) + (temp_v0 * M2C_FIELD(&g_2c20d0, f32 *, 8))));
    if (temp_f3 < M2C_FIELD(&g_2c20e0, f32 *, 0)) {

    } else if (M2C_FIELD(&g_2c20e0, f32 *, 4) < temp_f3) {

    }
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf1, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf4, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf5 */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f)) {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf4, $q */);
        var_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    }
    M2C_FIELD(arg0, f32 *, 0x544) = atan2f(M2C_ERROR(/* unknown instruction: prot3w $v1, $v0 */), var_v0);
    M2C_FIELD(arg0, f32 *, 0x550) = (f32) (M2C_FIELD(arg0, f32 *, 0x51C) * 0.75f);
}
