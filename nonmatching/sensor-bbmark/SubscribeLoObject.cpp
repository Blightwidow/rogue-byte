#include "sly2.h"
struct LO;
struct SUBSCRIBER { LO *plo; int csub; SUBSCRIBER *pnext; };
struct LO { char pad[8]; SUBSCRIBER *psubFirst; };
struct SLOTHEAP;
extern SLOTHEAP B_003E1144;
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);

void SubscribeLoObject(LO *plo, LO *ploTarget)
{
    for (SUBSCRIBER *psub = plo->psubFirst; psub != 0; psub = psub->pnext) {
        if (psub->plo == ploTarget) {
            psub->csub = psub->csub + 1;
            return;
        }
    }
    SUBSCRIBER * psubNew;
    plo->psubFirst = psubNew;
    psubNew = (SUBSCRIBER *)PvAllocSlotheapImpl(&B_003E1144);
    psubNew->csub = 1;
    psubNew->plo = ploTarget;
    psubNew->pnext = plo->psubFirst;
}
