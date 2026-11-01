extern "C" void *memmove(void *, const void *, unsigned int);
extern "C" float g_2dded0;

struct Entry_2085D0 { void *plo; int seen; float t; int pad; };
struct Sensed_2085D0 { char pad[0xFC]; unsigned count; Entry_2085D0 entry[8]; };
struct Guard_2085D0 { char pad0[0x3A4]; int tail; char pad1[0xF64 - 0x3A8]; Sensed_2085D0 *psensed; };
extern "C" unsigned PentryFindSensorLo(Sensed_2085D0 *, void *);

extern "C" int AddGuardSensedObject(Guard_2085D0 *guard, void *plo, int append)
{
    if (plo != 0) {
        if (plo != guard) {
            unsigned x = 0;
            if (append == 0)
                x = PentryFindSensorLo(guard->psensed, plo);
            if (x == 0) {
                Sensed_2085D0 *list = guard->psensed;
                x = list->count;
                if (x >= 8) {
                    if (append == 0) {
                        int tail = guard->tail;
                        if (tail > 0) {
                            guard->tail = tail - 1;
                            x = 8;
                            x -= tail;
                            x <<= 4;
                            x += 0x100;
                            x = (unsigned)list + x;
                            memmove((Entry_2085D0 *)x + 1, (Entry_2085D0 *)x, (tail - 1) * 16);
                            goto done;
                        }
                    }
                    return 0;
                }
                if (append != 0) {
                    x = (unsigned)list + ((x << 4) + 0x100);
                } else {
                    int tail = guard->tail;
                    x -= tail;
                    x <<= 4;
                    x += 0x100;
                    x = (unsigned)list + x;
                    memmove((Entry_2085D0 *)x + 1, (Entry_2085D0 *)x, tail * 16);
                }
            done:
                Entry_2085D0 *entry = (Entry_2085D0 *)x;
                entry->plo = plo;
                entry->seen = 0;
                entry->t = g_2dded0;
                guard->psensed->count += 1;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
