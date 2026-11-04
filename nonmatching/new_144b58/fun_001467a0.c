#include "m2c_macros.h"

s32 FIsLoInWorld();                           /* extern */
f32 GRandInRange();                 /* extern */
M2C_UNK PmatLoWorld();                        /* extern */
s128 PosLoWorld();                      /* extern */
M2C_UNK func_00146E18();             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
extern f32 D_FLT_002BD360;
extern f32 D_FLT_002BD368;
extern f32 D_FLT_002BD36C;
extern f32 D_FLT_002BD370;
extern f32 g_2dded0;

void func_001467A0(void *arg0) {
    f32 temp_v0;
    s32 temp_v1;
    u32 temp_s1;
    void *temp_a0;
    void *temp_a0_2;

    func_001EEF98();
    if (M2C_FIELD(arg0, u32 *, 0x30) != -1U) {
        if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0xDF4) == -1) && (FIsLoInWorld(M2C_FIELD(arg0, void **, 0x38)) != 0)) {
            temp_a0 = M2C_FIELD(arg0, void **, 0x38);
            if (M2C_FIELD(temp_a0, s32 *, 0x330) != 0) {
                goto block_5;
            }
            PosLoWorld(M2C_FIELD(arg0, void **, 0x10), PosLoWorld(temp_a0));
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x10($sp) */);
            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($sp) */);
            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf3 */);
            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
            M2C_ERROR(/* unknown instruction: vwaitq */);
            M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
            if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) < 0.0001f) {

            } else {
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf2x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf3, $q */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, ($sp) */);
            }
            temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
            do {
                temp_s1 = M2C_FIELD(arg0, u32 *, 0x30);
                switch (temp_s1) {
                case 0:
                    if (temp_v0 < D_FLT_002BD360) {
                        PmatLoWorld(M2C_FIELD(arg0, void **, 0x10));
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($sp) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf2 */) > 0.8f) {
                            if (GRandInRange(0, 0x3F800000) < 0.3f) {
                                func_00146E18(arg0, 3);
                            } else {
                                func_00146E18(arg0, 2);
                            }
                        }
                    } else if (D_FLT_002BD36C < temp_v0) {
                        func_00146E18(arg0, 1);
                    }
                    break;
                case 1:
                    if (temp_v0 < D_FLT_002BD368) {
                        func_00146E18(arg0, 0);
                    }
                    break;
                case 2:
                    if ((M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x18D8) == -1) && ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f)) {
block_30:
                        func_00146E18(arg0, -1);
                    }
                    break;
                case 3:
                    if ((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f) {
                        temp_a0_2 = M2C_FIELD(arg0, void **, 0x10);
                        temp_v1 = M2C_FIELD(temp_a0_2, s32 *, 0x2DC);
                        if (temp_v1 != -1) {
                            if ((temp_v1 == 1) && (D_FLT_002BD370 < (g_2dded0 - M2C_FIELD(temp_a0_2, f32 *, 0x2E0)))) {
                                func_00146E18(arg0, 4);
                            }
                        } else {
                            goto block_30;
                        }
                    }
                    break;
                case 4:
                    if (((g_2dded0 - M2C_FIELD(arg0, f32 *, 0x34)) > 0.1f) && (M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0x18C8) != 0xD)) {
                        func_00146E18(arg0, -1);
                    }
                    break;
                }
            } while (M2C_FIELD(arg0, u32 *, 0x30) != temp_s1);
        } else {
block_5:
            func_00146E18(arg0, -1);
        }
    }
}
