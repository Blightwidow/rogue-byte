#include "m2c_macros.h"

M2C_UNK CGc_UpdateTop(M2C_UNK *);                   /* extern */
s32 FFindDlEntry(M2C_UNK *, s32);                   /* extern */
M2C_UNK PrependDlEntry(M2C_UNK *, s32);             /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, s32);              /* extern */
extern M2C_UNK B_003D9E70;

void CGc_PushScreen(s32 arg0) {
    if (FFindDlEntry(&B_003D9E70, arg0) != 0) {
        RemoveDlEntry(&B_003D9E70, arg0);
    }
    PrependDlEntry(&B_003D9E70, arg0);
    CGc_UpdateTop(&B_003D9E70);
}
