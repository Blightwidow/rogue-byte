#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, s32);                   /* extern */
M2C_UNK FreeSlotheapPv(void *, s32);                /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
M2C_UNK RemoveSwRoot(void *, s32);                  /* extern */
extern M2C_UNK B_003DD4BC;

void func_001A53E0(void *arg0) {
    if (FFindDlEntry(&B_003DD4BC, M2C_FIELD(arg0, s32 *, 0x14)) != 0) {
        RemoveDlEntry(&B_003DD4BC, M2C_FIELD(arg0, s32 *, 0x14));
    }
    RemoveSwRoot(&B_003DD4BC - 0x2C, M2C_FIELD(arg0, s32 *, 0x14));
    FreeSlotheapPv(&B_003DD4BC + 0x3960, M2C_FIELD(arg0, s32 *, 0x14));
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
}
