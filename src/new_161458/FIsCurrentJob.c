#include "m2c_macros.h"

extern s32 B_003E0F9C;

s32 FIsCurrentJob(s32 arg0) {
    return B_003E0F9C == arg0;
}
