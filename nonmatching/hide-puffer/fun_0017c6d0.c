#include "m2c_macros.h"

M2C_UNK ConvertAloPos(s32, M2C_UNK, s128);          /* extern */
s128 PosLoWorld(s32);                               /* extern */
M2C_UNK SetGoalTarget(s32, void *, s128);           /* extern */
M2C_UNK func_0017C928(void *, M2C_UNK);             /* extern */
M2C_UNK func_001EEF98();                            /* extern */
s32 func_001EF0A8(void *);                          /* extern */
s32 func_00209098(s32);                             /* extern */
M2C_UNK func_002562A8(void *);                      /* extern */

void func_0017C6D0(void *arg0) {
    char sp[0x400];
    s128 sp20;
    f32 temp_v0;
    s32 temp_s2;

    func_001EEF98();
    sp20 = PosLoWorld(M2C_FIELD(arg0, s32 *, 0x30));
    PosLoWorld(M2C_FIELD(arg0, s32 *, 0x10));
    M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf2, $vf3 */);
    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
    M2C_ERROR(/* unknown instruction: vwaitq */);
    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
    temp_v0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
loop_25:
    if (func_001EF0A8(arg0) == 0) {
        temp_s2 = M2C_FIELD(arg0, s32 *, 0x50);
        switch (temp_s2) {                          /* irregular */
        case 0:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                if (!(temp_v0 > 1000.0f)) {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($s1) */);
                    M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                    M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 250.0f) {
                        M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                        ConvertAloPos(M2C_FIELD(arg0, s32 *, 0x30), 0, M2C_FIELD(arg0, s128 *, 0x40));
                        func_002562A8(sp);
                        SetGoalTarget(M2C_FIELD(arg0, s32 *, 0x18), sp, M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */));
                    }
                } else {
                    func_0017C928(arg0, 1);
                }
            } else {
block_15:
                func_0017C928(arg0, 2);
            }
            break;
        case 1:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) != 0) {
                goto block_15;
            }
            if (!(temp_v0 < 700.0f)) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x60($s1) */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf1, $vf2 */);
                M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                if (M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) > 250.0f) {
                    M2C_FIELD(arg0, s128 *, 0x60) = (s128) M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf2 */);
                    func_002562A8(sp);
                    SetGoalTarget(M2C_FIELD(arg0, s32 *, 0x18), sp, sp20);
                }
            } else {
                func_0017C928(arg0, 0);
            }
            break;
        case 2:
            if (func_00209098(M2C_FIELD(arg0, s32 *, 0x10)) == 0) {
                func_0017C928(arg0, 0);
            }
            break;
        }
        if (temp_s2 != M2C_FIELD(arg0, s32 *, 0x50)) {
            goto loop_25;
        }
    }
}
