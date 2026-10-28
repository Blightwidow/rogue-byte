#include "m2c_macros.h"

M2C_UNK CloneSo();                                  /* extern */
s32 PvAllocSwCopyImpl__FiPv(void *, s32, s32, s32); /* extern */

void CloneLaser(void *arg0) {
    char sp[0x400];
    CloneSo();
    M2C_FIELD(arg0, s32 *, 0x19C) = PvAllocSwCopyImpl__FiPv(sp, M2C_FIELD(arg0, s32 *, 0x19C), M2C_FIELD(arg0, s32 *, 0x198) * 0x150, 0x10);
}
