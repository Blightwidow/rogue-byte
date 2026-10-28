#include "m2c_macros.h"

M2C_UNK HandleLoMessage();                          /* extern */
M2C_UNK SetSlotSoState(void *, M2C_UNK);            /* extern */

void HandleSlotSoMessage(void *arg0, s32 arg1, void *arg2) {
    HandleLoMessage();
    if ((arg1 == 2) && (arg2 == M2C_FIELD(arg0, s32 *, 0x1C4))) {
        if (M2C_FIELD(arg2, s32 *, 0x14) == M2C_FIELD(arg0, s32 *, 0x1A4)) {
            SetSlotSoState(arg0, 4);
        }
    }
}
