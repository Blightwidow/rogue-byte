#include "m2c_macros.h"

f32 GRandInRange(M2C_UNK, f32);                     /* extern */
s128 PosLoWorld(s32);                               /* extern */
M2C_UNK SetVectorSphere__FP6VECTORfff(f32, f32, f32, s128); /* extern */
extern s128 g_2a2dc0;
extern f32 g_2be8b0;

void Member_GetRandomPos(void *arg0, s32 arg1, s128 *arg2) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    s16 temp_a1;
    s32 temp_s0;
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x20);
    temp_a1 = M2C_FIELD(temp_v1, s16 *, 0x30);
    temp_s0 = M2C_FIELD(temp_v1, s32 (**)(void *, s16), 0x34)(arg0 + temp_a1, temp_a1);
    temp_f22 = GRandInRange(0xC0490FDB, 3.1415927f);
    temp_f0 = GRandInRange(0xBF800000, 1.0f);
    temp_f20 = fabsf(temp_f0) * temp_f0 * 1.5707964f;
    temp_f21 = GRandInRange(0, g_2be8b0);
    SetVectorSphere__FP6VECTORfff(temp_f22, temp_f20, temp_f21, PosLoWorld(temp_s0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($s1) */);
    *arg2 = g_2a2dc0;
}
