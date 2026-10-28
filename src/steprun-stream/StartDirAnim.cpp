#include "sly2.h"
struct ASEG;
struct ALO;
struct DIRANIMS { char pad[0x30]; ASEG *paseg; };
struct DIRANIM { int a0; int a4; int pad8; void *vptr; char pad10[0x10]; ALO *palo; void *pasega; DIRANIMS *pdiranims; void *pcurrent; int grfapl; };
extern char D_002DA9D0[];
extern "C" void ApplyAsegToHandle(float, float, ASEG *, ALO *, int, void **);
extern "C" void SubscribeLoObject(void *, void *);

void StartDirAnim(DIRANIMS *pdiranims, ALO *palo, int grfapl, DIRANIM *pdiranim)
{
    memset(pdiranim, 0, 0x40);
    memset(pdiranim, 0, 0x40);
    pdiranim->pdiranims = pdiranims;
    pdiranim->palo = palo;
    pdiranim->vptr = D_002DA9D0;
    pdiranim->grfapl = grfapl;
    pdiranim->a0 = 0;
    pdiranim->a4 = 0;
    ApplyAsegToHandle(0.0f, 1.0f, pdiranims->paseg, palo, grfapl, &pdiranim->pasega);
    SubscribeLoObject(pdiranim->pasega, pdiranim);
    pdiranim->pcurrent = (char *)pdiranims + 0x30;
}
