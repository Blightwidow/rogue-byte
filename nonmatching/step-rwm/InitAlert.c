#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
extern M2C_UNK B_003E145C;

void *InitAlert(void *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 0xC) = arg1;
    M2C_FIELD(arg0, f32 *, 0x14) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x18) = 2.0f;
    M2C_FIELD(arg0, s32 *, 8) = -1;
    M2C_FIELD(arg0, s32 *, 0x10) = -1;
    AppendDlEntry(&B_003E145C, arg0);
    return arg0;
}
