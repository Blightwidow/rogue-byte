#include "sly2.h"
struct F2 { float lo, hi; };
struct SAAF { char pad[0xC]; F2 loop; F2 pause; unsigned short frame; };
struct LOOP { char pad[0x1C]; int cframe; char pad2[0x30]; F2 loop; F2 pause; float rate, gframe, req, cur; };
extern "C" void InitSaa(LOOP *, SAAF *);
extern "C" float GRandInRange(float, float);
void InitLoop__FP4LOOPP4SAAF(LOOP *loop, SAAF *saaf)
{
    InitSaa(loop, saaf);
    F2 *pl = &loop->loop;
    F2 *pp = &loop->pause;
    F2 *sl = &saaf->loop;
    F2 *sp = &saaf->pause;
    float a = sl->lo, b = sl->hi;
    pl->lo = a;
    pl->hi = b;
    float c = sp->lo, d = sp->hi;
    pp->lo = c;
    pp->hi = d;
    int frame = saaf->frame;
    float lo = pl->lo;
    float g;
    asm("mtc1 %1, %0\n\tnop\n\tcvt.s.w %0, %0" : "=f" (g) : "r" (frame), "f" (lo));
    loop->gframe = g;
    float dt = GRandInRange(lo, pl->hi);
    loop->rate = (float)loop->cframe / dt;
    float pause = GRandInRange(pp->lo, pp->hi);
    loop->req = pause;
    loop->cur = pause;
}
