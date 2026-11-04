#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *, s128 *, void *, M2C_UNK *); /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 *PvAllocStackImpl__Fi(s32 *);                   /* extern */
M2C_UNK SetJmpBodyState(void *, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK SolveInequalities(s32, s32 *, s32 *, s32 *, f32); /* extern */
extern M2C_UNK g_2a2dc0;

void LimitJmpAccelByContacts(void *arg0, s128 *arg1, s32 arg2, M2C_UNK *arg3) {
    M2C_UNK unksp;
    s32 sp400;
    M2C_UNK sp410;
    s128 sp420;
    s128 sp430;
    M2C_UNK *var_a3;
    s128 *temp_s7;
    s128 *var_a1;
    s128 temp_v0_3;
    s32 *temp_s0;
    s32 *temp_v0;
    s32 *temp_v0_2;
    s32 *var_a1_2;
    s32 *var_a1_3;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v1;
    u32 var_s3;
    u32 var_v1_2;
    u32 var_v1_3;
    u32 var_v1_4;
    void *var_a0;
    void *var_a2;

    var_a1 = arg1;
    var_a3 = arg3;
    var_s3 = 0;
    temp_s7 = var_a1;
    var_a2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xEC), void **, 0x64);
loop_1:
    if (var_a2 == NULL) {
        var_a0 = M2C_FIELD(M2C_FIELD(M2C_FIELD(arg0, void **, 0), void **, 0xEC), void **, 0x68);
    } else {
        var_a0 = M2C_FIELD(var_a2, void **, 0);
    }
    if (var_a0 != NULL) {
        var_a1 = &unksp-10 + (var_s3 * 0x10);
        var_a3 = &g_2a2dc0;
        var_v0 = var_s3 < 0x40U;
loop_8:
        if (var_v0 != 0) {
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x80($a0) */);
            if (M2C_FIELD(arg0, void **, 0) != M2C_FIELD(var_a0, s32 *, 8)) {
                M2C_ERROR(/* unknown instruction: qmtc2.ni $t0, $vf1 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0x400($sp) */);
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf4, $vf4, $vf1x */);
            }
            M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf4 */);
            if (!(M2C_ERROR(/* unknown instruction: pextuw $v0, $zero, $v0 */) > 0.7f)) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a3) */);
                var_a1 += 0x10;
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf4, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                var_s3 += 1;
                M2C_ERROR(/* unknown instruction: vmulx.xyzw $vf2, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf4, $vf4, $vf2 */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf4, ($a1) */);
            }
            var_a0 = M2C_FIELD(var_a0, void **, 0xAC);
            var_v0 = var_s3 < 0x40U;
            if (var_a0 == NULL) {
                goto block_14;
            }
            goto loop_8;
        }
    } else {
block_14:
        if (var_a2 != NULL) {
            var_a2 = M2C_FIELD(var_a2, void **, 4);
            goto loop_1;
        }
    }
    if (var_s3 != 0) {
        temp_s2 = var_s3 * 4;
        CStackFrame_Construct(&sp410, var_a1, var_a2, var_a3);
        sp400 = var_s3 * var_s3 * 4;
        M2C_FIELD(&sp400, s32 *, 4) = 0x10;
        temp_v0 = PvAllocStackImpl__Fi(&sp400);
        sp400 = temp_s2;
        M2C_FIELD(&sp400, s32 *, 4) = 0x10;
        temp_v0_2 = PvAllocStackImpl__Fi(&sp400);
        sp400 = temp_s2;
        M2C_FIELD(&sp400, s32 *, 4) = 0x10;
        temp_s0 = PvAllocStackImpl__Fi(&sp400);
        var_a1_2 = temp_v0;
        var_v1 = 0;
        if ((s32) var_s3 > 0) {
            do {
                if ((s32) var_s3 > 0) {
                    var_v1_2 = var_s3;
                    do {
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                        var_v1_2 -= 1;
                        M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                        M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                        M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                        M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                        *var_a1_2 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf2 */);
                        var_a1_2 += 4;
                    } while (var_v1_2 != 0);
                }
                var_v1 += 1;
            } while (var_v1 < (s32) var_s3);
        }
        temp_v0_3 = *temp_s7;
        var_a1_3 = temp_v0_2;
        sp420 = temp_v0_3;
        sp430 = temp_v0_3;
        if ((s32) var_s3 > 0) {
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
            var_v1_3 = var_s3;
            do {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
                var_v1_3 -= 1;
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf3, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                *var_a1_3 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf1 */);
                var_a1_3 += 4;
            } while (var_v1_3 != 0);
        }
        SolveInequalities((s32) var_s3, temp_v0, temp_v0_2, temp_s0, 3.4028235e38f);
        if ((s32) var_s3 > 0) {
            var_v1_4 = var_s3;
            do {
                var_v1_4 -= 1;
                M2C_ERROR(/* unknown instruction: qmtc2.ni $a1, $vf2 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x420($sp) */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x400($sp) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
                M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0x420($sp) */);
            } while (var_v1_4 != 0);
        }
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x430($sp) */);
        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0x420($sp) */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
        M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
        M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
        if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 1.0f) {
            temp_v1 = M2C_FIELD(arg0, s32 *, 0x1C);
            switch (temp_v1) {                      /* irregular */
            case 2:
                SetJmpBodyState(arg0, 3, 0);
                break;
            case 0:
                SetJmpBodyState(arg0, 1, 0);
                break;
            }
        }
        *temp_s7 = sp420;
        CStackFrame_Destructor(&sp410, 2);
    }
}
