#include "m2c_macros.h"

extern s32 B_002E1E58;

void func_001A2C20(s32 arg0) {
    if (arg0 == -1) {
        B_002E1E58 = 0;
        return;
    }
    B_002E1E58 = arg0;
}
