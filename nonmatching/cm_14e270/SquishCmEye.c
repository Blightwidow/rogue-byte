#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct(M2C_UNK *);           /* extern */
M2C_UNK CStackFrame_Destructor(M2C_UNK *, M2C_UNK); /* extern */
s32 CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_UNK, void *, s32, M2C_UNK, f32); /* extern */
M2C_UNK LimitVectorLength__FP6VECTORfT0(M2C_UNK, f32); /* extern */
f32 *PvAllocStackImpl__Fi(s32 *);                   /* extern */
M2C_UNK SolveInequalities(s32, f32 *, f32 *, f32 *, f32); /* extern */
extern f32 D_FLT_002BD8D4;

s128 SquishCmEye(s32 arg0, s32 arg1, void **arg2, f32 (*arg3)(s32, M2C_UNK, s128, void *), f32 fparg0, f32 fparg1) {
    char sp[0x400];
    M2C_UNK spC40;
    M2C_UNK sp10;
    M2C_UNK spC00;
    s32 spC10;
    s32 spC20;
    f32 (*spC24)(s32, M2C_UNK, s128, void *);
    s128 spC30;
    f32 *temp_s1;
    f32 *temp_v0_2;
    f32 *temp_v0_3;
    f32 *var_s4;
    f32 *var_s4_2;
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_v1;
    s32 var_s0;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    s32 var_s5;
    s32 var_v1;
    void **var_s1;
    void *temp_a1;
    void *temp_a3;
    void *temp_v0;
    void *var_s0_2;

    var_s5 = 0;
    M2C_ERROR(/* unknown instruction: por $s6, $zero, $t0 */);
    spC20 = arg0;
    spC24 = arg3;
    spC30 = M2C_ERROR(/* Read from unset register $t1 */);
    if (arg1 > 0) {
        var_s1 = arg2;
        var_s0 = arg1;
        do {
            temp_v0 = *var_s1;
            temp_a1 = temp_v0;
            temp_a2 = M2C_FIELD(temp_v0, s32 *, 0x70) * 0xC;
            temp_v1 = M2C_FIELD(temp_v0, s32 *, 0x74);
            var_s1 += 4;
            var_s0 -= 1;
            var_s5 += CsbiIntersectSphereBsp__FP6VECTORfiP3BSPT3P4GEOMiP3SBI(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s6 */), temp_a1, temp_v1 + temp_a2, 0, fparg0);
        } while (var_s0 != 0);
    }
    if (var_s5 == 0) {
        return spC30;
    }
    CStackFrame_Construct(&spC00);
    temp_s2 = var_s5 * 4;
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf0, $vf0 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf1, 0xc50($sp) */);
    var_s3 = 0;
    spC10 = var_s5 * var_s5 * 4;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_v0_2 = PvAllocStackImpl__Fi(&spC10);
    spC10 = temp_s2;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_v0_3 = PvAllocStackImpl__Fi(&spC10);
    var_s4 = temp_v0_2;
    spC10 = temp_s2;
    M2C_FIELD(&spC10, s32 *, 4) = 0x10;
    temp_s1 = PvAllocStackImpl__Fi(&spC10);
    if (var_s5 > 0) {
        do {
            if (var_s5 > 0) {
                var_v1 = var_s5;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                    var_v1 -= 1;
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, ($v0) */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf2, $vf2, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf2, $vf2y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf2, $vf3, $vf2z */);
                    *var_s4 = M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf2 */);
                    var_s4 += 4;
                } while (var_v1 != 0);
            }
            var_s3 += 1;
        } while (var_s3 < var_s5);
    }
    var_s4_2 = temp_v0_3;
    if (var_s5 > 0) {
        var_s0_2 = sp;
        var_s3_2 = var_s5;
        do {
            temp_a3 = var_s0_2;
            var_s0_2 += 0x30;
            var_s3_2 -= 1;
            *var_s4_2 = spC24(spC20, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s6 */), spC30, temp_a3);
            var_s4_2 += 4;
        } while (var_s3_2 != 0);
    }
    SolveInequalities(var_s5, temp_v0_2, temp_v0_3, temp_s1, D_FLT_002BD8D4 * fparg1);
    M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xc50($sp) */);
    if (var_s5 > 0) {
        var_s3_3 = var_s5;
        do {
            var_s3_3 -= 1;
            M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf2 */);
            M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc10($sp) */);
            M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($v0) */);
            M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
            M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
        } while (var_s3_3 != 0);
    }
    LimitVectorLength__FP6VECTORfT0(M2C_ERROR(/* unknown instruction: qmfc2.ni $a0, $vf3 */), fparg1);
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0xc30($sp) */);
    M2C_ERROR(/* unknown instruction: vadd.xyzw $vf2, $vf1, $vf2 */);
    M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0xc40($sp) */);
    CStackFrame_Destructor(&spC00, 2);
    return spC40;
}
