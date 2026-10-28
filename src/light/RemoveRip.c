#include "m2c_macros.h"

M2C_UNK ReleaseRip(void *);                         /* extern */
M2C_UNK RemoveDlEntry(s32, void *);                 /* extern */

void RemoveRip(void *arg0) {
    RemoveDlEntry(M2C_FIELD(arg0, s32 *, 8) + 0x15C, arg0);
    ReleaseRip(arg0);
}
