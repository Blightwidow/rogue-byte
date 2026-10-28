struct Blot { char pad0[0xB0]; int unk0xB0; };
extern "C" void InitLo(Blot *);
void JobBlot_Init(Blot *blot)
{
    InitLo(blot);
    blot->unk0xB0 = 1;
}
