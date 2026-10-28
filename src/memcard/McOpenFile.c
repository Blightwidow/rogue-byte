#include "m2c_macros.h"

M2C_UNK McSync(void *, s32, M2C_UNK, s32);          /* extern */
s32 sceMcOpen(s32, s32, s32, s32);                  /* extern */

void McOpenFile(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    McSync(arg0 + 0xFD5C, sceMcOpen(M2C_FIELD(arg0, s32 *, 0), M2C_FIELD(arg0, s32 *, 4), arg1, arg2), 2, arg3);
}
