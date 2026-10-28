#include "m2c_macros.h"

M2C_UNK ConvertAloPos(M2C_UNK, void *, M2C_UNK);    /* extern */
s32 PcgtPointInCbspQuick__FP4CBSPP6VECTOR(s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_00227440(void *, s32);                 /* extern */

void func_002273F0(void *arg0) {
    ConvertAloPos(0, arg0, M2C_ERROR(/* unknown instruction: por $a2, $zero, $a1 */));
    func_00227440(arg0, PcgtPointInCbspQuick__FP4CBSPP6VECTOR(M2C_FIELD(arg0, s32 *, 0xF4), 0x7FFFFFFF, M2C_ERROR(/* unknown instruction: por $a2, $zero, $v0 */)) != 0);
}
