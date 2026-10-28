#include "sly2.h"
struct ALLOCREQ { int cb; int cbAlign; };
struct SLOTHEAP { int cb; int c; int cbAlign; char *pvFree; int cAlloc; char *pvBlock; };
extern "C" char *PvAllocSwImpl__Fi(ALLOCREQ *);

char *PvAllocSlotheapImpl(SLOTHEAP *pslotheap)
{
    char *slot;
    if (!pslotheap->pvFree) {
        ALLOCREQ req;
        req.cb = pslotheap->c * pslotheap->cb;
        req.cbAlign = pslotheap->cbAlign;
        char *block = PvAllocSwImpl__Fi(&req);
        int index;
        for (index = 1; index < pslotheap->c; index++)
            *(char **)(block + (index - 1) * pslotheap->cb) = block + index * pslotheap->cb;
        *(char **)(block + (index - 1) * pslotheap->cb) = 0;
        pslotheap->pvFree = block;
        pslotheap->pvBlock = block;
    }
    slot = pslotheap->pvFree;
    pslotheap->pvFree = *(char **)slot;
    memset(slot, 0, pslotheap->cb);
    pslotheap->cAlloc++;
    return slot;
}
