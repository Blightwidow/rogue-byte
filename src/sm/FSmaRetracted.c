#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, s32);                   /* extern */
extern M2C_UNK B_003E126C;

s32 FSmaRetracted(s32 arg0) {
    return FFindDlEntry(&B_003E126C, arg0) == 0;
}
