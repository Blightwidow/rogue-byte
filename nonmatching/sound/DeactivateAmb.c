#include "m2c_macros.h"

s32 FFindDlEntry(M2C_UNK *, void *);                /* extern */
M2C_UNK RemoveDlEntry(M2C_UNK *, void *);           /* extern */
extern M2C_UNK B_003DD08C;

void DeactivateAmb(void *arg0) {
    void *temp_v0;

    if (FFindDlEntry(&B_003DD08C, arg0) != 0) {
        RemoveDlEntry(&B_003DD08C, arg0);
        temp_v0 = M2C_FIELD(arg0, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *), 0x14)(arg0 + M2C_FIELD(temp_v0, s16 *, 0x10));
    }
}
