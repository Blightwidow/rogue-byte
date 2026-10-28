#include "m2c_macros.h"

M2C_UNK RemoveDlEntry(s32);                         /* extern */

void RemoveSwRootRaw(s32 arg0) {
    RemoveDlEntry(arg0 + 0x20);
}
