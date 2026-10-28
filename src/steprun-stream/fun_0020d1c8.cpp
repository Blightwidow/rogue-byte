struct Guard { int unk0; int unk0x4; int unk0x8; int unk0xC; int unk0x10; };
extern "C" void SetGuardDamageState(Guard *, int);
void func_0020D1C8(Guard *guard)
{
    guard->unk0x4 = -1;
    guard->unk0x10 = 1;
    SetGuardDamageState(guard, 0);
}
