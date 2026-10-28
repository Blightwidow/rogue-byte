#include "m2c_macros.h"

s32 FSwLoadBusy(M2C_UNK *);                         /* extern */
extern M2C_UNK B_003DD490;

s32 FJobRunning(void *arg0) {
    s32 temp_a0;

    if (M2C_FIELD(arg0, s32 *, 0x50) == 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0xF0);
        if ((temp_a0 != 2) && (temp_a0 != 3)) {
            return FSwLoadBusy(&B_003DD490) == 0;
        }
        /* Duplicate return node #5. Try simplifying control flow for better match */
        return 0;
    }
    return 0;
}
