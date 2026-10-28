#include "sly2.h"
struct VTE { short delta; short index; void (*fn)(void *, ...); };
struct VT { char pad[8]; VTE entry[4]; };
struct HITFX { char pad[0xC]; VT *vt; char pad2[0x58 - 0x10]; HITFX *next; };
struct SENSOR { char pad[0xC]; VT *vt; char pad2[0xE0 - 0x10]; unsigned count; HITFX *list[8]; };
extern "C" HITFX *B_003E148C;
extern "C" void UpdateLo(SENSOR *);
extern "C" void SweepHitFxSensor(SENSOR *, int);
extern "C" int FHitFxSensorReaches(SENSOR *, HITFX *);
extern "C" void UpdateHitFxSensor(SENSOR *sensor)
{
    UpdateLo(sensor);
    SweepHitFxSensor(sensor, 0);
    for (HITFX *fx = B_003E148C; fx; fx = fx->next) {
        int count = sensor->count;
        int i;
        for (i = 0; i < count; i++) {
            if (sensor->list[i] == fx) break;
        }
        if (i < count || !FHitFxSensorReaches(sensor, fx)) continue;
        if (sensor->count > 7) return;
        fx->vt->entry[0].fn((char *)fx + fx->vt->entry[0].delta);
        count = sensor->count;
        sensor->list[count] = fx;
        sensor->count = count + 1;
        sensor->vt->entry[2].fn((char *)sensor + sensor->vt->entry[2].delta, 5, 0, 0, 0, 0);
        return;
    }
}
