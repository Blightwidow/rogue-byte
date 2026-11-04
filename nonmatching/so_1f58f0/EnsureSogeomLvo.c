#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct();           /* extern */
M2C_UNK CStackFrame_Destructor(); /* extern */
s32 PvAllocStackClearImpl__Fi();               /* extern */
s32 PvAllocSwClearImpl__Fi();                  /* extern */
void *PvAllocSwImpl__Fi();                     /* extern */

void EnsureSogeomLvo(void *arg0) {
    M2C_UNK sp30;
    s32 sp40;
    s32 *temp_a0;
    s32 *temp_t0;
    s32 *var_v1;
    s32 temp_t1;
    u8 *temp_t2;
    s32 temp_t7;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;
    s32 var_v0_2;
    u16 temp_a3;
    u16 temp_a3_2;
    void *temp_t0_2;

    if (M2C_FIELD(arg0, void **, 0x10) == NULL) {
        CStackFrame_Construct(&sp30);
        sp40 = 0xC;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(arg0, void **, 0x10) = PvAllocSwImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x90) * 0x10;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 0) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x90) * 0x10;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 4) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x98) * 0xC;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) = PvAllocSwClearImpl__Fi(&sp40);
        sp40 = M2C_FIELD(arg0, s32 *, 0x98) * 4;
        M2C_FIELD(&sp40, s32 *, 4) = 0x10;
        temp_t7 = PvAllocStackClearImpl__Fi(&sp40);
        var_a0 = 0;
        if (M2C_FIELD(arg0, s32 *, 0xA0) > 0) {
            do {
                var_a1 = 0;
                temp_t2 = M2C_FIELD(arg0, s32 *, 0xA4) + (var_a0 * 0x10);
                var_v0 = 0 * 2;
loop_4:
                temp_a3 = *(temp_t2 + 4 + var_v0);
                var_a2 = 0;
                temp_a0 = (temp_a3 * 4) + temp_t7;
                temp_t0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) + (temp_a3 * 0xC);
                var_v0_2 = 0 * 2;
loop_5:
                temp_t1 = var_a2 + 1;
                temp_a3_2 = *(temp_t2 + var_v0_2);
                var_a1_2 = 0;
                if (*temp_a0 > 0) {
                    if (temp_a3_2 != *temp_t0) {
                        var_v1 = temp_t0;
loop_8:
                        var_a1_2 += 1;
                        var_v1 += 4;
                        if (var_a1_2 < *temp_a0) {
                            if (temp_a3_2 == *var_v1) {
                                goto block_10;
                            }
                            goto loop_8;
                        }
                        goto block_11;
                    }
block_10:
                    var_a2 = temp_t1;
                    if (var_a1_2 >= *temp_a0) {
                        goto block_11;
                    }
                } else {
block_11:
                    var_a2 = temp_t1;
                    if (var_a1_2 < 3) {
                        *(temp_t0 + (*temp_a0 * 4)) = (s32) temp_a3_2;
                        *temp_a0 += 1;
                    }
                }
                var_v0_2 = var_a2 * 2;
                if (var_a2 < 2) {
                    goto loop_5;
                }
                var_a1 += 1;
                var_v0 = var_a1 * 2;
                if (var_a1 < 2) {
                    goto loop_4;
                }
                var_a0 += 1;
            } while (var_a0 < M2C_FIELD(arg0, s32 *, 0xA0));
        }
        var_a3 = 0;
        if (M2C_FIELD(arg0, s32 *, 0x98) > 0) {
            var_t1 = 0;
            do {
                temp_t0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x10), s32 *, 8) + var_t1;
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, ($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, ($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v1) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf1 */);
                M2C_ERROR(/* unknown instruction: vopmula.xyz $acc, $vf3, $vf2 */);
                M2C_ERROR(/* unknown instruction: vopmsub.xyz $vf3, $vf2, $vf3 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf3, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf3, $vf3y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf3, $vf2, $vf3z */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf3 */) < 0.0f) {
                    temp_v1 = M2C_FIELD(temp_t0_2, s32 *, 8);
                    M2C_FIELD(temp_t0_2, s32 *, 8) = (s32) M2C_FIELD(temp_t0_2, s32 *, 4);
                    M2C_FIELD(temp_t0_2, s32 *, 4) = temp_v1;
                }
                var_a3 += 1;
                var_t1 += 0xC;
            } while (var_a3 < M2C_FIELD(arg0, s32 *, 0x98));
        }
        CStackFrame_Destructor(&sp30, 2, M2C_FIELD(arg0, s32 *, 0x7C), var_a3);
    }
}
