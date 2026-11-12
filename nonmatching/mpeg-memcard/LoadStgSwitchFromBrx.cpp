#include "sly2.h"
#include "alloc.h"
struct SWITCHENTRY { int kind; void *pv; };
struct SWITCHGROUP { char pad[8]; int count; SWITCHENTRY *entries; };
struct STGSWITCH { char pad0[0x150]; int cEntry; void *table; int field_0x158; int field_0x15C; int cGroup; SWITCHGROUP *groups; };
extern "C" void *CStackFrame_Construct(void *);
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" void CSo_LoadFromBrx(STGSWITCH *, void *);
extern "C" void CStackFrame_Destructor(void *, int);
void LoadStgSwitchFromBrx(STGSWITCH *pstgsw, void *pbis)
{
    char frame[0x10];
    CStackFrame_Construct(frame);
    ALLOCREQ req;
    ALLOCREQ *preq = &req;
    req.cb = 0x40;
    preq->cbAlign = 0x10;
    pstgsw->table = PvAllocStackImpl__Fi(preq);
    req.cb = 0x200;
    preq->cbAlign = 0x10;
    pstgsw->groups = (SWITCHGROUP *)((char *)PvAllocStackClearImpl__Fi(preq) + 0x10);
    CSo_LoadFromBrx(pstgsw, pbis);
    pstgsw->field_0x15C = 0;
    req.cb = pstgsw->cEntry * 8;
    preq->cbAlign = 0x10;
    pstgsw->table = PvAllocSwCopyImpl__FiPv(preq, pstgsw->table);
    if (pstgsw->cGroup != 0) {
        preq->cbAlign = 0x10;
        req.cb = pstgsw->cGroup * 0x10 + 0x10;
        pstgsw->groups = (SWITCHGROUP *)((char *)PvAllocSwCopyImpl__FiPv(preq, (char *)pstgsw->groups - 0x10) + 0x10);
        for (int iGroup = -1; iGroup < pstgsw->cGroup; iGroup++) {
            SWITCHGROUP *pgroup = pstgsw->groups + iGroup;
            req.cb = pgroup->count * 8;
            preq->cbAlign = 0x10;
            pgroup->entries = (SWITCHENTRY *)PvAllocSwCopyImpl__FiPv(preq, pgroup->entries);
            for (int iEntry = 0; iEntry < pgroup->count; iEntry++) {
                SWITCHENTRY *pentry = pgroup->entries + iEntry;
                if (pentry->kind == 0xC) {
                    pentry->pv = PvAllocSwCopyImpl__FiPv(preq, pentry->pv);
                    req.cb = 8;
                    preq->cbAlign = 0x10;
                }
            }
        }
    } else {
        pstgsw->groups = 0;
    }
    CStackFrame_Destructor(frame, 2);
}
