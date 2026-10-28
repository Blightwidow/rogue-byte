#include "sly2.h"
struct SO;
struct BARRIER { char pad[0x150]; int coid; int aoid[4]; int ccid; int acid[4]; int fAllow; };
extern "C" {
int FLoHasOid(SO *, int);
int FIsBasicDerivedFrom(SO *, int);
int FIgnoreSoIntersection(BARRIER *, SO *);
}
int FIgnoreBarrierIntersection(BARRIER *pbarrier, SO *psoOther)
{
    int fMatched = 0;
    for (int ioid = 0; ioid < pbarrier->coid; ioid++) {
        if (FLoHasOid(psoOther, pbarrier->aoid[ioid]))
            fMatched = 1;
    }
    for (int icid = 0; icid < pbarrier->ccid; icid++) {
        if (FIsBasicDerivedFrom(psoOther, pbarrier->acid[icid]))
            fMatched = 1;
    }
    int result = 1;
    if (pbarrier->fAllow) {
        result = 3;
        if (!fMatched)
            result = FIgnoreSoIntersection(pbarrier, psoOther);
    } else {
        if (fMatched)
            result = 2;
    }
    return result;
}
