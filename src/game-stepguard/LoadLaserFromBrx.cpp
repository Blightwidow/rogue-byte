#include "sly2.h"
#include "alloc.h"
struct LASER { char pad[0x198]; int count; void *beams; };
extern "C" void * CStackFrame_Construct(void *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void CSo_LoadFromBrx(LASER *, void *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void LoadLaserFromBrx(LASER *laser, void *bis)
{
    char frame[0x10];
    int align = 0x10;
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    req.cb = 0x5400;
    preq->cbAlign = align;
    laser->beams = PvAllocStackClearImpl__Fi(preq);
    CSo_LoadFromBrx(laser, bis);
    req.cb = laser->count * 0x150;
    preq->cbAlign = align;
    laser->beams = PvAllocSwCopyImpl__FiPv(preq, laser->beams);
    CStackFrame_Destructor(frame, 2);
}
