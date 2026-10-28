#include "m2c_macros.h"

s32 ICheerFromOid(s32 arg0) {
    if (arg0 != 0x627) {
        if (arg0 < 0x628) {
            if (arg0 != 0x626) {
                return -1;
            }
            return 0;
        }
        if (arg0 != 0x628) {
            return -1;
        }
        return 2;
    }
    return 1;
}
