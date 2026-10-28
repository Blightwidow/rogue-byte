#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK, s32);                  /* extern */

void SetSymid__4CRefUi(s32 arg1, s32 arg2, s32 arg3) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x1C, arg3);
    M2C_FIELD(temp_v0, s32 *, 0x18) = (s32) M2C_ERROR(/* Read from unset register $t0 */);
    M2C_FIELD(temp_v0, s32 *, 0x10) = arg1;
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg2;
}
