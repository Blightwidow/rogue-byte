#include "m2c_macros.h"

M2C_UNK McSync(s32, s32, M2C_UNK, M2C_UNK);         /* extern */
s32 sceMcRead(s32, s32, s32);                       /* extern */

void McRead(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    McSync(arg0 + 0xFD5C, sceMcRead(arg1, arg2, arg3), 5, M2C_ERROR(/* Read from unset register $t0 */));
}
