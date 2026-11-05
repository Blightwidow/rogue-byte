struct Laser { char pad0[0x40]; int f40; char pad44[0x148 - 0x44]; long f148; char pad150[0x1C0 - 0x150]; float f1C0; };
extern "C" void func_001DE2A0(Laser *);
extern "C" void InitLaser(Laser *self) {
    func_001DE2A0(self);
    int link = self->f40;
    self->f1C0 = 1.0f;
    self->f148 = self->f148 & ~(1L << 35);
    if ((link ^ 1) & 1) {
        *(int *)link = *(int *)link | 8;
        return;
    }
    self->f40 = link | 8;
}
