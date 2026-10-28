#include "m2c_macros.h"

s32 MemcardMenu_KindOfState(void *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x40);
    switch (temp_v0) {
    case 17:
    case 20:
    case 23:
    case 24:
    case 27:
    case 29:
    case 34:
    case 35:
    case 36:
    case 46:
        return 1;
    case 18:
    case 21:
    case 28:
    case 32:
        return 2;
    default:
        return 0;
    }
}
