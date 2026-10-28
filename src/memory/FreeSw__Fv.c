#include "m2c_macros.h"

extern s32 g_2f6380;
extern s32 g_2f6384;

void FreeSw__Fv(void) {
    g_2f6384 = g_2f6380;
}
