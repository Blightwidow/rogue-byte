#include "m2c_macros.h"

M2C_UNK UnsubscribeLoObject(void *, void *);        /* extern */

void ReleaseSeqnodeSma(void *arg0) {
    void *temp_a0;
    void *temp_a1;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x58);
    if (temp_a0 != NULL) {
        UnsubscribeLoObject(temp_a0, arg0);
        temp_a1 = M2C_FIELD(arg0, void **, 0x58);
        temp_v0 = M2C_FIELD(temp_a1, void **, 0xC);
        M2C_FIELD(temp_v0, M2C_UNK (**)(void *, void *), 0x14)(temp_a1 + M2C_FIELD(temp_v0, s16 *, 0x10), temp_a1);
        M2C_FIELD(arg0, void **, 0x58) = NULL;
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
    }
}
