#include "m2c_macros.h"

M2C_UNK CStackFrame_Construct();              /* extern */
M2C_UNK CStackFrame_Destructor();    /* extern */
s128 LimitVectorLength__FP6VECTORfT0();    /* extern */
M2C_UNK PvAllocStackImpl__Fi();       /* extern */

void ApplyDzg(void *arg0, f32 fparg0, f32 fparg1) {
    char sp[0x400];
    s32 sp10;
    u8 *temp_v0;
    s32 var_a0;
    s32 var_a2;
    s32 var_s1;
    s32 var_v1;
    void *temp_s0;

    CStackFrame_Construct(sp);
    sp10 = M2C_FIELD(arg0, s32 *, 0x58) << 5;
    M2C_FIELD(&sp10, s32 *, 4) = 0x10;
    PvAllocStackImpl__Fi(&sp10, 0x10);
    var_a0 = 0;
    if (M2C_FIELD(arg0, s32 *, 4) > 0) {
        var_v1 = 0 * 0x28;
        do {
            if (M2C_FIELD((M2C_FIELD(arg0, s32 *, 8) + var_v1), f32 *, 0xC) != 0.0f) {
                var_a2 = 0;
                do {
                    if (M2C_FIELD((M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x60) + (var_a0 * 0x60)), s32 *, 0x50) + (var_a2 << 6)), s32 *, 8) != 0) {
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf3, 0xf0($s0) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a0) */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf3 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf3, $vf1, $vf2x */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x100($s0) */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf3, 0xf0($s0) */);
                        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf2 */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf2, 0x10($sp) */);
                        M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x10($a0) */);
                        M2C_ERROR(/* unknown instruction: vadda.xyzw $acc, $vf0, $vf4 */);
                        M2C_ERROR(/* unknown instruction: vmaddx.xyzw $vf4, $vf1, $vf2x */);
                        M2C_ERROR(/* unknown instruction: sqc2 $vf4, 0x100($s0) */);
                    }
                    var_a2 += 1;
                } while (var_a2 < 2);
            }
            var_a0 += 1;
            var_v1 = var_a0 * 0x28;
        } while (var_a0 < M2C_FIELD(arg0, s32 *, 4));
    }
    var_s1 = 0;
    if (M2C_FIELD(arg0, s32 *, 0x58) > 0) {
loop_10:
        temp_v0 = var_s1 * 4;
        var_s1 += 1;
        temp_s0 = *(temp_v0 + M2C_FIELD(arg0, s32 *, 0x5C));
        M2C_FIELD(temp_s0, s128 *, 0xF0) = LimitVectorLength__FP6VECTORfT0(M2C_FIELD(temp_s0, s128 *, 0xF0), fparg0);
        M2C_FIELD(temp_s0, s128 *, 0x100) = LimitVectorLength__FP6VECTORfT0(M2C_FIELD(temp_s0, s128 *, 0x100), fparg1);
        if (var_s1 < M2C_FIELD(arg0, s32 *, 0x58)) {
            goto loop_10;
        }
    }
    CStackFrame_Destructor(sp, 2);
}
