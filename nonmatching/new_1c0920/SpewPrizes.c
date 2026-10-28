#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(M2C_UNK *, M2C_UNK, s128); /* extern */
M2C_UNK ClearPrizeSpewer(void *);                   /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
f32 GRandInRange(f32, f32);                         /* extern */
void *PloLeaseCloneObject(s32, M2C_UNK);            /* extern */
s128 PosLoWorld(s32);                               /* extern */
s32 PpoSwFocusBase(M2C_UNK *);                      /* extern */
s128 SetVectorCylind__FP6VECTORfff(f32, f32, M2C_UNK); /* extern */
M2C_UNK VelBallistic(s128, M2C_UNK, M2C_UNK, f32);  /* extern */
M2C_UNK func_001C6BD0(void *, s128, M2C_UNK, f32, f32); /* extern */
extern M2C_UNK B_003DD490;
extern M2C_UNK D_FLT_002C0CE0;
extern f32 D_FLT_002C0CE8;
extern f32 D_FLT_002C0CEC;
extern M2C_UNK D_FLT_002C0CF0;
extern M2C_UNK D_FLT_002C0CF8;
extern s128 g_2a2dc0;

void *SpewPrizes(void *arg0, s32 arg1) {
    M2C_UNK sp30;
    s32 sp60;
    s128 sp70;
    s128 sp80;
    s128 sp90;
    f32 temp_f0;
    f32 temp_f20;
    f32 var_f13;
    f32 var_f2;
    s32 var_s3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *var_s1;
    void *var_s4;

    var_s3 = 0;
    var_s4 = NULL;
    sp60 = arg1;
loop_14:
    if (var_s3 < sp60) {
        if (var_s3 != 0) {
            var_s1 = PloLeaseCloneObject(M2C_FIELD(arg0, s32 *, 0x154), 0);
            if (var_s1 != NULL) {
                if (FIsBasicDerivedFrom(var_s1, 0x5A) != 0) {
                    temp_v0 = M2C_FIELD(var_s1, void **, 0xC);
                    M2C_FIELD(temp_v0, M2C_UNK (**)(void *, M2C_UNK), 0x264)(var_s1 + M2C_FIELD(temp_v0, s16 *, 0x260), 2);
                }
                goto block_22;
            }
        } else {
            var_s1 = M2C_FIELD(arg0, void **, 0x158);
block_22:
            if (var_s1 != NULL) {
                var_s4 = (var_s4 == NULL) ? var_s1 : var_s4;
                sp70 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s128 *, 0x70);
                sp80 = PosLoWorld(PpoSwFocusBase(&B_003DD490));
                temp_f20 = GRandInRange(M2C_FIELD(&D_FLT_002C0CF0, f32 *, 0), M2C_FIELD(&D_FLT_002C0CF0, f32 *, 4));
                sp90 = SetVectorCylind__FP6VECTORfff(temp_f20, GRandInRange(M2C_FIELD(&D_FLT_002C0CF8, f32 *, 0), M2C_FIELD(&D_FLT_002C0CF8, f32 *, 4)), 0xC2960000);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x80($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x70($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s5) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf4, $vf2z */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf3, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf4, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf4, $vf1z */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) < 0.0001f) {
                    M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
                } else {
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
                }
                BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp30, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), g_2a2dc0);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x90($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf2, $vf5x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf5y */);
                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf1, $vf4, $vf5z */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x80($sp) */);
                M2C_ERROR(/* unknown instruction: vadd.xyzw $vf1, $vf5, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xa0($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
                VelBallistic(sp70, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */), GRandInRange(M2C_FIELD(&D_FLT_002C0CE0, f32 *, 0), M2C_FIELD(&D_FLT_002C0CE0, f32 *, 4)));
                M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
                if (FIsBasicDerivedFrom(var_s1, 0x5A) == 0) {
                    temp_v0_2 = M2C_FIELD(var_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_2, M2C_UNK (**)(void *), 0x44)(var_s1 + M2C_FIELD(temp_v0_2, s16 *, 0x40));
                    temp_v0_3 = M2C_FIELD(var_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_3, M2C_UNK (**)(void *, void *), 0x13C)(var_s1 + M2C_FIELD(temp_v0_3, s16 *, 0x138), M2C_FIELD(arg0, void **, 0x150));
                    temp_v0_4 = M2C_FIELD(var_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_4, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(var_s1 + M2C_FIELD(temp_v0_4, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
                } else {
                    if ((FIsBasicDerivedFrom(var_s1, 0x5B) != 0) || (FIsBasicDerivedFrom(var_s1, 0x5D) != 0)) {
                        temp_f0 = (f32) var_s3;
                        var_f2 = temp_f0;
                        var_f13 = temp_f0 * D_FLT_002C0CEC;
                    } else {
                        var_f2 = (f32) var_s3;
                        var_f13 = 3.4028235e38f;
                    }
                    func_001C6BD0(var_s1, M2C_FIELD(M2C_FIELD(arg0, void **, 0x150), s128 *, 0x70), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */), var_f2 * D_FLT_002C0CE8, var_f13);
                }
                var_s3 += 1;
                goto loop_14;
            }
        }
    }
    ClearPrizeSpewer(arg0);
    return var_s4;
}
