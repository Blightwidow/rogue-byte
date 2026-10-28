extern "C" int FIsGuardInSgs(void *, int);
struct G { char pad0[0x298]; int unk0x298; char pad1[0x90]; int unk0x32C; };
int FIsGuardInvulnerable(G *guard)
{
if (guard->unk0x32C || guard->unk0x298) return 1; return FIsGuardInSgs(guard, 0x2A) != 0;
}
