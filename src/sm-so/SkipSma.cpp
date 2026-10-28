#include "sly2.h"
struct SMA;
struct VT { short d0; short i0; void *f0; short delta; short idx; void (*addref)(void *); short delta2; short idx2; void (*release)(void *); };
struct ASEG { char pad[0x74]; float tmax; };
struct ASEGA { char pad[0x14]; ASEG *aseg; char pad2[4]; float tlocal; };
struct SMA { char pad[0xC]; VT *vt; char pad2[0x20]; ASEGA *cur; };
struct HOLD { SMA *p; HOLD(SMA *s) { p = s; p->vt->addref((char *)p + p->vt->delta); } ~HOLD() { p->vt->release((char *)p + p->vt->delta2); } };
extern "C" int FSmaRetracted(SMA *);
extern "C" void RetractAsega(ASEGA *);
extern "C" void SeekAsega(ASEGA *, int, float, float);
extern "C" void SkipSma(SMA *sma, float dt)
{
    if (FSmaRetracted(sma)) return;
    HOLD hold(sma);
    ASEGA *cur;
    while ((cur = sma->cur) != 0) {
        float remaining = cur->aseg->tmax - cur->tlocal;
        if (dt < remaining) {
            SeekAsega(cur, 1, dt, 1.0f);
            break;
        }
        dt -= remaining;
        RetractAsega(cur);
    }
}
