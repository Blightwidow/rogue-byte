#include "sly2.h"
struct REQ { int size; int align; };
struct COIN { char pad[0x23C]; int count; void *table; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void *PvAllocStackImpl__Fi(REQ *);
extern "C" void LoadDprizeFromBrx(COIN *, void *);
extern "C" void func_001C7A08(COIN *);
extern "C" void *PvAllocSwCopyImpl__FiPv(REQ *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
void LoadCoinFromBrx(COIN *coin, void *bis)
{
    char frame[0x10];
    int align = 0x10;
    CStackFrame_Construct(frame);
    REQ req;
    REQ *preq = &req;
    req.size = 0x580;
    preq->align = align;
    coin->table = PvAllocStackImpl__Fi(preq);
    LoadDprizeFromBrx(coin, bis);
    func_001C7A08(coin);
    req.size = coin->count * 0x2C;
    preq->align = align;
    coin->table = PvAllocSwCopyImpl__FiPv(preq, coin->table);
    CStackFrame_Destructor(frame, 2);
}
