#include "m2c_macros.h"

M2C_UNK InitLo();                                   /* extern */
M2C_UNK InitSl(s32, M2C_UNK);                       /* extern */

void InitScript(s32 arg0) {
    InitLo();
    InitSl(arg0 + 0x50, 0x18);
}
