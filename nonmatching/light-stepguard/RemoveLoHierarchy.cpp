#include "sly2.h"
struct VT { char pad[0x20]; short delta; short idx; void (*fn)(void *, int, void *); };
struct LO { char pad[0xC]; VT *vt; char pad2[0x18]; unsigned long grf; };
extern "C" void RemoveSafePointsOfLo(void *, LO *, void *);
extern "C" char B_003DD490[];
extern "C" void RemoveLoHierarchy(LO *lo)
{
    unsigned long mask = 0xEFFFFFFFFFFFFFFFUL;
    unsigned long grf = lo->grf & mask;
    lo->grf = grf;
    if (grf & 0x800000000000000UL)
        RemoveSafePointsOfLo(B_003DD490, lo, 0);
    VT *vt = lo->vt;
    vt->fn((char *)lo + vt->delta, 1, lo);
}
