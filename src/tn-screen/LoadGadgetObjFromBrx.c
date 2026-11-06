struct Gadget { char pad0[0xE8]; char *inner; };
void CSo_LoadFromBrx();
void LoadGadgetObjFromBrx(struct Gadget *gadget) {
    CSo_LoadFromBrx();
    if (gadget->inner != 0) {
        *(float *)(gadget->inner + 0xD4) = 2.0f;
        *(float *)(gadget->inner + 0xD8) = 2.0f;
    }
}
