#include "sly2.h"
struct REQ { int size; int align; };
struct LOOT { char pad[0x150]; int count; void *table; };
extern "C" void * CStackFrame_Construct(void *);
extern "C" void *PvAllocStackClearImpl__Fi(REQ *);
extern "C" void CSo_LoadFromBrx(LOOT *, void *);
extern "C" void func_0013C440(LOOT *);
extern "C" void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
void LoadLootFromBrx(LOOT *loot, void *bis)
{
    char frame[0x10];
    int align = 0x10;
    CStackFrame_Construct(frame);
    REQ req;
    REQ *preq = &req;
    req.size = 0x580;
    preq->align = align;
    loot->table = PvAllocStackClearImpl__Fi(preq);
    CSo_LoadFromBrx(loot, bis);
    func_0013C440(loot);
    req.size = loot->count * 0x2C;
    preq->align = align;
    loot->table = PvAllocSwCopyImpl__FiPv(preq, loot->table);
    CStackFrame_Destructor(frame, 2);
}
