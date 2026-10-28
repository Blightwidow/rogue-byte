#include "m2c_macros.h"

M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
extern s32 B_003D3A40;
extern s32 B_003D3A44;
extern s32 g_2dd314;

void StopLoadingLogo(void) {
    SignalSema(B_003D3A40);
    WaitSema(B_003D3A44);
    g_2dd314 = 0;
}
