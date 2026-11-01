struct VT224190 { char pad[0x260]; short delta; short index; void (*fn)(char *, int); };
struct Gadget224190 { char pad[0xC]; VT224190 *vt; char pad10[0x140]; int state; };
extern "C" {
int FReleaseGadgetObj(Gadget224190 *gadget) {
    int state = gadget->state;
    if (state < 3) {
        if (state > 0) {
            gadget->vt->fn((char *)gadget + gadget->vt->delta, 3);
        }
    }
    return 1;
}
}
