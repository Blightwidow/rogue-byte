#include "m2c_macros.h"

M2C_UNK CloneLo();                                  /* extern */
s32 PvAllocSwCopyImpl__FiPv(void *, s32, s32, s32); /* extern */

void CloneJsg(void *arg0) {
    char sp[0x400];
    CloneLo();
    if (M2C_FIELD(arg0, s32 *, 0x80) != 0) {
        M2C_FIELD(arg0, s32 *, 0x54) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 *, 0x54), M2C_FIELD(arg0, s32 *, 0x58) * 0x50, 0x10);
    }
}
