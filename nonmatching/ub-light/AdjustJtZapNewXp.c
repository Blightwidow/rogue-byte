#include "m2c_macros.h"

extern f32 D_FLT_002BFB20;
extern M2C_UNK32 D_FLT_002BFB24;

void AdjustJtZapNewXp(void *arg0, void *arg1) {
    u32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, u32 *, 4);
    switch (temp_v1) {
    case 4:
    case 12:
        M2C_FIELD(arg1, M2C_UNK32 *, 0x98) = 0;
        M2C_FIELD(arg1, f32 *, 0x94) = (f32) D_FLT_002BFB20;
        return;
    default:
    case 1:
    case 2:
    case 3:
    case 5:
    case 8:
    case 9:
    case 10:
    case 11:
        M2C_FIELD(arg1, f32 *, 0x94) = (f32) D_FLT_002BFB20;
        M2C_FIELD(arg1, M2C_UNK32 *, 0x98) = (M2C_UNK32) D_FLT_002BFB24;
        /* fallthrough */
    case 0:
    case 6:
    case 7:
        return;
    }
}
