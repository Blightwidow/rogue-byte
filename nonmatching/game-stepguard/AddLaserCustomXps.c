#include "m2c_macros.h"

s32 ClsgClipEdgeToObject(void *, s128, s128, M2C_UNK); /* extern */
s32 FIsBasicDerivedFrom(s32, M2C_UNK);              /* extern */
M2C_UNK GetLaserBeamPoints(void *, s32, s128 *, M2C_UNK); /* extern */
M2C_UNK PxpAdd(M2C_UNK *, s32, void *, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK QueueSwCallbackOnce(M2C_UNK *, void *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_001F5990();                            /* extern */
s32 func_00205670(s32, s128, s128, s128 *);         /* extern */
extern M2C_UNK B_003DD490;

void AddLaserCustomXps(void *arg0, void *arg1) {
    M2C_UNK sp20;
    s128 sp10;
    s128 sp30;
    s128 sp40;
    s32 temp_s0;
    s32 temp_s3;
    s32 var_s1;
    s32 var_s4;

    var_s4 = 0;
    func_001F5990();
    if (M2C_FIELD(arg0, s32 *, 0x198) > 0) {
        do {
            var_s1 = 0;
            temp_s3 = M2C_FIELD(arg0, s32 *, 0x19C) + (var_s4 * 0x150);
            GetLaserBeamPoints(arg0, temp_s3, &sp10, 0);
            if (ClsgClipEdgeToObject(arg1, sp10, sp20, 1) == 0) {
                temp_s0 = *M2C_FIELD(M2C_FIELD(arg1, void **, 4), s32 **, 0x14);
                if (FIsBasicDerivedFrom(temp_s0, 0x33) != 0) {
                    var_s1 = func_00205670(temp_s0, sp10, sp20, &sp30);
                }
            } else {
                var_s1 = 1;
                sp30 = sp40;
            }
            M2C_ERROR(/* unknown instruction: lqc2 $vf4, 0x10($sp) */);
            if (var_s1 != 0) {
                M2C_ERROR(/* unknown instruction: lqc2 $vf5, 0x30($sp) */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf4, $vf5 */);
                M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x20($sp) */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf1, $vf1, $vf1 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf1, $vf1y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf1, $vf3, $vf1z */);
                M2C_ERROR(/* unknown instruction: vsub.xyzw $vf2, $vf2, $vf4 */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vmul.xyz $vf4, $vf2, $vf2 */);
                M2C_ERROR(/* unknown instruction: vaddw.x $vf3, $vf0, $vf0w */);
                M2C_ERROR(/* unknown instruction: vadday.x $acc, $vf4, $vf4y */);
                M2C_ERROR(/* unknown instruction: vmaddz.x $vf4, $vf3, $vf4z */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vaddq.x $vf4, $vf0, $q */);
                M2C_ERROR(/* unknown instruction: vdiv $q, $vf0w, $vf4x */);
                M2C_ERROR(/* unknown instruction: vwaitq */);
                M2C_ERROR(/* unknown instruction: vmulq.xyzw $vf1, $vf2, $q */);
                M2C_ERROR(/* unknown instruction: qmfc2.ni $t0, $vf1 */);
                PxpAdd(&B_003DD490, M2C_FIELD(arg0, s32 *, 0xE4), arg1, M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf5 */), 0, temp_s3 + 0x148);
                M2C_ERROR(/* unknown instruction: ldl $a2, %lo(RO_002A7AC7)($s7) */);
                QueueSwCallbackOnce(&B_003DD490, arg0, M2C_ERROR(/* unknown instruction: ldr $a2, %lo(RO_002A7AC0)($s7) */), 0);
            }
            var_s4 += 1;
        } while (var_s4 < M2C_FIELD(arg0, s32 *, 0x198));
    }
}
