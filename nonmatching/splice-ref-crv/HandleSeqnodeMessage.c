#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */

void HandleSeqnodeMessage(void *arg0, s32 arg1, void *arg2) {
    HandleLoMessage();
    if ((arg1 == 0xA) && (M2C_FIELD(arg2, s32 *, 0) == M2C_FIELD(arg0, s32 *, 0x58))) {
        if (M2C_FIELD(arg2, s32 *, 8) == M2C_FIELD(M2C_FIELD(arg0, void **, 0x30), s32 *, 0x18)) {
            M2C_FIELD(arg0, s32 *, 0x5C) = 1;
        }
    }
}
