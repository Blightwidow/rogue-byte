#include "sly2.h"
struct SPLOPT { int optid; void *peopid; };
struct ARYSPLOPT { int csplopt; SPLOPT *asplopt; };
extern ARYSPLOPT RO_00279AD0[];
struct CLASSINFO { int pad; int cid; };
struct BASIC { char pad[0xC]; struct VT *vptr; };
struct VT { char pad[0x30]; short delta; short index; CLASSINFO *(*fn)(void *); };
void *PeopidFind__FP5BASICi(BASIC *pbasic, int optid)
{
    CLASSINFO *pclassinfo = ((CLASSINFO *(*)(void *))pbasic->vptr->fn)((char *)pbasic + pbasic->vptr->delta);
    const ARYSPLOPT *parysplopt = &RO_00279AD0[pclassinfo->cid];
    int low = 0;
    int high = parysplopt->csplopt - 1;
    SPLOPT *asplopt = parysplopt->asplopt;
    if (high >= 0) {
        do {
            int mid = (low + high) >> 1;
            const SPLOPT *psplopt = (const SPLOPT *)((char *)(mid << 3) + (int)asplopt);
            if (psplopt->optid == optid)
                return psplopt->peopid;
            if (optid < psplopt->optid)
                high = mid - 1;
            else
                low = mid + 1;
        } while (low <= high);
    }
    return 0;
}
