struct Guard { int unk0; int unk0x4; int unk0x8; int unk0xC; };
extern "C" void SetFallCheckState(Guard *, int);
void func_0020CE40(Guard *guard)
{
    guard->unk0x4 = -1;
    guard->unk0xC = 1;
    SetFallCheckState(guard, 0);
}
