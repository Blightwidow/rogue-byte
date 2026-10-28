#include "m2c_macros.h"

M2C_UNK sceCdMmode(M2C_UNK);                        /* extern */
extern s32 g_2bd4c4;

void SetCdMmode__Fv(void) {
    if (g_2bd4c4 == 0x14) {
        sceCdMmode(2);
    }
}
