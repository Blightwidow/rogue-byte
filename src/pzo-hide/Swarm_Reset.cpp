#include "sly2.h"
struct DL { int a, b; };
struct DLE { int next; };
struct Group { int pad0; int total; int pad8; int alive; char pad10[0x20]; };
struct Group2 { char pad0[0x10]; DL dl; };
struct Rider { char pad0[0x20]; Group2 *group; char pad24[0x3C]; DLE dle; };
struct Swarm { char pad0[0x1C8]; int count; Group groups[1]; char pad1fc[0x90]; Rider *dead; };
extern "C" void func_0017F6B0(Swarm *);
extern "C" void ClearDle__FP3DLE(DLE *);
extern "C" void AppendDlEntry(DL *, char *);
extern "C" void ClearDl__FP2DL(void *);
extern "C" void SwarmGroup_PlaceRiders(Swarm *, Group *);
extern "C" void Swarm_Reset(Swarm *swarm)
{
    func_0017F6B0(swarm);
    Rider *rider = swarm->dead;
    while (rider) {
        Rider *next = (Rider *)rider->dle.next;
        ClearDle__FP3DLE(&rider->dle);
        AppendDlEntry(&rider->group->dl, (char *)rider);
        rider = next;
    }
    ClearDl__FP2DL(&swarm->dead);
    for (int index = 0; index < swarm->count; index++) {
        Group *group = &swarm->groups[index];
        group->alive = group->total;
        SwarmGroup_PlaceRiders(swarm, group);
    }
}
