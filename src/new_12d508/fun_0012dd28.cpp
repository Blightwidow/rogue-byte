#include "sly2.h"
struct ALO; struct XF;
struct ACT { char pad[0x8]; XF *pxf; char pad2[0x10]; ACT *pactRef; };
extern "C" ACT *PactNewForXf(int, ALO *, XF *, int, int);
extern "C" void InsertXfAct(ALO *, XF *, ACT *);

ACT *func_0012DD28(ALO *palo, XF *pxf, int priority, ACT *pactRef)
{
    int xfk = (pxf == pactRef->pxf) ? 0xE : 0xD;
    ACT *pact = PactNewForXf(7, palo, pxf, priority, xfk);
    pact->pactRef = pactRef;
    InsertXfAct(palo, pxf, pact);
    return pact;
}
