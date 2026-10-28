#include "m2c_macros.h"

void *PactNew();                                    /* extern */

void PactNewForXf(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PactNew();
    M2C_FIELD(temp_v0, s32 *, 4) = arg1;
    M2C_FIELD(temp_v0, s32 *, 8) = arg2;
    M2C_FIELD(temp_v0, s32 *, 0xC) = arg3;
    M2C_FIELD(temp_v0, s32 *, 0x14) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
}
