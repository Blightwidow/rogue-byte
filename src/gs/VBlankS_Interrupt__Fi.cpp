#include "sly2.h"
struct DISPENV { char b[0x28]; };
extern int B_002DFB58;
extern int B_002DFB4C;
extern int g_2dedbc;
extern int B_002DFB5C;
extern int D_002BE590;
extern int D_002BE594;
extern int g_2dedb0;
extern int B_002DFB60;
extern DISPENV B_002DEB80[];
extern "C" void iSignalSema(int);
void BlendDisplayOnBufferMismatch__Fv();
extern "C" void sceGsPutDispEnv(DISPENV *);
int VBlankS_Interrupt__Fi(int)
{
    if (B_002DFB58 != 0) {
        B_002DFB58 = 0;
        iSignalSema(B_002DFB4C);
    }
    switch (g_2dedbc) {
    case 1:
        if (B_002DFB5C == 0) {
            D_002BE594 = D_002BE590;
            BlendDisplayOnBufferMismatch__Fv();
        }
        break;
    case 2:
        if (B_002DFB5C == 0)
            BlendDisplayOnBufferMismatch__Fv();
        break;
    case 3:
        g_2dedb0 = g_2dedb0 + 1;
        B_002DFB60 = 1;
        sceGsPutDispEnv(&B_002DEB80[g_2dedb0 & 1]);
        break;
    }
    asm volatile("sync");
    asm volatile("ei");
    return 0;
}
