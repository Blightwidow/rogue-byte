#include "m2c_macros.h"

s32 func_00242AB8();                                /* extern */
extern s32 g_2bd4c4;

s32 FValidCdMmode__Fv(void) {
    s32 temp_v0;

    temp_v0 = func_00242AB8();
    if (g_2bd4c4 != temp_v0) {
        g_2bd4c4 = temp_v0;
    }
    return g_2bd4c4 == 0x14;
}
