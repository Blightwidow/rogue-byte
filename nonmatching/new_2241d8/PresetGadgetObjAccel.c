#include "m2c_macros.h"

M2C_UNK AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(void *, void *, M2C_UNK *, s128); /* extern */
M2C_UNK AddSoGravityAcceleration();                 /* extern */
M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, M2C_UNK, s128); /* extern */
s32 PmatLoWorld(void *);                            /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK TiltMatUpright__FP7MATRIX3N20(s32, M2C_UNK, void *); /* extern */
extern M2C_UNK D_002C4300;
extern s128 g_2a2dc0;
extern s128 g_2a2dd0;

void PresetGadgetObjAccel(void *arg0) {
    char sp[0x400];
    s128 sp30;
    s32 temp_v1;
    s32 temp_v1_2;
    void *temp_a0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x150);
    if ((temp_v1 != 0) && (temp_v1 != 4) && ((AddSoGravityAcceleration(), temp_v1_2 = M2C_FIELD(arg0, s32 *, 0x15C), (temp_v1_2 == 0x1A)) || (temp_v1_2 == 0x29))) {
        temp_a0 = M2C_FIELD(arg0, void **, 0x160);
        if (temp_a0 != NULL) {
            PosLoWorld(temp_a0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x60($sp) */);
            PosLoWorld(arg0);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x60($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            }
            BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), g_2a2dc0);
        } else {
            TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(arg0), 0, sp);
        }
        AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(arg0, sp, &D_002C4300, g_2a2dd0);
    }
}
