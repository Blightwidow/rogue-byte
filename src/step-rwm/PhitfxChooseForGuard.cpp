struct Hitfx { char pad[0x44]; void *plo; char pad2[0xC]; int state; Hitfx *next; };
struct VT { char pad[0x2C8]; short delta; short index; int (*fn)(void *, void *); };
struct Guard { char pad[0xC]; VT *vt; char pad2[0xF04 - 0x10]; float tnext; char pad3[0xF64 - 0xF08]; void *sensor; };
struct Entry { int pad; int state; };
extern Hitfx *B_003E148C;
extern float g_2dded0;
extern const float D_002C3DB0;
extern "C" {
int func_00208D70(Guard *);
Entry *PentryFindSensorLo(void *, void *);
void SetSensorEntryState(void *, Entry *, int);
int NCompareHitfxForGuard(Guard *, Hitfx *, Hitfx *);
}

Hitfx *PhitfxChooseForGuard(Guard *guard, Hitfx *current)
{
    int pad;
    if (func_00208D70(guard) == 0) return current;
    Hitfx *best = current;
    for (Hitfx *fx = B_003E148C; fx != 0; fx = fx->next) {
        if (guard->vt->fn((char *)guard + guard->vt->delta, fx) == 0) continue;
        if (best == 0 || NCompareHitfxForGuard(guard, fx, best) < 0) best = fx;
    }
    asm volatile("" : : "m" (pad));
    if (best != 0) {
        if (best->state == 4) {
            Entry *entry = PentryFindSensorLo(guard->sensor, best->plo);
            if (entry != 0) {
                if (entry->state == 0) {
                    SetSensorEntryState(guard->sensor, entry, 2);
                    guard->tnext = g_2dded0 + D_002C3DB0;
                }
                return current;
            }
        }
    }
    return best;
}
