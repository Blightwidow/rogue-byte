#include "sly2.h"
struct B8 { char b[8]; };
struct PMF { short delta; short index; void (*fn)(void *); };
struct VT { char pad[0x2E8]; short delta; short index; void (*fn)(void *); };
struct JT { char pad[0xC]; VT *vt; };
struct SO { char pad[0x148]; unsigned long grfso; };
struct ZAP { JT *pjt; int state; char pad[0x14]; B8 continuation; char pad2[0x30 - 0x24]; SO *psoSource; };
extern "C" void WarpZapToSafePoint(ZAP *);
extern "C" void SetJmpState(void *, int, int, int);

extern "C" void ZapContinue(ZAP *zap)
{
    B8 saved;
    saved = zap->continuation;
    memset(&zap->continuation, 0, 8);
    PMF *pmf = (PMF *)&saved;
    if (pmf->index != 0) {
        pmf->fn((char *)zap + pmf->delta);
        return;
    }
    if ((unsigned)(zap->state - 8) < 5) {
        JT *pjt = zap->pjt;
        pjt->vt->fn((char *)pjt + pjt->vt->delta);
        return;
    }
    if (zap->psoSource != 0 && (zap->psoSource->grfso & 0x200000000UL) != 0) {
        WarpZapToSafePoint(zap);
        return;
    }
    SetJmpState((char *)zap->pjt + 0x2C0, 0xB, 0, 0);
}
