#include "m2c_macros.h"

s32 FFindDlEntry(s32, void *);                      /* extern */

s32 FSeqnodeStopped(void *arg0) {
    return FFindDlEntry(M2C_FIELD(arg0, s32 *, 0x14) + 0x5C, arg0) == 0;
}
