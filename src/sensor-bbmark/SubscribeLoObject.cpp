#include "sly2.h"
struct LO;
struct SUBSCRIBER { LO *plo; int csub; SUBSCRIBER *pnext; };
struct LO { char pad[8]; SUBSCRIBER *psubFirst; };
struct SLOTHEAP;
extern SLOTHEAP B_003E1144;
extern "C" void *PvAllocSlotheapImpl(SLOTHEAP *);

void SubscribeLoObject(LO *plo, LO *ploTarget)
{
    SUBSCRIBER *psub;
    for (psub = plo->psubFirst; psub != 0; psub = psub->pnext) {
        if (psub->plo == ploTarget) {
            psub->csub = psub->csub + 1;
            return;
        }
    }
    psub = (SUBSCRIBER *)PvAllocSlotheapImpl(&B_003E1144);
    psub->csub = 1;
    psub->plo = ploTarget;
    psub->pnext = plo->psubFirst;
    plo->psubFirst = psub;
}
