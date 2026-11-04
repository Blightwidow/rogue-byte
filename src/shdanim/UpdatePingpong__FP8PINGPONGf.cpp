#include "sly2.h"
struct PINGPONG {
char pad0[0x1C]; int cframe; char pad20[0x14]; char sl[0x1C];
float dtMin; float dtMax; float dtPauseMin; float dtPauseMax;
float sviframe; float gframe; float dtPauseRequested; float dtPause;
};
extern "C" int FIsSlEmpty(void *);
extern "C" float GRandInRange(float, float);
extern "C" void SetSaiIframe(void *, int);
extern "C" float g_2dded4;
void UpdatePingpong(PINGPONG *ppingpong, float dt)
{
    if (FIsSlEmpty(&ppingpong->sl))
        return;
    int cframe = ppingpong->cframe;
    if (cframe < 2)
        return;
    if (0.0f < ppingpong->dtPause) {
        ppingpong->dtPause = ppingpong->dtPause - g_2dded4;
        return;
    }
    float sviframe = ppingpong->sviframe;
    float dgframe = sviframe * g_2dded4;
    float gframe = ppingpong->gframe + dgframe;
    ppingpong->gframe = gframe;
    if ((float)cframe <= gframe) {
        ppingpong->gframe = gframe - dgframe;
        ppingpong->sviframe = -sviframe;
    }
    if (ppingpong->gframe < 0.0f) {
        ppingpong->gframe = 0.0f;
        float dtPingpong = GRandInRange(ppingpong->dtMin, ppingpong->dtMax);
        ppingpong->sviframe = (float)(ppingpong->cframe << 1) / dtPingpong;
        float dtPause = GRandInRange(ppingpong->dtPauseMin, ppingpong->dtPauseMax);
        ppingpong->dtPauseRequested = dtPause;
        ppingpong->dtPause = dtPause;
    }
    SetSaiIframe(ppingpong, (int)ppingpong->gframe);
}
