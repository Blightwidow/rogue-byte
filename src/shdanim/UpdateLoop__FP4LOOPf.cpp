// SPDX-License-Identifier: GPL-3.0-or-later
struct LOOP { char pad0[0x1C]; int cframe; char pad1[0x14]; char slsai[0x1C]; float dtMin; float dtMax; float dtPauseMin; float dtPauseMax; float sviframe; float gframe; float dtPauseRequested; float dtPause; };
extern float g_2dded4;
extern "C" int FIsSlEmpty(void *);
extern "C" float GRandInRange(float, float);
float GModPositive(float, float);
extern "C" void SetSaiIframe(LOOP *, int);

void UpdateLoop(LOOP *ploop, float dt)
{
    if (FIsSlEmpty(ploop->slsai))
        return;
    int cframe = ploop->cframe;
    if (cframe < 2)
        return;
    float dtPause = ploop->dtPause;
    if (0.0f < dtPause) {
        ploop->dtPause = dtPause - g_2dded4;
        return;
    }
    float gframe = ploop->gframe + ploop->sviframe * g_2dded4;
    ploop->gframe = gframe;
    if ((float)cframe <= gframe) {
        float dtLoop = GRandInRange(ploop->dtMin, ploop->dtMax);
        ploop->sviframe = (float)ploop->cframe / dtLoop;
        float dtPauseNew = GRandInRange(ploop->dtPauseMin, ploop->dtPauseMax);
        ploop->dtPauseRequested = dtPauseNew;
        ploop->dtPause = dtPauseNew;
    }
    float gframeWrapped = GModPositive(ploop->gframe, (float)ploop->cframe);
    ploop->gframe = gframeWrapped;
    SetSaiIframe(ploop, (int)gframeWrapped);
}
