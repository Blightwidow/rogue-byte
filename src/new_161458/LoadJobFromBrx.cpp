#include "sly2.h"
#include "alloc.h"
struct JOB { char pad0[0x54]; int cevFail; void *aevFail; int cevComplete; void *aevComplete; char pad1[0x28]; int ctoggle; void *atoggle; int canim; void *aanim; };
struct CBIS;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void LoadLoFromBrx(JOB *, CBIS *);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void Unknown1__18CBinaryInputStream(CBIS *);
void LoadJobFromBrx(JOB *job, CBIS *stream)
{
    char frame[16];
    ALLOCREQ req;
    int align = 0x10;
    int size80 = 0x80;
    CStackFrame_Construct(frame);
    ALLOCREQ *preq = &req;
    preq->cb = 0x200;
    preq->cbAlign = align;
    job->atoggle = PvAllocStackImpl__Fi(preq);
    preq->cb = 0x300;
    preq->cbAlign = align;
    job->aanim = PvAllocStackImpl__Fi(preq);
    preq->cb = size80;
    preq->cbAlign = align;
    job->aevFail = PvAllocStackImpl__Fi(preq);
    preq->cb = size80;
    preq->cbAlign = align;
    job->aevComplete = PvAllocStackImpl__Fi(preq);
    LoadLoFromBrx(job, stream);
    preq->cb = job->ctoggle << 4;
    preq->cbAlign = align;
    job->atoggle = PvAllocSwCopyImpl__FiPv(preq, job->atoggle);
    preq->cb = job->canim * 0x18;
    preq->cbAlign = align;
    job->aanim = PvAllocSwCopyImpl__FiPv(preq, job->aanim);
    preq->cb = job->cevFail << 2;
    preq->cbAlign = align;
    job->aevFail = PvAllocSwCopyImpl__FiPv(preq, job->aevFail);
    preq->cb = job->cevComplete << 2;
    preq->cbAlign = align;
    job->aevComplete = PvAllocSwCopyImpl__FiPv(preq, job->aevComplete);
    Unknown1__18CBinaryInputStream(stream);
    CStackFrame_Destructor(frame, 2);
}
