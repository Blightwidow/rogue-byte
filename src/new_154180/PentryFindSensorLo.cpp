#include "sly2.h"
struct SENSORENTRY154180 { int key; int pad[3]; };
struct SENSORLO154180 { char pad[0xFC]; int count; SENSORENTRY154180 entry[1]; };
extern "C" {
SENSORENTRY154180 *PentryFindSensorLo(SENSORLO154180 *lo, int key)
{
    if (key == 0)
        return 0;
    for (int index = 0; index < lo->count; index++) {
        SENSORENTRY154180 *entry = &lo->entry[index];
        if (entry->key == key)
            return entry;
    }
    return 0;
}
}
