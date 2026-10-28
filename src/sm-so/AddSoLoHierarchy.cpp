#include "sly2.h"
struct SO;
struct SOVT { char pad[0x58]; short d; short i; void (*fn)(void *); };
struct PHYS { char pad[0xDC]; int unkDC; };
struct ZONESET { char pad[0x2C]; int czone; };
struct CHILD { char pad0[0xC]; SOVT *vt; char pad1[0x14]; CHILD *pnext; };
struct SO {
    char pad0[0x40]; unsigned grfOrPtr; char pad1[0x20]; CHILD *pchildFirst; char pad2[0x8]; CHILD *pchildEnd;
    char pad3[0x74]; PHYS *pphys;
};
struct SW { char pad[0x45CC]; ZONESET *pzoneset; };
struct UL { unsigned long v; } __attribute__((packed));
extern "C" void AddLoHierarchy(SO *);
extern "C" void UpdateAloXfWorld(SO *);
extern "C" void AddSoGeomsToOxa(SO *);
extern "C" QW PosLoWorld(SO *);
extern "C" void *PpathzoneFindPos(QW, int);
extern "C" void func_001F37C8(SO *, void *);
extern "C" void QueueSwCallback(SW *, SO *, unsigned long, int);
extern "C" SW B_003DD490;
extern "C" const UL RO_002A8270;

void AddSoLoHierarchy(SO *pso)
{
    QW scratch;
    AddLoHierarchy(pso);
    UpdateAloXfWorld(pso);
    asm("" : : "r" (&scratch));
    AddSoGeomsToOxa(pso);
    if ((pso->grfOrPtr ^ 1) & 1)
        *(unsigned *)pso->grfOrPtr |= 0x14;
    else
        pso->grfOrPtr |= 0x14;
    int link = 0;
    if (pso->pphys)
        link = pso->pphys->unkDC;
    if (link) {
        ZONESET *pzoneset = B_003DD490.pzoneset;
        if (pzoneset && pzoneset->czone)
            func_001F37C8(pso, PpathzoneFindPos(PosLoWorld(pso), 1));
        else
            QueueSwCallback(&B_003DD490, pso, RO_002A8270.v, 0);
    }
    for (CHILD *pchild = pso->pchildFirst; pchild != pso->pchildEnd; pchild = pchild->pnext)
        pchild->vt->fn((char *)pchild + pchild->vt->d);
}
