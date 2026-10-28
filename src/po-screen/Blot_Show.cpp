#include "sly2.h"
struct VT { char pad[0x80]; short delta; short index; void (*fn)(void *); };
struct Blot {
    char p0[0xC]; VT *pvt; char p1[0x58 - 0x10]; int blots; char p2[0x70 - 0x5C]; int labelVisible; int labelAppear; int labelDisappear; char p3[0x84 - 0x7C]; int asprite;
};
enum TIMERS { TIMERS_dummy };
extern "C" void SetBlotBlots(Blot *, int);
void SetTimerTimers__FP5TIMER6TIMERS(Blot *, TIMERS);
extern "C" int FSpriteHasLabel(Blot *, int, int);
void Blot_Show(Blot *pblot, int labelStart)
{
    if (pblot->blots == 0)
        SetBlotBlots(pblot, 1);
    SetTimerTimers__FP5TIMER6TIMERS(pblot, (TIMERS)2);
    pblot->labelVisible = labelStart;
    pblot->labelAppear = -1;
    pblot->labelDisappear = -1;
    if (labelStart != -1) {
        SetBlotBlots(pblot, 1);
        SetBlotBlots(pblot, 2);
    } else {
        pblot->labelVisible = 0x314;
        if (FSpriteHasLabel(pblot, pblot->asprite, 0x30F))
            pblot->labelAppear = 0x30F;
        if (FSpriteHasLabel(pblot, pblot->asprite, 0x310))
            pblot->labelVisible = 0x310;
        if (FSpriteHasLabel(pblot, pblot->asprite, 0x311))
            pblot->labelDisappear = 0x311;
        if (pblot->blots == 1) {
            VT *pvt = pblot->pvt;
            pvt->fn((char *)pblot + pvt->delta);
        }
    }
}
