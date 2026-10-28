#include "m2c_macros.h"

M2C_UNK ClearHandsOff(M2C_UNK *, M2C_UNK);          /* extern */
s32 FAsegaGone();                                   /* extern */
M2C_UNK SetHandsOff(M2C_UNK *, M2C_UNK);            /* extern */
extern M2C_UNK B_003DD490;

void SetAsegaHandsOff(void *arg0, s32 arg1) {
    if ((FAsegaGone() == 0) && (arg1 != M2C_FIELD(arg0, s32 *, 0x58))) {
        if (arg1 != 0) {
            SetHandsOff(&B_003DD490, 3);
        } else {
            ClearHandsOff(&B_003DD490, 3);
        }
        M2C_FIELD(arg0, s32 *, 0x58) = arg1;
    }
}
