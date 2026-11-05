#include "sly2.h"
struct SHUFFLE {
    char pad0[0x1C];
    int cframe;
    char pad20[8];
    unsigned short iframe;
    char pad2A[10];
    char sl[0x1C];
    float dtMin;
    float dtMax;
    float dtPause;
};
extern "C" int FIsSlEmpty(void *);
extern "C" int NRandInRange(int, int);
extern "C" void SetSaiIframe(SHUFFLE *, int);
extern "C" float GRandInRange(float, float);
extern float g_2dded4;
void UpdateShuffle(SHUFFLE *pshuffle, float dt)
{
    if (FIsSlEmpty(&pshuffle->sl))
        return;
    int cframe = pshuffle->cframe;
    if (cframe < 2)
        return;
    float dtPause;
    if (0.0f < pshuffle->dtPause) {
        dtPause = pshuffle->dtPause - g_2dded4;
    } else {
        int step = NRandInRange(1, cframe - 1);
        SetSaiIframe(pshuffle, (pshuffle->iframe + step) % pshuffle->cframe);
        dtPause = GRandInRange(pshuffle->dtMin, pshuffle->dtMax);
    }
    pshuffle->dtPause = dtPause;
}
