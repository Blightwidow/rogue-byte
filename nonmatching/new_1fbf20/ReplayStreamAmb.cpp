struct Obj_1FC270 { char pad0[0x40]; int f40; char pad1[0x50 - 0x44]; unsigned short f50; unsigned short f52; char pad2[0x68 - 0x54]; long f68; char pad3[0x3BC - 0x70]; int f3bc; };
extern "C" {
void func_001FB0C0(void *);
void ReplayStreamAmb(Obj_1FC270 *self) {
    int active = 0; if (self->f40 == 0) { active = self->f52 != 0 || (self->f50 & 1) != 0; } if (active) {
        func_001FB0C0(self);
        self->f68 = 0;
        self->f3bc = 0xF;
    }
}
}
