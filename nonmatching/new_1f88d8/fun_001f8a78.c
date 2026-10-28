#include "m2c_macros.h"

M2C_UNK ConvertXfPos(M2C_UNK, s32, M2C_UNK);        /* extern */
M2C_UNK func_001F89E0(void *, s32, s32, M2C_UNK);   /* extern */

void func_001F8A78(void *arg0, s32 arg1, s32 arg2) {
    ConvertXfPos(0, M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), s32 *, 0xA0), M2C_ERROR(/* unknown instruction: por $a2, $zero, $a3 */));
    func_001F89E0(arg0, arg1, arg2, M2C_ERROR(/* unknown instruction: por $a3, $zero, $v0 */));
}
