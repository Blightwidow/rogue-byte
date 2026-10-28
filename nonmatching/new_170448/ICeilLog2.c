#include "m2c_macros.h"

s32 ICeilLog2(s32 arg0) {
    if (arg0 >= 9) {
        if (arg0 < 0x21) {
            return (arg0 < 0x11) ? 4 : 5;
        }
        return (arg0 < 0x41) ? 6 : 7;
    }
    if (arg0 >= 3) {
        return (arg0 < 5) ? 2 : 3;
    }
    if (arg0 != 0) {
        return arg0 >= 2;
    }
    return -1;
}
