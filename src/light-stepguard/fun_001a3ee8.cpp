#include "sly2.h"
struct Sw { char pad[0x4154]; void *lights[0x100]; int dirty; char pad2[8]; int regions; void *regionSets; char pad3[8]; char globalSet[0x20]; };
extern "C" void AddLightToSw(Sw *, void *);

extern "C" void func_001A3EE8(Sw *sw)
{
    if (sw->dirty != 0) {
        sw->dirty = 0;
        memset(sw->globalSet, 0, 0x20);
        memset(sw->regionSets, 0, sw->regions << 5);
        unsigned index = 0;
        void **light = sw->lights;
        do {
            if (*light != 0)
                AddLightToSw(sw, *light);
            index++;
            light++;
        } while (index < 0x100);
    }
}
