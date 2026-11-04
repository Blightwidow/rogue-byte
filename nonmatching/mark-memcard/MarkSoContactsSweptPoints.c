#include "m2c_macros.h"

s32 ClsgClipEdgeToObject(void *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK InvertMatrix4Affine(M2C_UNK *, void *);     /* extern */
M2C_UNK PxpAdd(s32, void *, void *, M2C_UNK, f32, s32); /* extern */

void MarkSoContactsSweptPoints(s32 arg0, void *arg1, void *arg2, s32 arg3) {
    M2C_UNK sp50;
    M2C_UNK sp10;
    M2C_UNK spD0;
    f32 temp_a3;
    f32 temp_f0;
    f32 var_f12;
    s32 temp_v0;
    s32 var_s1;
    s32 var_v1;
    s32 var_v1_2;

    var_s1 = M2C_FIELD(arg1, s32 *, 0x1C);
    if (var_s1 < M2C_FIELD(arg1, s32 *, 0x78)) {
        do {
            M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x20($s0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($s4) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s4) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($s4) */);
            M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf3x */);
            M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf3y */);
            M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf3z */);
            M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
            if (M2C_FIELD(arg2, s32 *, 0xA8) != M2C_FIELD(arg2, s32 *, 0xAC)) {
                M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x120($sp) */);
                InvertMatrix4Affine(&spD0, arg2 + 0x20);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xe0($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0xf0($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x100($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0xd0($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x120($sp) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf5, $vf6x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf3, $vf6y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf6z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf1, $vf0w */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x40($v1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x30($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x20($v0) */);
                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf4, $vf6x */);
                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf6y */);
                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf1, $vf6z */);
                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf6, $vf3, $vf0w */);
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            var_s1 += 1;
            M2C_ERROR(/* unknown instruction: sqc2 $vf6, 0x120($sp) */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x110($sp) */);
            temp_v0 = ClsgClipEdgeToObject(arg2, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf6 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), 2);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x110($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x120($sp) */);
            if (temp_v0 != 0) {
                var_f12 = 0.0f;
                var_v1 = 1;
                if (sp50 != 0.0f) {
                    var_v1 = 0;
                }
                if (var_v1 < temp_v0) {
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf6, $vf1 */);
                    var_v1_2 = M2C_FIELD(arg1, s32 *, 0x90);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf6, 0x10($sp) */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                    M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf5, $vf1, $q */);
                    if (var_v1_2 > 0) {
                        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf4, $vf6 */);
                        M2C_ERROR(/* unknown instruction: vmove.xyzw $vf3, $vf5 */);
                        do {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf4 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                            temp_a3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf1 */);
                            if (temp_a3 < var_f12) {
                                var_f12 = temp_a3;
                            }
                            var_v1_2 -= 1;
                        } while (var_v1_2 != 0);
                    }
                    if (M2C_FIELD(arg1, s64 *, 0x10) & (0x8000 << 0x22)) {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x70($v0) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf6 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf5 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        temp_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) - M2C_FIELD(arg1, f32 *, 8);
                        if (temp_f0 < var_f12) {
                            var_f12 = temp_f0;
                        }
                    }
                    M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf5 */);
                    PxpAdd(arg0, arg1, arg2, M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf6 */), var_f12, arg3);
                }
            }
        } while (var_s1 < M2C_FIELD(arg1, s32 *, 0x78));
    }
}
