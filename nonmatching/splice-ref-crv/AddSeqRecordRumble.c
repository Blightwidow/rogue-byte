#include "m2c_macros.h"

void *PjsgeAllocJsg(M2C_UNK);                       /* extern */

void func_001E1088(s32 arg1, f32 fparg0) {
    void *temp_v0;

    temp_v0 = PjsgeAllocJsg(0x33);
    M2C_FIELD(temp_v0, s32 *, 0x14) = arg1;
    M2C_FIELD(temp_v0, f32 *, 0x10) = fparg0;
}
