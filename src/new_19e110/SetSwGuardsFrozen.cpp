struct GUARD { char pad[0xFBC]; int mode; };
struct SW { char pad[0x4748]; int frozen; float time; };
extern float g_2dded0[];
extern "C" int CploFindSwObjectsByClass(SW *, int, int, int, int, GUARD **);
extern "C" void SetGuardMode(GUARD *, int);

void SetSwGuardsFrozen(SW *sw, int frozen)
{
    GUARD *aguard[32];
    sw->frozen = frozen;
    sw->time = g_2dded0[0];
    int count = CploFindSwObjectsByClass(sw, 0x105, 0x38, 0, 0x20, aguard);
    for (int index = 0; index < count; index++) {
        GUARD *guard = aguard[index];
        if (frozen) {
            SetGuardMode(guard, 0xE);
        } else if (guard->mode == 0xE) {
            SetGuardMode(guard, -1);
        }
    }
}
