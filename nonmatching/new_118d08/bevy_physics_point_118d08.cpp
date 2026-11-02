// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
// Draft: assembler wall (sqc2 in a jal delay slot plus ps2eeas hazard nops).
struct OBJ_118D08 { char pad[0x18]; int grf; };
struct NODE_118D08 { NODE_118D08 *pnodeBack; NODE_118D08 *pnodeFront; OBJ_118D08 *pobj; };
struct VU_118D08 { QW q; };
extern "C" void *func_002564B8(void *); // empty out-of-line constructor (returns this)
extern "C" int bevy_physics_point_118d08(NODE_118D08 *pnode, NODE_118D08 *pnodeLimit, int cpos, QW *apos, int *pcobj, OBJ_118D08 ***ppobj);
// distance of pos to the plane (plane.xyz . pos.xyz - plane.w), VU0 macro code
static inline float DistPlane(QW *pplane, QW pos, VU_118D08 *pdist, VU_118D08 *pone)
{
    QW posLocal = pos;
    QW planeLocal;
    asm("lqc2 vf1, %1\n\tsqc2 vf1, %0" : "=m"(planeLocal) : "m"(*pplane));
    VU_118D08 dist;
    VU_118D08 one;
    func_002564B8(&dist);
    func_002564B8(&one);
    int bits;
    asm("lqc2 vf1, %3\n\tlqc2 vf3, %4\n\tvmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\t"
        "vmaddaz.x ACC, vf2, vf1z\n\tvmsubw.x vf1, vf2, vf1w\n\tqmfc2.ni %0, vf1\n\tsqc2 vf2, %2\n\tsqc2 vf1, %1"
        : "=r"(bits), "=m"(dist.q), "=m"(one.q) : "m"(planeLocal), "m"(posLocal));
    float d;
    asm("mtc1 %1, %0" : "=f"(d) : "r"(bits));
    return d;
}
extern "C" int bevy_physics_point_118d08(NODE_118D08 *pnode, NODE_118D08 *pnodeLimit, int cpos, QW *apos, int *pcobj, OBJ_118D08 ***ppobj)
{
    if (cpos == 0)
        return 1;
    if (pnode == 0)
        return 1;
    float dMax = DistPlane((QW *)pnode->pobj, apos[0], 0, 0);
    float dMin = dMax;
    for (int ipos = 1; ipos < cpos; ipos++) {
        float d = DistPlane((QW *)pnode->pobj, apos[ipos], 0, 0);
        dMax = dMax > d ? dMax : d;
        dMin = dMin < d ? dMin : d;
    }
    if (dMin > 0.0001f) {
        NODE_118D08 *pnodeFront = pnode->pnodeFront < pnodeLimit ? pnode->pnodeFront : 0;
        if (pnodeFront == 0)
            return 1;
        return bevy_physics_point_118d08(pnodeFront, pnodeLimit, cpos, apos, pcobj, ppobj);
    }
    if (dMax < -0.0001f) {
        NODE_118D08 *pnodeBack = pnode->pnodeBack < pnodeLimit ? pnode->pnodeBack : 0;
        if (pnodeBack == 0)
            return 0;
        return bevy_physics_point_118d08(pnodeBack, pnodeLimit, cpos, apos, pcobj, ppobj);
    }
    NODE_118D08 *pnodeBack = pnode->pnodeBack < pnodeLimit ? pnode->pnodeBack : 0;
    int resultBack = pnodeBack ? bevy_physics_point_118d08(pnodeBack, pnodeLimit, cpos, apos, pcobj, ppobj) : 0;
    NODE_118D08 *pnodeFront = pnode->pnodeFront < pnodeLimit ? pnode->pnodeFront : 0;
    int resultFront = pnodeFront ? bevy_physics_point_118d08(pnodeFront, pnodeLimit, cpos, apos, pcobj, ppobj) : 1;
    if (resultBack == resultFront && resultBack != 2)
        return resultBack;
    if (*pcobj <= 0)
        return 1;
    OBJ_118D08 *pobj = pnode->pobj;
    if (pobj->grf & 0x4000)
        return 2;
    *(*ppobj)++ = pobj;
    pobj->grf |= 0x4000;
    return 2;
}
