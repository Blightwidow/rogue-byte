#include "m2c_macros.h"

M2C_UNK func_00167E58(M2C_UNK);                     /* extern */
M2C_UNK iFlushCache(M2C_UNK);                       /* extern */

s32 Vif1InterruptHandler(void) {
    func_00167E58(0x1100C320);
    iFlushCache(0);
    *(s32 *)0x10003C10 = 8;
    M2C_SYNC();
    M2C_ERROR(/* unknown instruction: ei */);
    return -1;
}
