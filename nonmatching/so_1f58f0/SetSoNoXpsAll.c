#include "m2c_macros.h"

M2C_UNK DiscardSoXps(void *, void *, void *);       /* extern */

void SetSoNoXpsAll(void *arg0, s32 arg1) {
    void *temp_a2;

    temp_a2 = M2C_FIELD(arg0, void **, 0xEC);
    if (temp_a2 != NULL) {
        M2C_FIELD(temp_a2, s64 *, 0x70) = (s64) ((M2C_FIELD(temp_a2, s64 *, 0x70) & ~4) | ((arg1 & 1) * 4));
        DiscardSoXps(arg0, temp_a2, arg0);
    }
}
