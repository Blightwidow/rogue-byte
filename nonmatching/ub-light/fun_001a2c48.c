#include "m2c_macros.h"

extern u32 B_002E1E58;
extern M2C_UNK D_002BFBD0;

void func_001A2C48(s32 *arg0, s32 *arg1) {
    void *temp_v1;

    if ((u32) B_002E1E58 >= 7U) {
        B_002E1E58 = 0;
    }
    temp_v1 = (B_002E1E58 * 8) + &D_002BFBD0;
    if (arg0 != NULL) {
        *arg0 = M2C_FIELD(temp_v1, s32 *, 0);
    }
    if (arg1 != NULL) {
        *arg1 = M2C_FIELD(temp_v1, s32 *, 4);
    }
}
