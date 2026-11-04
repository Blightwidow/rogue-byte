#include "m2c_macros.h"

M2C_UNK DetachMurrayObject();                       /* extern */
s32 FIsBasicDerivedFrom(void *, M2C_UNK);           /* extern */
M2C_UNK GetSoDvGravity(void *);                     /* extern */
M2C_UNK PosLoWorld(void *);                         /* extern */
M2C_UNK VelBallistic(M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
M2C_UNK func_001F7A68(void *, M2C_UNK);             /* extern */
M2C_UNK func_00209FB8(void *);                      /* extern */

void ThrowMurrayObject(void *arg0) {
    f32 temp_f20;
    void *temp_s2;
    void *temp_v1;

    DetachMurrayObject();
    temp_s2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x13F0), void **, 0x180);
    M2C_FIELD(arg0, void **, 0x13F0) = NULL;
    if (((u64) M2C_FIELD(temp_s2, u64 *, 0x28) >> 0x3C) & 1) {
        if (FIsBasicDerivedFrom(temp_s2, 0x38) != 0) {
            func_00209FB8(temp_s2);
        }
        PosLoWorld(temp_s2);
        M2C_ERROR(/* unknown instruction: lqc2 $vf2, 0x1420($s1) */);
        M2C_ERROR(/* unknown instruction: qmtc2.ni $v0, $vf3 */);
        M2C_ERROR(/* unknown instruction: vsub.xyzw $vf1, $vf3, $vf2 */);
        M2C_ERROR(/* unknown instruction: vmul.xy $vf1, $vf1, $vf1 */);
        M2C_ERROR(/* unknown instruction: vaddy.x $vf1, $vf1, $vf1y */);
        M2C_ERROR(/* unknown instruction: vwaitq */);
        M2C_ERROR(/* unknown instruction: vaddq.x $vf1, $vf0, $q */);
        temp_f20 = M2C_ERROR(/* unknown instruction: qmfc2.ni $v0, $vf1 */) / M2C_FIELD(arg0, f32 *, 0x1414);
        PosLoWorld(temp_s2);
        M2C_ERROR(/* unknown instruction: por $s0, $zero, $v0 */);
        GetSoDvGravity(temp_s2);
        VelBallistic(M2C_ERROR(/* unknown instruction: por $a0, $zero, $s0 */), M2C_ERROR(/* unknown instruction: por $a1, $zero, $s1 */), M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */), temp_f20);
        temp_v1 = M2C_FIELD(temp_s2, void **, 0xC);
        M2C_FIELD(temp_v1, M2C_UNK (**)(void *, M2C_UNK), 0x11C)(temp_s2 + M2C_FIELD(temp_v1, s16 *, 0x118), M2C_ERROR(/* unknown instruction: por $a1, $zero, $v0 */));
        func_001F7A68(temp_s2, 2);
    }
}
