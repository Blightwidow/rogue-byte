#include "sly2.h"
struct ALLOCREQ { int size; int align; };
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
    preq->size = 0x200;
    preq->align = align;
    job->atoggle = PvAllocStackImpl__Fi(preq);
    preq->size = 0x300;
    preq->align = align;
    job->aanim = PvAllocStackImpl__Fi(preq);
    preq->size = size80;
    preq->align = align;
    job->aevFail = PvAllocStackImpl__Fi(preq);
    preq->size = size80;
    preq->align = align;
    job->aevComplete = PvAllocStackImpl__Fi(preq);
    LoadLoFromBrx(job, stream);
    preq->size = job->ctoggle << 4;
    preq->align = align;
    job->atoggle = PvAllocSwCopyImpl__FiPv(preq, job->atoggle);
    preq->size = job->canim * 0x18;
    preq->align = align;
    job->aanim = PvAllocSwCopyImpl__FiPv(preq, job->aanim);
    preq->size = job->cevFail << 2;
    preq->align = align;
    job->aevFail = PvAllocSwCopyImpl__FiPv(preq, job->aevFail);
    preq->size = job->cevComplete << 2;
    preq->align = align;
    job->aevComplete = PvAllocSwCopyImpl__FiPv(preq, job->aevComplete);
    Unknown1__18CBinaryInputStream(stream);
    CStackFrame_Destructor(frame, 2);
}
