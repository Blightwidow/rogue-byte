#include "m2c_macros.h"

M2C_UNK GSmooth__FfffP3SMPPf(M2C_UNK *, s32 *, M2C_UNK, f32, f32); /* extern */
M2C_UNK InvertMatrix3(M2C_UNK *, void *);           /* extern */
s128 PosLoWorld(void *);                            /* extern */
M2C_UNK SetStepRadTargetDir(void *, s128);          /* extern */
extern M2C_UNK D_002BF418;
extern s128 g_2a2da0;
extern f32 g_2bf414;
extern f32 g_2dded4;

void func_0018E1E0(void *arg0) {
    s128 sp0;
    M2C_UNK sp40;
    s32 sp80;
    s128 sp90;

    sp90 = PosLoWorld(M2C_FIELD(arg0, void **, 0x10DC));
    PosLoWorld(arg0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {
        sp0 = g_2a2da0;
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    }
    SetStepRadTargetDir(arg0, sp0);
    GSmooth__FfffP3SMPPf(&D_002BF418, &sp80, M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */), g_2bf414, g_2dded4 * 0.5f);
    InvertMatrix3(&sp40, arg0 + 0x1B0);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf5, $vf5, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf3, $vf2x */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf1x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf5, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf3, $vf1z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x190($s0) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf5, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x30($sp) */);
}
