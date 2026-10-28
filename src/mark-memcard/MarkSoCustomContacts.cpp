#include "sly2.h"
struct MQ;
struct PXP { MQ *pgeom0; char pad[0x60 - 4]; };
struct MQ {
    MQ *pgeomXp0;
    char pad4[8];
    void *pso0;
    char pad10[0x40 - 0x10];
    void *pso1;
    char pad44[0xAC - 0x44];
    MQ *pmqNext;
    char padB0[0xC0 - 0xB0];
} __attribute__((aligned(16)));
struct VT {
    char pad[0x1E0];
    short delta; short index; void (*fn)(void *, void *, int, void *, void *, void *);
};
struct SO { char pad[0xC]; VT *vt; };
struct GEOM { char pad[0x18]; int grftak; };
struct OXA { char pad[0x60]; SO *pso; char pad2[0x6C - 0x64]; MQ *pmqAbsorbed; };
extern "C" {
void *PaloFindWkrAbsorber(void *, int);
void *PvAllocSlotheapImpl(void *);
void PrependMqList(void *, MQ *, void *);
}
extern "C" void MarkSoCustomContacts(char *psw, OXA *poxaRoot, OXA *poxaOwner, GEOM *pgeom, int cbsp, void *absp, void *pbspLast, void *ppxpFirst)
{
    MQ *pmqLocal = 0;
    void *ptarget = ppxpFirst;
    if (pgeom->grftak) ptarget = &pmqLocal;
    SO *pso = poxaRoot->pso;
    pso->vt->fn((char *)pso + pso->vt->delta, pgeom, cbsp, absp, pbspLast, ptarget);
    if (pmqLocal == 0) return;
    for (MQ *pmq = pmqLocal; pmq != 0; pmq = pmq->pmqNext) {
        int other = (GEOM *)pmq->pgeomXp0 != pgeom;
        char *pside = (char *)pmq + ((1 - other) << 6);
        void *pso = *(void **)(pside + 0xC);
        if (PaloFindWkrAbsorber(pso, pgeom->grftak)) {
            MQ *pclone = (MQ *)PvAllocSlotheapImpl(psw + 0x3D40);
            *pclone = *pmq;
            pclone->pmqNext = poxaOwner->pmqAbsorbed;
            poxaOwner->pmqAbsorbed = pclone;
        }
    }
    PrependMqList(psw, pmqLocal, ppxpFirst);
}
