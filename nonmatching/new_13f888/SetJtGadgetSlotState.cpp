extern "C" float g_2dded0;
typedef void (*SLOTFN)(void *, int);
struct VT { char pad0[0x320]; short d320; short i320; SLOTFN f320; char pad1[0x330 - 0x328]; short d330; short i330; SLOTFN f330; };
struct SLOT { int gadget; int state; float t; };
struct JT { char pad[0xC]; VT *vt; };

void SetJtGadgetSlotState(JT *jt, SLOT *slot, int state)
{
    if (slot->state == state)
        return;
    if (slot->state == 1) {
        VT *vt = jt->vt;
        vt->f330((char *)jt + vt->d330, slot->gadget);
    }
    slot->t = g_2dded0;
    slot->state = state;
    switch (state) {
    case 2: {
        VT *vt = jt->vt;
        vt->f320((char *)jt + vt->d320, slot->gadget);
        slot->state = 0;
        return;
    }
    case 1: {
        VT *vt = jt->vt;
        vt->f320((char *)jt + vt->d320, slot->gadget);
        break;
    }
    }
}
