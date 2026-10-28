#include "sly2.h"
struct SO { char p0[0x148]; unsigned long grfso; };
struct SOGEOM { int unk0; SO *psoOwner; };
struct ALLOCREQ { int cb; int align; };
extern "C" void *PvAllocStackImpl__Fi(ALLOCREQ *);
void ExtractUniqueSosFromGeoms(int cgeom, SOGEOM **ageom, int *pcso, SO ***papso)
{
    int cso = 0;
    ALLOCREQ req;
    req.cb = cgeom << 2;
    req.align = 0x10;
    SO **apso = (SO **)PvAllocStackImpl__Fi(&req);
    for (int igeom = 0; igeom < cgeom; igeom++) {
        SO *pso = ageom[igeom]->psoOwner;
        if ((pso->grfso & 0x40000000UL) == 0) {
            pso->grfso = pso->grfso | 0x40000000UL;
            apso[cso++] = pso;
        }
    }
    for (int iso = 0; iso < cso; iso++)
        apso[iso]->grfso = apso[iso]->grfso & ~0x40000000UL;
    *pcso = cso;
    *papso = apso;
}
