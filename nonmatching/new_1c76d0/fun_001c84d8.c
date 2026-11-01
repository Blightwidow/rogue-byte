#include "m2c_macros.h"

M2C_UNK EnsureSggAlarm__FP3SGGP5ALARM(); /* extern */
s32 FAsegaGone();                                /* extern */
s32 FButtonPressedWithin(); /* extern */
M2C_UNK func_001C8918(); /* extern */
extern f32 D_FLT_002C0FE8;
extern f32 g_2dded0;

void func_001C84D8(void *arg0) {
    M2C_UNK RO_FLT_002A7798;
    f32 var_f0;
    f32 var_f1;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v1;
    u32 temp_t0;
    u32 var_a0;
    u32 var_v1;

    do {
        temp_s1 = M2C_FIELD(arg0, s32 *, 0x188);
        if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0x30, 0) != 0) {
            EnsureSggAlarm__FP3SGGP5ALARM(M2C_FIELD(arg0, s32 *, 0x19C), 0x655);
            func_001C8918(arg0, 3);
        }
        temp_v1 = M2C_FIELD(arg0, s32 *, 0x188);
        switch (temp_v1) {                          /* irregular */
        case 0:
            if (FButtonPressedWithin(M2C_FIELD(arg0, void **, 0x150), 0xC0, 0) != 0) {
                func_001C8918(arg0, 2);
            } else {
                temp_t0 = M2C_FIELD(arg0, u32 *, 0x194);
                M2C_ERROR(/* unknown instruction: pextlw $v1, $v0, $v1 */);
                M2C_ERROR(/* unknown instruction: pcpyld $v1, $v0, $v1 */);
                M2C_ERROR(/* unknown instruction: qmtc2.ni $v1, $vf3 */);
                var_f1 = 3.4028235e38f;
                var_a0 = -1U;
                var_v1 = 0;
                do {
                    M2C_ERROR(/* unknown instruction: lqc2 $vf1, ($a1) */);
                    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                    M2C_ERROR(/* unknown instruction: vaddw.x $vf2, $vf0, $vf0w */);
                    M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                    M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf2, $vf1z */);
                    M2C_ERROR(/* unknown instruction: vwaitq */);
                    M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                    var_f0 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                    if (var_v1 == temp_t0) {
                        var_f0 *= D_FLT_002C0FE8;
                    }
                    if (var_f0 < var_f1) {
                        var_f1 = var_f0;
                        var_a0 = var_v1;
                    }
                    var_v1 += 1;
                } while (var_v1 < 9U);
                if (var_a0 != temp_t0) {
                    M2C_FIELD(arg0, u32 *, 0x194) = var_a0;
                    func_001C8918(arg0, 1, &RO_FLT_002A7798, temp_t0);
                }
            }
            break;
        case 2:
            temp_a0 = M2C_FIELD(arg0, s32 *, 0x1A0);
            if ((temp_a0 == 0) || (FAsegaGone(temp_a0) != 0)) {
                temp_v0 = ((s32) (M2C_FIELD(arg0, s32 *, 0x198) * 0xA) % 1000) + 1 + M2C_FIELD(arg0, u32 *, 0x194);
                M2C_FIELD(arg0, s32 *, 0x198) = temp_v0;
                if (temp_v0 == M2C_FIELD(arg0, s32 *, 0x1F0)) {
                    EnsureSggAlarm__FP3SGGP5ALARM(M2C_FIELD(arg0, s32 *, 0x19C), 0x655);
                    func_001C8918(arg0, 3);
                } else {
                    func_001C8918(arg0, 0);
                }
            }
            break;
        case 1:
            if (M2C_FIELD(M2C_FIELD(arg0, void **, 0x204), f32 *, 0xA8) <= g_2dded0) {
                func_001C8918(arg0, 0);
            }
            break;
        }
    } while (M2C_FIELD(arg0, s32 *, 0x188) != temp_s1);
}
