#include "sly2.h"
struct VT1 { char pad[0x108]; short d; short i; QW (*fn)(void *); short d2; short i2; QW (*fn2)(void *); };
struct SLOT { short d; short i; void (*fn)(void *, QW); };
struct ALO { char pad[0xC]; VT1 *vt; };
struct SO { char pad[0xC]; char *vt; char pad2[0xE8 - 0x10]; int phys; };
extern "C" void SetLoPosMatFromLo(SO *, ALO *);
void MatchSoOtherObject(SO *pso, ALO *other)
{
    SetLoPosMatFromLo(pso, other);
    if (pso->phys) {
        SLOT *s = (SLOT *)(pso->vt + 0x118);
        char *t = (char *)pso + s->d;
        s->fn(t, other->vt->fn((char *)other + other->vt->d));
        SLOT *s2 = (SLOT *)(pso->vt + 0x120);
        char *t2 = (char *)pso + s2->d;
        s2->fn(t2, other->vt->fn2((char *)other + other->vt->d2));
    }
}
