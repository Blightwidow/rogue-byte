#include "m2c_macros.h"

s32 func_0018D6F8(s32 arg0, s32 arg1) {
    if (arg1 != 0x25) {
        if (arg1 < 0x26) {
            if (arg1 != 0x1A) {
                return 0;
            }
            return arg0 + 0x1FB0;
        }
        switch (arg1) {                             /* irregular */
        case 38:
            return arg0 + 0x1FC8;
        case 41:
            return arg0 + 0x1FD4;
        default:
            return 0;
        }
    } else {
        return arg0 + 0x1FBC;
    }
}
