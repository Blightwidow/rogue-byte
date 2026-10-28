#include "m2c_macros.h"

extern f32 g_2ddf0c;

void GadgetMenu_InitPage(void *arg0) {
    M2C_FIELD(arg0, s32 *, 0x40) = -1;
    M2C_FIELD(arg0, f32 *, 0x44) = (f32) g_2ddf0c;
}
