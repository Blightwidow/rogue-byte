#include "m2c_macros.h"

extern s32 B_003E0FA0;

s32 FIsCurrentTask(s32 arg0) {
    return B_003E0FA0 == arg0;
}
