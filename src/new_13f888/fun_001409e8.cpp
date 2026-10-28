#include "sly2.h"
extern "C" {
int bevy_player_p15_binoc_active(void *);
QW PosLoWorld(void *);
void *PhitfxSpawn(int, QW, void *);
int FIsGuardInSgs(void *, int);
int FHitFxSensorReaches(void *, void *);
void HitFx_Remove(void *);
}
struct GVT { char pad[0x2C8]; short delta; short idx; int (*fn)(void *, void *); };
struct Guard { char pad[0xC]; GVT *vt; char pad2[0xFE0 - 0x10]; Guard *next; };
struct Sensor { char pad[0x104]; Sensor *next; };
extern Guard *B_003E1444;
extern Sensor *B_003E1468;
int func_001409E8(char *jt)
{
    QW scratch;
    asm("" : "=m"(scratch));
    if (bevy_player_p15_binoc_active(jt))
        return 2;
    void *handle = 0;
    if (*(int *)(jt + 0x10C4)) {
        QW pos = PosLoWorld(jt);
        handle = PhitfxSpawn(*(int *)(jt + 0x10C4), pos, jt);
    }
    if (!handle)
        return 2;
    int state = 0;
    for (Guard *guard = B_003E1444; guard; guard = guard->next) {
        if (FIsGuardInSgs(guard, 0x1D) || FIsGuardInSgs(guard, 0xB)) {
            state = 2;
            break;
        }
        if (guard->vt->fn((char *)guard + guard->vt->delta, handle)) {
            state = 1;
            break;
        }
    }
    if (!state) {
        for (Sensor *sensor = B_003E1468; sensor; sensor = sensor->next) {
            if (FHitFxSensorReaches(sensor, handle)) {
                state = 1;
                break;
            }
        }
    }
    HitFx_Remove(handle);
    return state;
}
