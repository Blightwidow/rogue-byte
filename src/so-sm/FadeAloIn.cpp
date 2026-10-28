#include "sly2.h"
struct VT { char pad[0x40]; short delta; short index; void (*fn)(void *); };
struct ALO { char p0[0xC]; VT *vt; char p1[0x18]; unsigned long flags; char p2[0xFC]; float alpha; };
extern "C" void SetAloFadeRate(ALO *, float);
extern "C" void SetAloAlpha(ALO *, float);
extern "C" void FadeAloIn(ALO *palo, float dt)
{
    if (dt <= 0.0f) {
        SetAloFadeRate(palo, 0.0f);
        SetAloAlpha(palo, 1.0f);
        return;
    }
    if (palo->flags & 0x100000000000000UL) {
        palo->vt->fn((char *)palo + palo->vt->delta);
        palo->alpha = 0.0f;
    }
    // the original has a nop between the mtc1 of 1.0f and div.s; reproduced with an asm nop
    float one = 1.0f; asm volatile("nop" : "+f"(one)); SetAloFadeRate(palo, one / dt);
}
