#include "sly2.h"
struct LO { char pad[0x24]; LO *next; unsigned long grfo; };
struct ALO;
struct VT { char pad[0x148]; short delta; short index; void (*fn)(void *, ALO *); };
struct ALO { char pad[0xC]; VT *vptr; char pad2[0x64 - 0x10]; LO *child; char pad3[0x70 - 0x68]; LO *removed; };
extern "C" void PloCloneLo(LO *, ALO *);

void CloneAloHierarchy(ALO *palo, ALO *base)
{
    VT *vt = palo->vptr;
    vt->fn((char *)palo + vt->delta, base);
    LO *lo = base->child;
    if (lo != base->removed) {
        do {
            if ((lo->grfo & (1UL << 57)) == 0)
                PloCloneLo(lo, palo);
            lo = lo->next;
        } while (lo != base->removed);
    }
}
