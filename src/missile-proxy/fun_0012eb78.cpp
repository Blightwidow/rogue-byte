#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct LO { char pad[0xE4]; int cxfm; void *axfm; int unkEC; int cvec; void *avec; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void LoadXfmFromBrx(LO *, void *);

extern "C" void func_0012EB78(LO *plo, void *pbis)
{
    char frame[0x10];
    ALLOCREQ allocreq;
    CStackFrame_Construct(frame);
    ALLOCREQ *preq = &allocreq;
    preq->cb = 0xA0;
    preq->cbAlign = 0x10;
    plo->axfm = PvAllocStackClearImpl__Fi(preq);
    preq->cb = 0x80;
    preq->cbAlign = 0x10;
    plo->avec = PvAllocStackClearImpl__Fi(preq);
    LoadXfmFromBrx(plo, pbis);
    preq->cb = plo->cxfm * 0x14;
    preq->cbAlign = 0x10;
    plo->axfm = PvAllocSwCopyImpl__FiPv(preq, plo->axfm);
    preq->cb = plo->cvec << 4;
    preq->cbAlign = 0x10;
    plo->avec = PvAllocSwCopyImpl__FiPv(preq, plo->avec);
    CStackFrame_Destructor(frame, 2);
}
