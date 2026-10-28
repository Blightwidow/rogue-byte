#include "sly2.h"
struct LO { char pad0[0x10]; void *parent; };
struct EXPLG { char pad0[0x10]; void *parent; char pad[0xCC]; int cexpl; LO **apexpl; };
struct ALLOCREQ { int size; int align; };
extern "C" void CloneXfm(EXPLG *, EXPLG *);
extern "C" void *PvAllocSwCopyImpl__FiPv(ALLOCREQ *, void *);
extern "C" LO *PloCloneLo(LO *, void *);

extern "C" void CloneExplg(EXPLG *pexplg, EXPLG *pexplgBase)
{
    int i = 0;
    CloneXfm(pexplg, pexplgBase);
    ALLOCREQ req;
    req.size = pexplg->cexpl << 2;
    req.align = 0x10;
    pexplg->apexpl = (LO **)PvAllocSwCopyImpl__FiPv(&req, pexplg->apexpl);
    while (i < pexplg->cexpl) {
        pexplg->apexpl[i] = PloCloneLo(pexplg->apexpl[i], pexplg->parent);
        i++;
    }
}
