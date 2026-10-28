#include "m2c_macros.h"

extern s32 B_003DCFEC;

s32 PshdFromIndex(s32 arg0) {
    return B_003DCFEC + (arg0 * 0x2C);
}
