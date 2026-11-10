struct CLOCKT { float t; };
extern "C" CLOCKT g_2dded0;
struct SLOT { int gadget; int state; float t; };
#include "jt.h"

void SetJtGadgetSlotState(JT *jt, SLOT *slot, int state)
{
    if (slot->state == state)
        return;
    if (slot->state == 1)
        jt->Slot102(slot->gadget);
    slot->state = state;
    slot->t = g_2dded0.t;
    switch (state) {
    case 2:
        jt->UseGadget(slot->gadget);
        slot->state = 0;
        return;
    case 1:
        jt->UseGadget(slot->gadget);
        break;
    }
}
