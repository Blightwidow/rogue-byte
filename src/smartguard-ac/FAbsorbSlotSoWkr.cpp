#include "sly2.h"
struct EVENT { int kind; int gap[3]; VECTOR vec30; VECTOR vec20; int tail[4]; };
struct WKR { char pad[0x20]; VECTOR vec20; VECTOR vec30; char pad2[0x44 - 0x40]; unsigned grf; };
struct VT { char pad[0x198]; short delta; short index; void (*fn)(void *, EVENT *); };
struct OBJ { char pad[0xC]; VT *vptr; };
struct SO { char pad[0x1C8]; OBJ *pobjAnim; char pad2[0x220 - 0x1CC]; int state; };
int FAbsorbSoWkr(SO *, WKR *);
extern "C" void SetSlotSoState(SO *, int);
int FAbsorbSlotSoWkr(SO *pso, WKR *pwkr)
{
    int fAbsorbed = FAbsorbSoWkr(pso, pwkr);
    if (fAbsorbed != 0 && (pwkr->grf & 8) != 0 && pso->state != 5) {
        SetSlotSoState(pso, 5);
        OBJ *pobj = pso->pobjAnim;
        if (pobj != 0) {
            EVENT event;
            event.kind = 6;
            event.vec20 = pwkr->vec20;
            event.vec30 = pwkr->vec30;
            VT *vtable = pobj->vptr;
            vtable->fn((char *)pobj + vtable->delta, &event);
        }
    }
    return fAbsorbed;
}
