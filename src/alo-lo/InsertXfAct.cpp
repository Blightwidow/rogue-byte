#include "sly2.h"
struct ACT;
struct VT { char pad[8]; short deltaActivate; short i0; void (*fnActivate)(void *); short deltaDeactivate; short i1; void (*fnDeactivate)(void *); short deltaReselect; short i2; void (*fnReselect)(void *); };
struct ACT { char pad0[0xC]; int priority; ACT *pactNext; int unk14; VT *vt; };
struct XF { char pad[0x90]; ACT *pactTop; };
struct ALO;
extern "C" void InvalidateXfSegment(ALO *, XF *);
extern "C" void InsertXfAct(ALO *palo, XF *pxf, ACT *pact)
{
    ACT **ppactLink = &pxf->pactTop;
    ACT *pactTopOld = pxf->pactTop;
    for (ACT *pactCur = pactTopOld; pactCur && pactCur->priority > pact->priority; pactCur = pactCur->pactNext)
        ppactLink = &pactCur->pactNext;
    pact->pactNext = *ppactLink;
    *ppactLink = pact;
    if (pxf->pactTop != pactTopOld) {
        InvalidateXfSegment(palo, pxf);
        if (pactTopOld)
            pactTopOld->vt->fnDeactivate((char *)pactTopOld + pactTopOld->vt->deltaDeactivate);
        ACT *pactNew = pxf->pactTop;
        pactNew->vt->fnActivate((char *)pactNew + pactNew->vt->deltaActivate);
    } else {
        if (pactTopOld)
            pactTopOld->vt->fnReselect((char *)pactTopOld + pactTopOld->vt->deltaReselect);
    }
}
