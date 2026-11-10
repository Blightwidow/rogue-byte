#include "sly2.h"
#include "alloc.h"
struct LOOT { char pad[0x150]; int count; void *table; };
extern "C" void * CStackFrame_Construct(void *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void CSo_LoadFromBrx(LOOT *, void *);
extern "C" void func_0013C440(LOOT *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
void LoadLootFromBrx(LOOT *loot, void *bis)
{
    char frame[0x10];
    int align = 0x10;
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    req.cb = 0x580;
    preq->cbAlign = align;
    loot->table = PvAllocStackClearImpl__Fi(preq);
    CSo_LoadFromBrx(loot, bis);
    func_0013C440(loot);
    req.cb = loot->count * 0x2C;
    preq->cbAlign = align;
    loot->table = PvAllocSwCopyImpl__FiPv(preq, loot->table);
    CStackFrame_Destructor(frame, 2);
}
