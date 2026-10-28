#include "m2c_macros.h"

extern s32 g_2c2d8c;

void RumbleUnknown1__Fv(void) {
    if (g_2c2d8c == 0) {
        g_2c2d8c = 1;
    }
}
