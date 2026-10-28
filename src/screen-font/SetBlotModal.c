#include "m2c_macros.h"

M2C_UNK AppendDlEntry(M2C_UNK *, void *);           /* extern */
s32 FFindDlEntry(M2C_UNK *, void *);                /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
extern M2C_UNK B_003E1060;

void SetBlotModal(void *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0xA8);
    if (temp_v0 != arg1) {
        if ((temp_v0 == 0) && (FFindDlEntry(&B_003E1060, arg0) != 0)) {
            RemoveDlEntry(&B_003E1060, arg0);
        }
        M2C_FIELD(arg0, s32 *, 0xA8) = arg1;
        if ((arg1 == 0) && (FFindDlEntry(&B_003E1060, arg0) == 0)) {
            AppendDlEntry(&B_003E1060, arg0);
        }
    }
}
