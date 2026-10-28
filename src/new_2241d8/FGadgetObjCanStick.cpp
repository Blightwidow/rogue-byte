#include "m2c_macros.h"

s32 FGadgetObjCanStick(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x15C);
    switch (temp_v0) {
    case 4:
        return M2C_FIELD(arg0, s32 *, 0x150) == 1;
    default:
        return 0;
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 26:
    case 37:
    case 41:
        return 1;
    }
}
