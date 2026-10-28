#include "m2c_macros.h"

s32 PslotBentleyGadget(s32 arg0, s32 arg1) {
    switch (arg1) {
    case 5:
        return arg0 + 0x1824;
    case 7:
        return arg0 + 0x1830;
    case 9:
        return arg0 + 0x183C;
    case 11:
        return arg0 + 0x1848;
    case 13:
        return arg0 + 0x1854;
    case 4:
        return arg0 + 0x1860;
    default:
        return 0;
    }
}
