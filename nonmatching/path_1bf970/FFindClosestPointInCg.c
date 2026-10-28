#include "m2c_macros.h"

s32 PcgtPointInCgSafe(s32, M2C_UNK);                /* extern */
s128 PosClosestOnCgt(s32, M2C_UNK);                 /* extern */

s32 FFindClosestPointInCg(void *arg0, s128 *arg2) {
    s32 temp_v0;

    M2C_ERROR(/* unknown instruction: por $s0, $zero, $a1 */);
    temp_v0 = PcgtPointInCgSafe(M2C_FIELD(arg0, s32 *, 0x14), M2C_ERROR(/* unknown instruction: por $a2, $zero, $s0 */));
    if (temp_v0 != 0) {
        *arg2 = PosClosestOnCgt(temp_v0, M2C_ERROR(/* unknown instruction: por $a1, $zero, $s0 */));
        return 1;
    }
    return 0;
}
