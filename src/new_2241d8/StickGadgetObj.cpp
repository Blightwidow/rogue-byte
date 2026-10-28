#include "sly2.h"
struct GVT { short delta; short index; void (*fn)(void *, int); };
struct GADGET { char pad0[0xC]; GVT *vt; char pad1[0x15C - 0x10]; int kind; };
struct LO { char pad[0x18]; int oid; };
extern "C" void func_001A58D0(GADGET *, LO *, int);

static inline void SetState(GADGET *pgadget, int state)
{
    GVT *slot = &pgadget->vt[0x4C];
    slot->fn((char *)pgadget + slot->delta, state);
}

void StickGadgetObj(GADGET *pgadget, LO *plo)
{
    int kind = pgadget->kind;
    if (kind == 0x1A || kind == 0x29) {
        SetState(pgadget, 3);
        return;
    }
    if (plo->oid == 1)
        plo = 0;
    func_001A58D0(pgadget, plo, 3);
    SetState(pgadget, 2);
}
