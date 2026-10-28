#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 IcgvFromPcgv__FP2CGP3CGV(s32 *, M2C_UNK *);     /* extern */
s32 PvAllocStackClearImpl__Fi(s32 *, M2C_UNK);      /* extern */
M2C_UNK *PvAllocStackImpl__Fi(s32 *);               /* extern */

void FindPathAStar__FP2CGP3CGVT1iPiPP3CGV(s32 *arg0, s32 arg1, s32 arg2) {
    char sp[0x400];
    M2C_UNK sp20;
    s32 sp30;
    M2C_UNK *sp40;
    s32 *sp44;
    s32 *sp48;
    M2C_UNK **var_a0;
    M2C_UNK *temp_s0;
    M2C_UNK *temp_v0;
    M2C_UNK *var_s1;
    M2C_UNK *var_s4;
    M2C_UNK *var_v0_2;
    f32 temp_f1;
    f32 var_f1;
    s32 *temp_v1;
    s32 temp_fp;
    s32 var_s2;
    s32 var_v0;
    void *temp_s3;

    sp48 = M2C_ERROR(/* Read from unset register $t1 */);
    sp44 = M2C_ERROR(/* Read from unset register $t0 */);
    CStackFrame_Construct(&sp20);
    sp30 = *arg0 * 4;
    M2C_FIELD(&sp30, s32 *, 4) = 0x10;
    temp_fp = PvAllocStackClearImpl__Fi(&sp30, 0x10);
    var_s1 = sp;
    *sp48 = arg1;
    sp40 = NULL;
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s0) */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s6) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    M2C_ERROR(/* unknown instruction: qmfc2.ni $v1, $vf1 */);
    if (arg1 != arg2) {
        var_s4 = *sp;
loop_2:
        var_s2 = 0;
        if (M2C_FIELD(var_s4, s32 *, 0x10) > 0) {
loop_4:
            temp_s3 = M2C_FIELD(var_s4, s32 *, 0x14) + (var_s2 * 8);
            temp_s0 = M2C_FIELD(temp_s3, M2C_UNK **, 0);
            if (temp_s0 == arg2) {
                var_v0 = 0;
            } else {
                temp_v1 = (IcgvFromPcgv__FP2CGP3CGV(arg0, temp_s0) * 4) + temp_fp;
                var_v0 = 1;
                if (*temp_v1 == 0) {
                    var_v0 = 0;
                    *temp_v1 = 1;
                }
            }
            var_s2 += 1;
            if (var_v0 == 0) {
                sp30 = 0x18;
                M2C_FIELD(&sp30, s32 *, 4) = 0x10;
                temp_v0 = PvAllocStackImpl__Fi(&sp30);
                var_a0 = &sp40;
                M2C_FIELD(temp_v0, M2C_UNK **, 0) = temp_s0;
                temp_f1 = M2C_FIELD(var_s1, f32 *, 8) + M2C_FIELD(temp_s3, f32 *, 4);
                M2C_FIELD(temp_v0, f32 *, 8) = temp_f1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($s4) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($s6) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_FIELD(temp_v0, M2C_UNK **, 0xC) = var_s1;
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                var_f1 = temp_f1 + M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                M2C_FIELD(temp_v0, f32 *, 4) = var_f1;
                M2C_FIELD(temp_v0, s32 *, 0x10) = (s32) (M2C_FIELD(var_s1, s32 *, 0x10) + 1);
                var_v0_2 = sp40;
                if (var_v0_2 != NULL) {
loop_13:
                    if (!(var_f1 < M2C_FIELD(var_v0_2, f32 *, 4))) {
                        var_a0 = &*(var_v0_2 + 0x14);
                        var_v0_2 = M2C_FIELD(var_v0_2, M2C_UNK **, 0x14);
                        if (var_v0_2 != NULL) {
                            var_f1 = M2C_FIELD(temp_v0, f32 *, 4);
                            goto loop_13;
                        }
                    }
                }
                M2C_FIELD(temp_v0, M2C_UNK **, 0x14) = var_v0_2;
                *var_a0 = temp_v0;
            }
            if (var_s2 < M2C_FIELD(var_s4, s32 *, 0x10)) {
                goto loop_4;
            }
        }
        var_s1 = sp40;
        if (var_s1 != NULL) {
            sp40 = M2C_FIELD(var_s1, M2C_UNK **, 0x14);
            if (M2C_FIELD(var_s1, M2C_UNK **, 0) != arg2) {
                var_s4 = M2C_FIELD(var_s1, M2C_UNK **, 0);
                goto loop_2;
            }
            goto block_24;
        }
        goto block_29;
    }
block_24:
    if (var_s1 != NULL) {
        *sp44 = M2C_FIELD(var_s1, s32 *, 0x10);
        do {
            M2C_FIELD(&sp48[M2C_FIELD(var_s1, s32 *, 0x10)], M2C_UNK **, -4) = (M2C_UNK *) M2C_FIELD(var_s1, M2C_UNK **, 0);
            var_s1 = M2C_FIELD(var_s1, M2C_UNK **, 0xC);
        } while (var_s1 != NULL);
    } else {
block_29:
        *sp44 = 0;
    }
    CStackFrame_Destructor(&sp20, 2);
}
