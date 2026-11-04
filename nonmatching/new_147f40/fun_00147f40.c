#include "m2c_macros.h"

M2C_UNK AppendDlEntry();             /* extern */
s32 FFindDlEntry();                  /* extern */
s128 PosLoWorld();                       /* extern */
void *PpoSwFocusBase();                             /* extern */
M2C_UNK RemoveDlEntry();             /* extern */
M2C_UNK RemoveSwRootRaw();           /* extern */
M2C_UNK RetractSwRoot();             /* extern */
extern M2C_UNK B_002DDF40;
extern f32 D_FLT_002BD450;
extern void *g_2dd2fc;

void func_00147F40(void *arg0) {
    M2C_UNK saved_reg_s4;
    char sp[0x400];
    void ***sp4;
    s32 sp8;
    void *spC;
    s128 sp10;
    s128 sp20;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_v0_2;
    f32 temp_v0_3;
    s128 var_v0;
    s32 temp_s5;
    s32 var_a1;
    s32 var_s4;
    s64 temp_a0_2;
    void ***var_v0_2;
    void **temp_a0_3;
    void **temp_v0_4;
    void **var_s2;
    void *temp_a0;
    void *temp_s1;
    void *temp_v0;
    void *temp_v0_5;
    void *temp_v0_6;
    void *var_s0;

    var_s4 = saved_reg_s4;
    temp_s5 = M2C_FIELD(&B_002DDF40, s32 *, 0x14);
    sp10 = M2C_FIELD(&B_002DDF40, s128 *, 0x90);
    temp_v0 = PpoSwFocusBase();
    if (temp_v0 == NULL) {
        var_v0 = sp10;
    } else {
        var_v0 = PosLoWorld(temp_v0);
    }
    sp20 = var_v0;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($sp) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x39b0($s3) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf2 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf1, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf1, $vf2z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf2, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x39c0($s3) */);
    temp_v0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf1 */);
    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
    if ((D_FLT_002BD450 < temp_v0_2) || (D_FLT_002BD450 < temp_v0_3) || (var_v0_2 = arg0 + 0x20, (temp_s5 != M2C_FIELD(arg0, s32 *, 0x39A8)))) {
        M2C_FIELD(arg0, s32 *, 0x39A4) = 0;
        M2C_FIELD(arg0, s32 *, 0x39A8) = temp_s5;
        M2C_FIELD(arg0, s128 *, 0x39B0) = sp10;
        M2C_FIELD(arg0, s128 *, 0x39C0) = sp20;
        var_v0_2 = arg0 + 0x20;
    }
    sp4 = var_v0_2;
    temp_a0 = g_2dd2fc;
    var_a1 = M2C_FIELD(var_v0_2, s32 *, 8);
    g_2dd2fc = sp;
    temp_v0_4 = M2C_FIELD(arg0, void ***, 0x20);
    spC = temp_a0;
    var_s2 = temp_v0_4;
    sp4 = temp_v0_4 + var_a1;
    sp8 = var_a1;
    if (var_s2 != M2C_FIELD(arg0, s32 *, 0x39A4)) {
        do {
            temp_s1 = *var_s2;
            temp_a0_2 = (s64) (M2C_FIELD(temp_s1, s64 *, 0x28) << 8) >> 0x3C;
            if (temp_a0_2 != 1) {
                if (temp_a0_2 < 2) {
                    var_s0 = arg0 + 0x2C;
                    if (temp_a0_2 != 0) {

                    } else {
                        if (!(temp_s5 & M2C_FIELD(temp_s1, u8 *, 0x2D))) {
                            var_s4 = 0;
                            goto block_25;
                        }
                        var_s4 = 1;
                        PosLoWorld(temp_s1, var_a1);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                        M2C_ERROR(/* unknown instruction: vwaitq */);
                        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                        temp_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) - M2C_FIELD(temp_s1, f32 *, 0x38);
                        if (!(temp_f0 < 0.0f)) {
                            var_s4 = 0;
                        }
                        var_s0 = arg0 + 0x2C;
                        if (D_FLT_002BD450 < (fabsf(temp_f0) - temp_v0_2)) {
block_25:
                            RetractSwRoot(arg0, var_s2);
                            goto block_32;
                        }
                    }
                } else if (temp_a0_2 != 2) {
                    var_s0 = arg0 + 0x2C;
                    if (temp_a0_2 != 3) {

                    } else {
                        if (!(temp_s5 & M2C_FIELD(temp_s1, u8 *, 0x2D))) {
                            var_s4 = 0;
                        } else {
                            var_s4 = 1;
                            PosLoWorld(temp_s1, var_a1);
                            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                            M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x20($sp) */);
                            M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
                            M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                            M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                            M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                            M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                            M2C_ERROR(/* unknown instruction: vwaitq */);
                            M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                            temp_f0_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) - M2C_FIELD(temp_s1, f32 *, 0x38);
                            if (!(temp_f0_2 < 0.0f)) {
                                var_s4 = 0;
                            }
                            if (D_FLT_002BD450 < (fabsf(temp_f0_2) - temp_v0_3)) {
                                RetractSwRoot(arg0, var_s2);
                            }
                        }
                        goto block_32;
                    }
                } else {
                    var_s4 = 0;
                    goto block_19;
                }
            } else {
                var_s4 = 1;
block_19:
                RemoveSwRootRaw(arg0, var_s2);
block_32:
                var_s0 = arg0 + 0x2C;
            }
            if (var_s4 != FFindDlEntry(var_s0, var_s2)) {
                if (var_s4 == 0) {
                    temp_v0_5 = M2C_FIELD(temp_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_5, M2C_UNK (**)(void *), 0xB4)(temp_s1 + M2C_FIELD(temp_v0_5, s16 *, 0xB0));
                    RemoveDlEntry(var_s0, var_s2);
                } else {
                    AppendDlEntry(var_s0, var_s2);
                    temp_v0_6 = M2C_FIELD(temp_s1, void **, 0xC);
                    M2C_FIELD(temp_v0_6, M2C_UNK (**)(void *), 0xBC)(temp_s1 + M2C_FIELD(temp_v0_6, s16 *, 0xB8));
                }
            }
            temp_a0_3 = *sp4;
            var_a1 = M2C_FIELD(arg0, s32 *, 0x39A4);
            var_s2 = temp_a0_3;
            sp4 = temp_a0_3 + sp8;
        } while (var_s2 != var_a1);
    }
    g_2dd2fc = spC;
}
