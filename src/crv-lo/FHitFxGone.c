#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, s32);                   /* extern */
extern M2C_UNK B_003E148C;

s32 FHitFxGone(s32 arg0) {
    return FFindDlEntry(&B_003E148C, arg0) == 0;
}
