#include "m2c_macros.h"

M2C_UNK AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(void *, void *, void *); /* extern */
M2C_UNK AddSoAcceleration(void *, M2C_UNK);         /* extern */
M2C_UNK ConvertXfMat(s128 *, s32, M2C_UNK, void *); /* extern */
M2C_UNK LoadRotateMatrixRad(s128 *, s128, f32);     /* extern */
extern s128 g_2a2dc0;

void Chaser_AccelToward(void *arg0) {
    char sp[0x400];
    s128 sp30;
    s128 sp60;
    void *temp_v1;

    if (M2C_FIELD(arg0, s32 *, 0x1C0) != 4) {
        LoadRotateMatrixRad(&sp30, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x204));
        if (M2C_FIELD(arg0, s32 *, 0x1C0) != 3) {
            ConvertXfMat(&sp30, M2C_FIELD(M2C_FIELD(arg0, void **, 0x5C), s32 *, 0xA0), 0, sp);
        }
        AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(arg0, sp, arg0 + 0x378);
    }
    if (M2C_FIELD(arg0, s32 *, 0x1C0) == 3) {
        temp_v1 = M2C_FIELD(arg0, void **, 0xC);
        sp60 = M2C_FIELD(arg0, s128 *, 0x210);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *), 0x10C)(arg0 + M2C_FIELD(temp_v1, s16 *, 0x108));
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf3 */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
        AddSoAcceleration(arg0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */));
    }
}
