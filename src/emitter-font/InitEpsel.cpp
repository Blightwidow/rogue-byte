struct Epsel { char pad[0x110]; int f110; int f114; int f118; int f11C; int f120; };
extern Epsel *B_003E1C04;
void InitLo();
extern "C" void InitEpsel(Epsel *self) {
    InitLo();
    self->f110 = -1;
    self->f114 = -1;
    self->f11C = -1;
    self->f120 = -1;
    B_003E1C04 = self;
}
