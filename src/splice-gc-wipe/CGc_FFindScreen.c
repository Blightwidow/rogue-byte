#include "m2c_macros.h"

M2C_UNK FFindDlEntry(M2C_UNK *, s32);               /* extern */
extern M2C_UNK B_003D9E70;

void CGc_FFindScreen(s32 arg0) {
    FFindDlEntry(&B_003D9E70, arg0);
}
