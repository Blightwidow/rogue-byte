#include "m2c_macros.h"

M2C_UNK BuildRotateVectorsMatrix(s128 *, s128, M2C_UNK, f32); /* extern */
M2C_UNK CStackFrame_Construct(M2C_UNK *, s128, M2C_UNK *); /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK, s128, void *); /* extern */
M2C_UNK DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(s128 *, f32 *, s128 *, s128); /* extern */
s32 FFindSurfaceAlongUp(s128 *, M2C_UNK, M2C_UNK, f32, f32); /* extern */
M2C_UNK IntersectSwBoundingSphere(M2C_UNK *, s128, M2C_UNK *, s32, f32); /* extern */
M2C_UNK LoadRotateMatrixRad(s128 *, s128, f32);     /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK __as__6VECTORG9VU_VECTOR(s128 *, M2C_UNK);  /* extern */
extern M2C_UNK B_003DD490;
extern s32 D_002C3CE4;
extern f32 D_FLT_002C3CE8;
extern M2C_UNK FFilterHitTestDefault;
extern s128 g_2a2dc0;

void func_00205910(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    M2C_UNK RO_FLT_002A85F8;
    M2C_UNK sp120;
    M2C_UNK sp130;
    M2C_UNK sp90;
    M2C_UNK spA0;
    M2C_UNK unksp1C;
    M2C_UNK unksp2C;
    M2C_UNK unkspC;
    s128 sp0;
    s128 sp10;
    s128 sp20;
    s128 sp30;
    f32 sp3C;
    s128 sp40;
    s128 sp50;
    s128 sp60;
    s128 sp70;
    s128 sp80;
    M2C_UNK spB0;
    s128 spC0;
    s128 spE0;
    s128 spF0;
    s128 sp100;
    s128 sp110;
    M2C_UNK sp170;
    M2C_UNK sp174;
    f32 sp178;
    void *sp17C;
    void *sp180;
    s32 sp184;
    M2C_UNK *sp188;
    f32 *sp18C;
    s128 *sp190;
    f32 temp_a3;
    f32 var_f20;
    s128 *var_s0;
    s32 var_s1;
    s32 var_v0;
    s32 var_v1;

    sp17C = arg0;
    sp180 = arg1;
    sp184 = arg3;
    LoadRotateMatrixRad(&sp80, g_2a2dc0, M2C_FIELD(arg0, f32 *, 0x1A8));
    PosLoWorld(sp17C);
    __as__6VECTORG9VU_VECTOR(&sp30, M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
    sp188 = &spB0;
    sp0 = sp80;
    sp10 = sp90;
    sp20 = spA0;
    sp3C = 1.0f;
    unksp2C = 0;
    unksp1C = 0;
    unkspC = 0;
    sp40 = sp0;
    sp50 = sp10;
    sp60 = sp20;
    sp70 = sp30;
    var_f20 = -3.4028235e38f;
    if (arg2 > 0) {
        var_v0 = arg2;
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
            var_v0 -= 1;
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
            var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f0, $f20 */);
        } while (var_v0 != 0);
    }
    CStackFrame_Construct(sp188, sp10, &RO_FLT_002A85F8);
    IntersectSwBoundingSphere(&B_003DD490, sp30, &FFilterHitTestDefault, M2C_FIELD(sp17C, s32 *, 0xEC), var_f20);
    var_v1 = 0;
    if (D_002C3CE4 > 0) {
        sp190 = &spE0;
        sp18C = &sp178;
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x20($sp) */);
            if (arg2 > 0) {
                var_s0 = &sp80;
                var_s1 = arg2;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s2) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($sp) */);
                    M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
                    M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
                    M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf5z */);
                    M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x1a0($sp) */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xc0($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x1a0($sp) */);
                    if (FFindSurfaceAlongUp(&spC0, 0, 0, M2C_FIELD(sp180, f32 *, 4), M2C_FIELD(sp180, f32 *, 0)) != 0) {
                        *var_s0 = spC0;
                    } else {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xc0($sp) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf2, $vf6, $vf1x */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xd0($sp) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($s0) */);
                    }
                    var_s0 += 0x10;
                    var_s1 -= 1;
                } while (var_s1 != 0);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x90($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xa0($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf3 */);
            M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf2, $vf1 */);
            M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf1, $vf2 */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            temp_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf1 */);
            if (temp_a3 < 0.0001f) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a2, $vf1 */);
            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            }
            BuildRotateVectorsMatrix(&sp110, sp60, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), temp_a3);
            sp100 = sp130;
            spE0 = sp110;
            spF0 = sp120;
            DecomposeRotateMatrixRad__FP7MATRIX3PfP6VECTOR(sp190, sp18C, &spC0, sp110);
            if (D_FLT_002C3CE8 < sp178) {
                LoadRotateMatrixRad(&sp110, spC0, D_FLT_002C3CE8);
                spE0 = sp110;
                spF0 = sp120;
                sp100 = sp130;
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xe0($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0xf0($sp) */);
            var_v1 += 1;
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x100($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($sp) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf4x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf4y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf4, $vf5, $vf4z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x110($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x140($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($s6) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf2x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf2y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf2, $vf5, $vf2z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x120($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x150($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($s6) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf1x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf6, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf5, $vf1z */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x160($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x130($sp) */);
            unksp2C = 0;
            unksp1C = 0;
            unkspC = 0;
        } while (var_v1 < D_002C3CE4);
    }
    M2C_FIELD(sp17C, s128 *, 0x1B0) = sp0;
    M2C_FIELD(sp17C, s128 *, 0x1D0) = sp20;
    M2C_FIELD(sp17C, s128 *, 0x1C0) = sp10;
    CStackFrame_Destructor(sp188, 2, sp10, sp17C);
}
