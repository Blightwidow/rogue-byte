#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct();              /* extern */
M2C_UNK CStackFrame_Destructor(); /* extern */
s32 ClsgClipEdgeToBsp(); /* extern */
M2C_UNK InitPlaneFromNormalPos(); /* extern */
s32 PruneBsp__FP3BSPP6VECTORfPP3BSP(); /* extern */
s32 PvAllocStackImpl__Fi();                    /* extern */

void bevy_physics_sphere_1a9108(s32 arg0, s32 arg1, s128 arg3) {
    char sp[0x400];
    M2C_UNK sp60;
    s32 sp10;
    s128 sp20;
    s32 sp620;
    s32 sp624;
    s128 sp630;
    f32 var_f20;
    f32 var_f21;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a2;
    s32 var_s1;
    void **var_a1;
    void **var_s0;
    void *temp_a2;
    void *temp_s3;
    void *temp_v0_3;

    var_f20 = M2C_ERROR(/* unknown instruction: max.s $f20, $f12, $f0 */);
    temp_s3 = M2C_ERROR(/* Read from unset register $t0 */);
    sp630 = arg3;
    CStackFrame_Construct(sp);
    sp10 = 0xFFFC;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    temp_s2 = PvAllocStackImpl__Fi(&sp10);
    if (var_f20 < 52000.0f) {
loop_2:
        sp624 = temp_s2;
        sp620 = 0x1555;
        temp_v0 = PruneBsp__FP3BSPP6VECTORfPP3BSP(arg0, arg1, sp630, &sp620, var_f20);
        if ((temp_v0 >= 0) && (temp_v0 >= 2) && (temp_v0 == 2)) {
            var_f21 = 0.0f;
            var_s1 = 0;
            temp_v0_2 = (s32) ((sp624 - temp_s2) * 0xAAAAAAAB) >> 2;
            sp620 = temp_v0_2;
            if (temp_v0_2 > 0) {
                var_s0 = temp_s2 + 8;
                do {
                    temp_a2 = *var_s0;
                    temp_v1 = M2C_FIELD(temp_a2, s32 *, 0x18);
                    if (!(temp_v1 & 0x1000)) {
                        M2C_FIELD(temp_a2, s32 *, 0x18) = (s32) (temp_v1 | 0x1000);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a2) */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf1, $vf1, $vf2x */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x640($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x640($sp) */);
                        if (ClsgClipEdgeToBsp(sp624 - 0xC, 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf1 */), M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf3 */)) > 0) {
                            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x630($sp) */);
                            if (var_f21 < sp60) {
                                var_f21 = sp60;
                                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf1, $vf1 */);
                                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                                M2C_ERROR(/* unknown instruction: vwaitq */);
                                M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
                                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                                M2C_ERROR(/* unknown instruction: vwaitq */);
                                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf3, $vf1, $q */);
                                M2C_FIELD(temp_s3, s128 *, 0) = sp20;
                                InitPlaneFromNormalPos(temp_s3 + 0x10, M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */));
                                M2C_FIELD(temp_s3, s32 *, 0x20) = 0xC;
                            }
                        }
                    }
                    var_s1 += 1;
                    var_s0 += 0xC;
                } while (var_s1 < sp620);
            }
            var_a2 = 0;
            if (sp620 > 0) {
                var_a1 = temp_s2 + 8;
                do {
                    temp_v0_3 = *var_a1;
                    var_a2 += 1;
                    M2C_FIELD(temp_v0_3, s32 *, 0x18) = (s32) (M2C_FIELD(temp_v0_3, s32 *, 0x18) & ~0x1000);
                    var_a1 += 0xC;
                } while (var_a2 < sp620);
            }
            if (var_f21 > 0.0f) {
                CStackFrame_Destructor(sp, 2, var_a2);
                return;
            }
            goto block_18;
        }
block_18:
        var_f20 *= 2.0f;
        if (!(var_f20 < 52000.0f)) {
            goto block_19;
        }
        goto loop_2;
    }
block_19:
    CStackFrame_Destructor(sp, 2);
}
