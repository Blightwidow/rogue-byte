#include "m2c_macros.h"

M2C_UNK BuildRotateVectorsMatrix(s128 *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK EvaluateCrvFromU(void *, M2C_UNK, M2C_UNK *, f32); /* extern */
f32 GModPositive__Fff(f32, f32);                    /* extern */
M2C_UNK GetPathPosFromS(void *, M2C_UNK *, M2C_UNK, f32); /* extern */
s128 GetPerpendicularVector(M2C_UNK);               /* extern */
f32 SMaxCrv(void *);                                /* extern */
f32 SMinCrv();                                      /* extern */
f32 UMinCrv(void *);                                /* extern */
M2C_UNK bevy_camera_follow_track_heading_weight(void *, M2C_UNK, s128); /* extern */
f32 func_001E6728(void *, f32);                     /* extern */

void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(void *arg0, s32 arg1, void *arg2, f32 fparg0) {
    M2C_UNK sp0;
    M2C_UNK sp20;
    M2C_UNK spC0;
    M2C_UNK spD0;
    s128 sp10;
    M2C_UNK sp30;
    M2C_UNK sp60;
    M2C_UNK sp70;
    s128 sp80;
    s128 sp90;
    s128 spA0;
    s128 spB0;
    f32 temp_f22;
    f32 temp_f23;
    f32 var_f0;
    f32 var_f1;
    f32 var_f21;
    s32 var_s1;

    temp_f22 = SMinCrv();
    temp_f23 = SMaxCrv(arg0);
    EvaluateCrvFromU(arg0, 0, &sp30, UMinCrv(arg0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x30($sp) */);
    var_s1 = 0;
loop_5:
    if (var_s1 & 1) {
        var_f1 = 10.0f;
        var_f0 = (f32) (var_s1 + 1);
    } else {
        var_f1 = (f32) var_s1;
        var_f0 = -10.0f;
    }
    var_f21 = fparg0 + (var_f1 * var_f0);
    if (M2C_FIELD(arg0, s32 *, 0xE4) == 0) {
        if (!(var_f21 < temp_f22) && !(temp_f23 < fparg0)) {

        } else {
block_4:
            var_s1 += 1;
            goto loop_5;
        }
    } else {
        var_f21 = temp_f22 + GModPositive__Fff(var_f21 - temp_f22, temp_f23 - temp_f22);
    }
    GetPathPosFromS(arg0, &sp60, 0, func_001E6728(arg0, var_f21 + 50.0f));
    GetPathPosFromS(arg0, &sp70, 0, func_001E6728(arg0, var_f21 - 50.0f));
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf3 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf1 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
    }
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x50($sp) */);
    if (var_s1 == 0) {
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x40($sp) */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x50($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf3, $vf4 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
    if (!(M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) > -0.9f)) {
        goto block_4;
    }
    BuildRotateVectorsMatrix(&spB0, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf4 */));
    sp90 = spC0;
    sp80 = spB0;
    spA0 = spD0;
    bevy_camera_follow_track_heading_weight(arg0, 0, M2C_FIELD(arg0, s128 *, 0x1C0));
    M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x40($sp) */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf5, $vf5 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf6, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x90($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf7 */);
    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf7x */);
    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf7y */);
    M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf1, $vf7z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x60($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf6 */) < 0.0001f) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $a0, $vf4 */);
    } else {
        M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf6x */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf4, $vf5, $q */);
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf1 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf1, $vf4 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf2, $vf1, $q */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */) < 0.0001f) {
        sp10 = GetPerpendicularVector(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf4 */));
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf4, $vf2 */);
    M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf1, $vf2, $vf4 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
    if (arg1 == 0) {
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf2, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x70($sp) */);
        M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf4, $vf1x */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
    }
    if (arg2 != NULL) {
        M2C_FIELD(arg2, s128 *, 0) = sp0;
        M2C_FIELD(arg2, s128 *, 0x20) = sp20;
        M2C_FIELD(arg2, s128 *, 0x10) = sp10;
    }
}
