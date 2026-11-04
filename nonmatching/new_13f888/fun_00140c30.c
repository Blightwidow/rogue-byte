#include "m2c_macros.h"

M2C_UNK SetJmpState(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00205008(M2C_UNK);                     /* extern */

void func_00140C30(s32 arg0, s32 arg1, void *arg2) {
    M2C_ERROR(/* unknown instruction: qmtc2.ni $a3, $vf2 */);
    if (!(((u64) M2C_FIELD(arg2, u64 *, 0x28) >> 0x3C) & 1)) {
        SetJmpState(arg0 + 0x2C0, 0, 0, 0);
        return;
    }
    M2C_ERROR(/* unknown instruction: lqc2 $vf1, 0x1010($a0) */);
    M2C_ERROR(/* unknown instruction: vsub.xyzw $vf3, $vf2, $vf1 */);
    func_00205008(M2C_ERROR(/* unknown instruction: qmfc2.ni $a3, $vf3 */));
}
