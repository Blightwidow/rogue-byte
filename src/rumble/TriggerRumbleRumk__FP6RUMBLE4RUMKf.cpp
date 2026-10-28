struct RUMBLE;
struct RUMPAT;
extern "C" char D_002C2260;
void TriggerRumbleRumpat__FP6RUMBLEP6RUMPATf(RUMBLE *, RUMPAT *, float);
extern "C" void TriggerRumbleRumk__FP6RUMBLE4RUMKf(RUMBLE *rumble, int rumk, float scale)
{
    TriggerRumbleRumpat__FP6RUMBLEP6RUMPATf(rumble, (RUMPAT *)(&D_002C2260 + rumk * 0x104), scale);
}
