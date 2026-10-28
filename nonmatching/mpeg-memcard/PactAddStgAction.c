#include "m2c_macros.h"

void *PstageStgSwitchCur(M2C_UNK *);                /* extern */
extern M2C_UNK RO_002A76C0;

s32 *PactAddStgAction(s32 arg1) {
    s32 *temp_v0;
    s32 temp_a0;
    void *temp_v0_2;

    temp_v0_2 = PstageStgSwitchCur(&RO_002A76C0);
    if (temp_v0_2 != NULL) {
        temp_a0 = M2C_FIELD(temp_v0_2, s32 *, 8);
        if (temp_a0 < 0x40) {
            temp_v0 = M2C_FIELD(temp_v0_2, s32 *, 0xC) + (temp_a0 * 8);
            M2C_FIELD(temp_v0_2, s32 *, 8) = (s32) (temp_a0 + 1);
            *temp_v0 = arg1;
            return temp_v0;
        }
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return NULL;
    }
    return NULL;
}
