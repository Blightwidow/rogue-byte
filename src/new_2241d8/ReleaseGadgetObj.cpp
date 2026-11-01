#include "sly2.h"
struct GVT { short delta; short index; void (*fn)(void *, int); };
struct GADGET { char pad0[0xC]; GVT *vt; char pad1[0x15C - 0x10]; int kind; };

static inline void SetState(GADGET *pgadget, int state)
{
    GVT *slot = &pgadget->vt[0x4C];
    slot->fn((char *)pgadget + slot->delta, state);
}

void ReleaseGadgetObj(GADGET *pgadget)
{
    if (pgadget->kind == 0xB) {
        SetState(pgadget, 5);
        return;
    }
    SetState(pgadget, 3);
}
