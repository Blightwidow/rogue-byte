#include "sly2.h"
struct VT { char pad[0x20]; short delta; short idx; void (*fn)(void *, int, void *); };
struct LO { char pad[0xC]; VT *vt; char pad2[0x18]; unsigned long grf; };
struct SW;
extern SW B_003DD490;
void RemoveSafePointsOfLo(SW *, LO *, void *);
void RemoveLoHierarchy(LO *lo)
{
    unsigned long mask;
    asm("ori %0, $0, 0xEFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF\n\tdsll %0, %0, 16\n\tori %0, %0, 0xFFFF" : "=r" (mask));
    unsigned long grf = lo->grf & mask;
    lo->grf = grf;
    if (grf & 0x800000000000000UL)
        RemoveSafePointsOfLo(&B_003DD490, lo, 0);
    VT *vt = lo->vt;
    vt->fn((char *)lo + vt->delta, 1, lo);
}
