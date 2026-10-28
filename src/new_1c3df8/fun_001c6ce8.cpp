#include "sly2.h"
struct VT { char pad[0x260]; short delta; short index; void (*fn)(void *, int); };
struct LO { char pad[0xC]; VT *vt; };
struct SW;
extern "C" LO *PloFindSwObject_thunk(SW *, int, int, int);
extern "C" LO *PloLeaseCloneObject(LO *, int);
extern "C" void LockLeaseOfPlo(LO *, LO *);
int func_001C6CE8(SW *sw, int cid, int count, LO **out)
{
    int made;
    if (count == 0)
        return 0;
    int oid;
    switch (cid) {
    case 0x5B:
        oid = 0x2B3;
        break;
    case 0x5D:
        oid = 0x2B4;
        break;
    default:
        return 0;
    }
    LO *templ = PloFindSwObject_thunk(sw, 5, oid, 0);
    if (templ == 0)
        return 0;
    made = 0;
    LO **slot = out;
    for (int index = 0; index < count; index++) {
        LO *lo = PloLeaseCloneObject(templ, 0);
        if (lo == 0)
            break;
        made++;
        lo->vt->fn((char *)lo + lo->vt->delta, 2);
        LockLeaseOfPlo(templ, lo);
        *slot = lo;
        slot++;
    }
    return made;
}
