#include "m2c_macros.h"

s32 ClassifyMcSync(s32 arg0) {
    if (arg0 != 0) {
        if (arg0 <= 0) {
            if (arg0 != -1) {
                return 0x1F;
            }
            return 0x20;
        }
        if (arg0 != 1) {
            return 0x1F;
        }
        return 0x22;
    }
    return 0x21;
}
