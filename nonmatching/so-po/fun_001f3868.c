#include "m2c_macros.h"

M2C_UNK PosLoWorld();                               /* extern */
s32 PpathzoneFindPos(M2C_UNK, M2C_UNK);             /* extern */
M2C_UNK func_001F37C8(s32, s32);                    /* extern */

void func_001F3868(s32 arg0) {
    PosLoWorld();
    func_001F37C8(arg0, PpathzoneFindPos(M2C_ERROR(/* unknown instruction: por $a0, $zero, $v0 */), 1));
}
