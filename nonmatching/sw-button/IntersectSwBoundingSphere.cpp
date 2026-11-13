// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

extern "C" {
struct Obj20FC60 { char pad0[0x60]; Obj20FC60 *next; };
struct Node20FC60 { char pad0[0x20]; QW center; float radius; Obj20FC60 *first; char pad38[8]; Node20FC60 *next; };
struct World20FC60 { char pad0[0x3D1C]; Node20FC60 *nodes; };
struct Alloc20FC60 { int size; int align; char pad8[8]; QW center; };
void *PvAllocStackImpl__Fi(Alloc20FC60 *);
void UpdateSwAaox__FP2SW(World20FC60 *);
void func_00133E30(World20FC60 *);

void IntersectSwBoundingSphere(World20FC60 *world, QW center, int (*filter)(int, Obj20FC60 *), int context, int *pcount, float radius, Obj20FC60 ***plist)
{
    int count = 0;
    Alloc20FC60 req;
    req.center = center;
    req.size = 0x400;
    req.align = 0x10;
    Obj20FC60 **list = (Obj20FC60 **)PvAllocStackImpl__Fi(&req);
    func_00133E30(world);
    UpdateSwAaox__FP2SW(world);
    for (Node20FC60 *node = world->nodes; node != 0; node = node->next) {
        float nodeRadius = node->radius;
        QW offset = VectorSub(req.center, node->center);
        float distanceSquared = LaneX(DotProduct(offset, offset));
        float reach = radius + nodeRadius;
        float reachSquared = reach * reach;
        if (reachSquared < distanceSquared) continue;
        for (Obj20FC60 *obj = node->first; obj != 0; obj = obj->next) {
            if ((filter == 0 || filter(context, obj) != 0) && count < 0x100) {
                list[count] = obj;
                count++;
            }
        }
    }
    *plist = list;
    *pcount = count;
}
}
