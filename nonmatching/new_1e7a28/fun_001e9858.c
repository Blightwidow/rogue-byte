#include "m2c_macros.h"

M2C_UNK BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(s128 *, s128, s128); /* extern */
M2C_UNK CopyAb__FPvT0Ui(void *, s32, s32);          /* extern */
M2C_UNK FindCrvClosestPointAll(s32, M2C_UNK, M2C_UNK, s32 *); /* extern */
void *PmatLoWorld(void *);                          /* extern */
M2C_UNK PostSoLoad();                               /* extern */
void *PvAllocSwImpl__Fi(s32 *);                     /* extern */
M2C_UNK func_0016EF00(void *, s32, s32);            /* extern */
extern M2C_UNK D_002C44F0;

void func_001E9858(void *arg0) {
    char sp[0x400];
    s32 sp800;
    s128 sp810;
    s128 sp820;
    s128 sp830;
    s128 sp840;
    s128 sp850;
    s128 sp860;
    s128 sp870;
    s128 sp880;
    s128 sp890;
    s128 sp8A0;
    f32 sp8B0;
    s128 sp8C0;
    s32 sp8D0;
    M2C_UNK *temp_fp;
    s128 temp_t1;
    s128 temp_t2;
    s128 temp_t3;
    s32 temp_a1;
    s32 temp_a2;
    s32 var_s0;
    s32 var_s5;
    s32 var_v0;
    void *temp_s1;
    void *temp_v1;
    void *var_s0_2;
    void *var_s4;

    PostSoLoad();
    if (M2C_FIELD(arg0, s32 *, 0x150) != 0) {
        if (M2C_FIELD(arg0, void **, 0xDC) != NULL) {
            sp8C0 = M2C_FIELD(PmatLoWorld(arg0), s128 *, 0x20);
            var_s4 = M2C_FIELD(arg0, void **, 0xDC);
            if (var_s4 != NULL) {
loop_4:
                var_s0 = 0;
                temp_a1 = (s32) ((M2C_FIELD(var_s4, s32 *, 0) - M2C_FIELD(arg0, s32 *, 0xBC)) * 0xCCCCCCCD) >> 2;
                temp_a2 = temp_a1 * 0x28;
                temp_v1 = M2C_FIELD(arg0, s32 *, 0xC0) + temp_a2;
                temp_fp = M2C_FIELD(temp_v1, M2C_UNK **, 4);
                M2C_FIELD(temp_v1, M2C_UNK **, 4) = &D_002C44F0;
                func_0016EF00(arg0 + 0x80, temp_a1, temp_a2);
                if (M2C_FIELD(var_s4, s32 *, 4) > 0) {
                    var_v0 = 0 << 5;
                    do {
                        sp8D0 = var_s0 + 1;
                        temp_s1 = M2C_FIELD(var_s4, s32 *, 8) + var_v0;
                        var_s5 = 0;
                        CopyAb__FPvT0Ui(sp, M2C_FIELD(temp_s1, s32 *, 0xC), M2C_FIELD(temp_s1, s32 *, 0) * 0x10);
                        sp800 = M2C_FIELD(temp_s1, s32 *, 0) * 0x10;
                        M2C_FIELD(&sp800, s32 *, 4) = 0x10;
                        var_s0_2 = PvAllocSwImpl__Fi(&sp800);
                        M2C_FIELD(temp_s1, void **, 0x1C) = var_s0_2;
                        if (M2C_FIELD(temp_s1, s32 *, 0) > 0) {
                            do {
                                M2C_ERROR(/* unknown instruction: lqc2 $vf5, ($s2) */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($s3) */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($s3) */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x30($s3) */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x40($fp) */);
                                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf3, $vf5x */);
                                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf4, $vf5y */);
                                M2C_ERROR(/* unknown instruction: vmaddaz.xyz $acc, $vf2, $vf5z */);
                                M2C_ERROR(/* unknown instruction: vmaddw.xyz $vf3, $vf1, $vf0w */);
                                var_s5 += 1;
                                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x8e0($sp) */);
                                FindCrvClosestPointAll(M2C_FIELD(arg0, s32 *, 0x150), M2C_ERROR(/* unknown instruction: qmfc2.ni $a1, $vf3 */), 0, &sp800);
                                BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(&sp850, sp810, sp8C0);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x800($sp) */);
                                M2C_ERROR(/* unknown instruction: pextlw $a1, $a3, $a2 */);
                                M2C_ERROR(/* unknown instruction: pextuw $a0, $a3, $a2 */);
                                M2C_ERROR(/* unknown instruction: pextlw $v1, $zero, $t0 */);
                                M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $t0 */);
                                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x8e0($sp) */);
                                M2C_ERROR(/* unknown instruction: pcpyld $t1, $v1, $a1 */);
                                M2C_ERROR(/* unknown instruction: pcpyud $t2, $a1, $v1 */);
                                M2C_ERROR(/* unknown instruction: pcpyld $t3, $v0, $a0 */);
                                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
                                temp_t2 = M2C_ERROR(/* unknown instruction: qmtc2.ni $t2, $vf2 */);
                                temp_t1 = M2C_ERROR(/* unknown instruction: qmtc2.ni $t1, $vf1 */);
                                sp820 = sp850;
                                temp_t3 = M2C_ERROR(/* unknown instruction: qmtc2.ni $t3, $vf4 */);
                                sp830 = sp860;
                                sp840 = sp870;
                                M2C_ERROR(/* unknown instruction: vmulax.xyz $acc, $vf1, $vf3x */);
                                M2C_ERROR(/* unknown instruction: vmadday.xyz $acc, $vf2, $vf3y */);
                                M2C_ERROR(/* unknown instruction: vmaddz.xyz $vf3, $vf4, $vf3z */);
                                sp850 = temp_t1;
                                sp860 = temp_t2;
                                sp870 = temp_t3;
                                sp880 = temp_t1;
                                sp890 = temp_t2;
                                sp8A0 = temp_t3;
                                M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($s0) */);
                                M2C_FIELD(var_s0_2, f32 *, 0xC) = sp8B0;
                                var_s0_2 += 0x10;
                            } while (var_s5 < M2C_FIELD(temp_s1, s32 *, 0));
                        }
                        var_s0 = sp8D0;
                        var_v0 = var_s0 << 5;
                    } while (var_s0 < M2C_FIELD(var_s4, s32 *, 4));
                }
                var_s4 = M2C_FIELD(var_s4, void **, 0xC);
                if (var_s4 != NULL) {
                    goto loop_4;
                }
            }
        }
    }
}
