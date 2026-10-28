#include "m2c_macros.h"

f32 GRandInRange();                /* extern */
M2C_UNK GetNormalVectors__FP6VECTORN30(); /* extern */
f32 RadNormalize__Ff();                          /* extern */
s128 SetVectorSphere__FP6VECTORfff();  /* extern */
extern s128 g_2a2da0;
extern s128 g_2a2db0;

void ChooseEmitVelocity__FP6EMITVXffP2LMP6VECTORiT4(void *arg0, void *arg1, s128 *arg2, s32 arg3, f32 fparg0, f32 fparg1) {
    f32 sp8;
    M2C_UNK sp10;
    s128 sp30;
    f32 temp_f22;
    f32 temp_f23;
    f32 var_f22;
    f32 var_f23;
    s32 temp_lo;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0);
    temp_lo = arg3 / temp_v0;
    var_f23 = M2C_FIELD(arg0, f32 *, 0xC) + ((f32) temp_lo * M2C_FIELD(arg0, f32 *, 4));
    var_f22 = M2C_FIELD(arg0, f32 *, 0x10) + ((f32) (arg3 % temp_v0) * M2C_FIELD(arg0, f32 *, 8));
    if (fparg0 != 0.0f) {
        var_f23 += fparg0 * GRandInRange(temp_lo, -0.5f, 0x3F000000) * M2C_FIELD(arg0, f32 *, 4);
        var_f22 += fparg0 * GRandInRange(0xBF000000, 0.5f) * M2C_FIELD(arg0, f32 *, 8);
    }
    temp_f23 = RadNormalize__Ff(var_f23 + 1.5707964f);
    temp_f22 = RadNormalize__Ff(var_f22);
    sp30 = *arg2;
    sp8 *= fparg1;
    GetNormalVectors__FP6VECTORN30(M2C_ERROR(/* unknown instruction: por $a0, $zero, $a3 */), g_2a2da0, g_2a2db0, &sp10, SetVectorSphere__FP6VECTORfff(temp_f22, temp_f23, GRandInRange(M2C_FIELD(arg1, s32 *, 0), M2C_FIELD(arg1, f32 *, 4))));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf2x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s3) */);
}
