#include "m2c_macros.h"

s32 sceDmaGetChan(M2C_UNK);                         /* extern */
M2C_UNK sceDmaReset(M2C_UNK);                       /* extern */
M2C_UNK sceGsResetPath();                           /* extern */
extern s32 B_002DE590;
extern s32 g_2de594;
extern s32 g_2de598;
extern s32 g_2de59c;
extern s32 g_2de5a0;

void StartupDma__Fv(void) {
    sceDmaReset(1);
    sceGsResetPath();
    B_002DE590 = sceDmaGetChan(0);
    g_2de594 = sceDmaGetChan(1);
    g_2de598 = sceDmaGetChan(2);
    g_2de59c = sceDmaGetChan(8);
    g_2de5a0 = sceDmaGetChan(9);
}
