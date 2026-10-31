extern "C" void *memmove(void *, const void *, unsigned int);
extern "C" void *PentryFindSensorLo(void *, void *, int);
extern "C" float g_2dded0;

struct Entry { void *plo; int seen; float t; int pad; };

int AddGuardSensedObject(char *guard, void *plo, int append)
{
    if (plo != 0) {
        if (plo != guard) {
            unsigned x = 0;
            if (append == 0) x = (unsigned)PentryFindSensorLo(*(void **)(guard + 0xF64), plo, append);
            if (x == 0) {
                register char *list asm("$4") = *(char **)(guard + 0xF64);
                x = *(unsigned *)(list + 0xFC);
                if (x >= 8) {
                    if (append == 0) {
                        int tail = *(int *)(guard + 0x3A4);
                        if (tail > 0) {
                            *(int *)(guard + 0x3A4) = tail - 1;
                            x = 8;
                            x -= tail;
                            x <<= 4;
                            x += 0x100;
                            x = (unsigned)list + x;
                            memmove((Entry *)x + 1, (Entry *)x, (tail - 1) * 16);
                            goto done;
                        }
                    }
                    return 0;
                }
                if (append != 0) {
                    x = (unsigned)list + ((x << 4) + 0x100);
                } else {
                    int tail = *(int *)(guard + 0x3A4);
                    x -= tail;
                    x <<= 4;
                    x += 0x100;
                    x = (unsigned)list + x;
                    memmove((Entry *)x + 1, (Entry *)x, tail * 16);
                }
            done:
                Entry *entry = (Entry *)x;
                entry->plo = plo;
                entry->seen = 0;
                entry->t = g_2dded0;
                *(int *)(*(char **)(guard + 0xF64) + 0xFC) += 1;
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
