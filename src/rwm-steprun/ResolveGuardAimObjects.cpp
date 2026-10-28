#include "sly2.h"
struct GUARD { char pad0[0xEB8]; int aoid[8]; int count; int afound[8]; int found; };
struct SW;
extern SW B_003DD490;
extern "C" int PloFindSwObject_thunk(SW *, int, int, GUARD *);

void ResolveGuardAimObjects(GUARD *pguard)
{
    pguard->found = 0;
    for (int index = 0; index < pguard->count; index++) {
        int pobject = PloFindSwObject_thunk(&B_003DD490, 4, pguard->aoid[index], pguard);
        if (pobject != 0) {
            int n = pguard->found;
            pguard->afound[n] = pobject;
            pguard->found = n + 1;
        }
    }
}
