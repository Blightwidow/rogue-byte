#include "m2c_macros.h"

s32 OidFromICheer(s32 arg0) {
    if (arg0 != 1) {
        if (arg0 < 2) {
            if (arg0 != 0) {
                return -1;
            }
            return 0x626;
        }
        if (arg0 != 2) {
            return -1;
        }
        return 0x628;
    }
    return 0x627;
}
