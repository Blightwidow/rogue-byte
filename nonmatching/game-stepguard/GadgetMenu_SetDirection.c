#include "m2c_macros.h"

M2C_UNK ClosestPointOnSegment(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, s128); /* extern */
void *GadgetMenu_PgmeFind(s32);                     /* extern */
M2C_UNK GadgetMenu_SelectGadget(void *, s32);       /* extern */
M2C_UNK Menu_ClearDialog(void *);                   /* extern */
s32 NewEmitter(M2C_UNK);                            /* extern */
M2C_UNK SetEmitterUnpositioned(s32, M2C_UNK);       /* extern */
extern f32 g_2c3274;
extern f32 g_2c3278;
extern f32 g_2c327c;
extern f32 g_2ddf0c;

void GadgetMenu_SetDirection(void *arg0, s32 arg1) {
    M2C_UNK sp50;
    M2C_UNK sp10;
    f32 sp70;
    f32 sp74;
    f32 var_f0;
    f32 var_f21;
    s32 temp_a1;
    s32 var_s2;
    s32 var_s5;
    void *temp_s1;
    void *temp_s4;

    if ((arg1 != M2C_FIELD(arg0, s32 *, 0x28)) && (M2C_FIELD(arg0, s32 *, 0x28) = arg1, M2C_FIELD(arg0, f32 *, 0x2C) = (f32) g_2ddf0c, (arg1 != -1))) {
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x48);
        if (temp_a1 != -1) {
            temp_s4 = GadgetMenu_PgmeFind(temp_a1);
            M2C_ERROR(/* unknown instruction: pextlw $a1, $v0, $a1 */);
            M2C_ERROR(/* unknown instruction: pcpyld $a1, $v0, $a1 */);
            if (M2C_FIELD(arg0, void **, 0x10) != NULL) {
                M2C_ERROR(/* unknown instruction: pextlw $v0, $v1, $v0 */);
                M2C_ERROR(/* unknown instruction: pcpyld $v0, $v1, $v0 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            } else {
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf0, $vf0 */);
            }
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
            M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf1x */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
            var_s5 = -1;
            M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf3, $vf1, $vf2x */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x80($sp) */);
            var_s2 = 0;
            var_f21 = 3.4028235e38f;
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, ($sp) */);
            if (M2C_FIELD(arg0, s32 *, 0x4C) > 0) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf1 */);
loop_8:
                temp_s1 = M2C_FIELD(arg0, s32 *, 0x50) + (var_s2 << 5);
                if ((temp_s1 != temp_s4) && (M2C_FIELD(temp_s1, s32 *, 0x1C) & 4)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x80($sp) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: pextlw $s0, $v0, $s0 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
                    if (ClsgClipEdgeToSphere__FP6VECTORfT0T0iP3LSG(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf2 */), 1, g_2c3278, M2C_ERROR(/* unknown instruction: pcpyld $s0, $v0, $s0 */)) > 0) {
                        var_f0 = sp50 * g_2c3274;
                        goto block_15;
                    }
                    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x80($sp) */);
                    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf3, $vf1, $vf3 */);
                    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x90($sp) */);
                    ClosestPointOnSegment(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf1 */), M2C_ERROR(/* unknown instruction: qmfc2.ni $a2, $vf3 */), 0);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x90($sp) */);
                    if ((sp74 < g_2c327c) && (sp70 > 0.0f)) {
                        var_f0 = g_2c3274 + sp74;
block_15:
                        if (var_f0 < var_f21) {
                            var_s5 = M2C_FIELD(temp_s1, s32 *, 0);
                            var_f21 = var_f0;
                        }
                    }
                }
                var_s2 += 1;
                if (var_s2 < M2C_FIELD(arg0, s32 *, 0x4C)) {
                    goto loop_8;
                }
            }
            if (var_s5 != -1) {
                GadgetMenu_SelectGadget(arg0, var_s5);
                Menu_ClearDialog(arg0);
                SetEmitterUnpositioned(NewEmitter(0x35), 0);
            }
        }
    }
}
