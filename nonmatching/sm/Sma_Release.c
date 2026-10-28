#include "m2c_macros.h"

M2C_UNK Basic_FreeSubscribers(void *);              /* extern */
M2C_UNK CFramePtr_Assign(M2C_UNK);                  /* extern */
M2C_UNK FreeSlotheapPv(M2C_UNK *, void *);          /* extern */
M2C_UNK SidebagPtr_Assign(void *, M2C_UNK);         /* extern */
extern M2C_UNK B_003E1278;

void Sma_Release(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x10) - 1;
    M2C_FIELD(arg0, s32 *, 0x10) = temp_v0;
    if (temp_v0 <= 0) {
        CFramePtr_Assign(0);
        SidebagPtr_Assign(arg0 + 4, 0);
        Basic_FreeSubscribers(arg0);
        FreeSlotheapPv(&B_003E1278, arg0);
    }
}
