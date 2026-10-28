#include "sly2.h"
struct FRM { char pad0[4]; void *pqwGif; char pad1[0x1C]; void *pqwVif; char pad2[8]; unsigned grf; };
extern char B_002DEA50[];
extern unsigned B_002DEB0C;
extern int g_2de594;
extern int g_2de598;
extern FRM *g_2deb14;
extern int g_2deb18;
extern int g_2deb1c;
extern int g_2deb20;
extern int g_2dedbc;
extern "C" void WaitSema(int);
extern "C" void SignalSema(int);
extern "C" void FlushSaaUnpacks(void);
extern "C" void RestoreGsBuffers__Fv(void);
extern "C" void BuildAllDrawEnvGifs(void);
extern "C" void SendDmaSyncGsFinish__FP10sceDmaChanP2QW(int, void *);
extern "C" void BlendPrevFrame__Fv(int);
extern "C" void func_002417F0(int, int, int);
extern "C" void SwapGsBuffers__Fv(void);
extern "C" void FrameRenderLoop__FPv(void *pv)
{
    for (;;) {
        g_2deb20 = 1;
        WaitSema(g_2deb18);
        g_2deb20 = 0;
        g_2deb14 = (FRM *)(B_002DEA50 + B_002DEB0C * 0x50);
        B_002DEB0C = B_002DEB0C + 1;
        if (B_002DEB0C > 1)
            B_002DEB0C = 0;
        FlushSaaUnpacks();
        RestoreGsBuffers__Fv();
        BuildAllDrawEnvGifs();
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de594, g_2deb14->pqwVif);
        SendDmaSyncGsFinish__FP10sceDmaChanP2QW(g_2de598, g_2deb14->pqwGif);
        if ((g_2deb14->grf & 1) != 0)
            BlendPrevFrame__Fv(g_2de594);
        func_002417F0(g_2de594, 0, 0);
        SignalSema(g_2deb1c);
        SwapGsBuffers__Fv();
        g_2dedbc = 1;
    }
}
