#include "m2c_macros.h"

M2C_UNK CloneXfm();                                 /* extern */
s32 PloCloneLo(s32, s32);                           /* extern */

void CloneTn(void *arg0) {
    CloneXfm();
    M2C_FIELD(arg0, s32 *, 0x10C) = PloCloneLo(M2C_FIELD(arg0, s32 *, 0x10C), M2C_FIELD(arg0, s32 *, 0x10));
}
