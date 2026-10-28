#include "sly2.h"
struct REQ { int size; int align; };
struct LASER { char pad[0x198]; int count; void *beams; };
extern "C" void * CStackFrame_Construct(void *);
extern "C" void *PvAllocStackClearImpl__Fi(REQ *);
extern "C" void CSo_LoadFromBrx(LASER *, void *);
extern "C" void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void LoadLaserFromBrx(LASER *laser, void *bis)
{
    char frame[0x10];
    int align = 0x10;
    CStackFrame_Construct(frame);
    REQ req;
    REQ *preq = &req;
    req.size = 0x5400;
    preq->align = align;
    laser->beams = PvAllocStackClearImpl__Fi(preq);
    CSo_LoadFromBrx(laser, bis);
    req.size = laser->count * 0x150;
    preq->align = align;
    laser->beams = PvAllocSwCopyImpl__FiPv(preq, laser->beams);
    CStackFrame_Destructor(frame, 2);
}
