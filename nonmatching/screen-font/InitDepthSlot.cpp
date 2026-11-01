struct DepthSlot2156B8 {
    unsigned a0; unsigned a4; char pad8[0x28];
    int f30; int f34; int f38; unsigned f3c; unsigned f40; const void *f44; int f48;
    unsigned f4c; unsigned f50; int f54; int f58; int f5c; char pad60[4]; int f64; char sle[16];
};
extern "C" {
extern const char RO_002A3A10[];
void ClearSle(void *);
void InitDepthSlot(DepthSlot2156B8 *slot) {
    slot->f44 = RO_002A3A10;
    slot->f4c = 0x7F7F7F7F;
    slot->f50 = 0xFFFFFFFF;
    slot->f64 = -1;
    slot->f30 = 0;
    slot->f54 = 0;
    slot->a0 = 0x7F7F7F7F;
    slot->a4 = 0xFFFFFFFF;
    slot->f3c = 0x7F7F7F7F;
    slot->f40 = 0xFFFFFFFF;
    slot->f58 = 0;
    slot->f34 = 0;
    slot->f5c = 0;
    slot->f38 = 0;
    slot->f48 = 0;
    ClearSle(slot->sle);
}
}
