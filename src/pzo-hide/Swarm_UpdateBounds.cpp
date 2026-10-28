#include "sly2.h"
extern "C" void UpdateSoBounds(void*);
extern "C" void GetCrvBounds(void*, QW*, QW*);
extern "C" void ExtendSoBounds(void*, QW, float);
struct Group { char pad0[0x20]; float radius; void* crv; char pad1[0x30 - 0x28]; };
struct Swarm { char pad0[0x1C8]; int count; Group groups[1]; };
extern "C" void Swarm_UpdateBounds(Swarm* swarm)
{
    UpdateSoBounds(swarm);
    for (int i = 0; i < swarm->count; i++) {
        Group* group = &swarm->groups[i];
        QW posMin;
        QW posMax;
        GetCrvBounds(group->crv, &posMin, &posMax);
        ExtendSoBounds(swarm, posMin, group->radius);
        ExtendSoBounds(swarm, posMax, group->radius);
    }
}
