#include "sly2.h"
struct SLOTHEAP;
extern "C" void FreeSlotheapPv(SLOTHEAP *heap, void *item);
extern SLOTHEAP B_003E1144;
extern SLOTHEAP B_003E14E4;
struct LOVT { char pad[0x28]; short delta; short index; void (*fn)(char *, int, void *); };
struct LO { char pad[0xC]; LOVT *vt; };
struct SUB { LO *lo; int pad4; SUB *next; };
struct RVT { char pad[0x18]; short delta; short index; void (*fn)(char *); };
struct RIP { char pad0[4]; int ref; char pad1[0xE8 - 8]; SUB *subs; RVT *vt; };

void ReleaseRip(RIP *rip)
{
    int ref = rip->ref - 1;
    rip->ref = ref;
    if (ref != 0)
        return;
    rip->vt->fn((char *)rip + rip->vt->delta);
    SUB *sub = rip->subs;
    if (sub != 0) {
        do {
            LO *lo = sub->lo;
            lo->vt->fn((char *)lo + lo->vt->delta, 8, rip);
            SUB *next = sub->next;
            FreeSlotheapPv(&B_003E1144, sub);
            sub = next;
        } while (sub != 0);
    }
    rip->subs = 0;
    FreeSlotheapPv(&B_003E14E4, rip);
}
