extern "C" void RetractSmaRef(void *);
extern "C" void ApplyAsegToHandle(void *, void *, int, void *, float, float);

struct V3 { int x, y, z; };
struct VT { char pad[0x2D0]; short delta; short index; void (*fn)(void *); };
struct BENT { char pad0[0x190]; V3 vel; char pad1[0x14E4 - 0x19C]; void *a14E4; void *a14E8; char pad2[0x15D4 - 0x14EC]; void *a15D4; char pad3[0x15F0 - 0x15D8]; void *a15F0; char pad4[0x16B0 - 0x15F4]; int state; };

void SetBentleyGadgetAnim(BENT *b, int gadgets)
{
    if (gadgets == b->state) return;
    b->state = gadgets;
    void *paseg = 0;
    int grfapl = 1;
    switch (gadgets) {
    case 0:
        paseg = b->a14E4;
        { V3 *v = &b->vel; v->z = 0; v->y = 0; v->x = 0; }
        break;
    case 1:
        paseg = b->a15F0;
        grfapl = 9;
        break;
    case 2:
        paseg = b->a14E8;
        if (paseg == 0) paseg = b->a15D4;
        grfapl = 9;
        break;
    }
    RetractSmaRef((char *)b + 0x1034);
    ApplyAsegToHandle(paseg, b, grfapl, (char *)b + 0x1030, 0.0f, 1.0f);
    VT *vt = *(VT **)((char *)b + 0xC);
    vt->fn((char *)b + vt->delta);
}
