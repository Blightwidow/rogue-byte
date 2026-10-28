#include "m2c_macros.h"

M2C_UNK func_001A3078(M2C_UNK *);                   /* extern */
extern M2C_UNK B_002E1E60;

void IncrementSwShowCount(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x3D80) + 1;
    M2C_FIELD(arg0, s32 *, 0x3D80) = temp_v0;
    if (temp_v0 == 1) {
        func_001A3078(&B_002E1E60);
    }
}
