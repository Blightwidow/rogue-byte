#include "alloc.h"
struct PATH { char pad0[0x54]; int cnode; int anode; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void LoadLoFromBrx(PATH *, void *);
void func_0014A008(PATH *path, void *bis)
{
    char frame[16];
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    int align = 0x10;
    preq->cb = 0xC00;
    preq->cbAlign = align;
    path->anode = (int)PvAllocStackClearImpl__Fi(preq);
    LoadLoFromBrx(path, bis);
    preq->cb = path->cnode * 0xC;
    preq->cbAlign = align;
    path->anode = (int)PvAllocSwCopyImpl__FiPv(preq, (void *)path->anode);
    CStackFrame_Destructor(frame, 2);
}
