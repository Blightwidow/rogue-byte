#include "sly2.h"
struct NODE { float nx, ny, gDist; unsigned short aichild[2]; };
struct CG { char pad[0xC]; void *aface; int cnode; NODE *anode; };
void *PcgtPointInCgQuick(CG *cg, QW pos, unsigned long grf)
{
    void * result;
    QW rotated, packed, vec;
    float x, y, z = -1.0f;
    int bitsX, bitsY, bitsZ;
    asm("prot3w %0, %1" : "=r" (rotated) : "r" (pos));
    asm("mtc1 %1, %0" : "=f" (x) : "r" (pos));
    asm("mtc1 %1, %0" : "=f" (y) : "r" (rotated));
    asm("mfc1 %0, %1" : "=r" (bitsX) : "f" (x));
    asm("mfc1 %0, %1" : "=r" (bitsY) : "f" (y));
    asm("pextlw %0, %1, %2" : "=r" (packed) : "r" (bitsY), "r" (bitsX));
    asm("mfc1 %0, %1" : "=r" (bitsZ) : "f" (z));
    asm("pcpyld %0, %1, %2" : "=r" (vec) : "r" (bitsZ), "r" (packed));
    QW spill = vec;
    asm("" : : "m" (spill));
    NODE *anode = cg->anode;
    NODE *end = anode + cg->cnode;
    unsigned leaf = (grf & 1) ? 0x8000 : 0x4000;
    if (anode == end)
        return 0;
    asm("qmtc2.ni %0, vf3" : : "r" (vec));
    NODE *node = anode;
    for (;;) {
        float dist;
        asm("lqc2 vf1, 0(%0)" : : "r" (node));
        asm("vmul.xyz vf1, vf1, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        asm("qmfc2.ni %0, vf1" : "=r" (dist));
        unsigned child = node->aichild[0.0f < dist ? 1 : 0];
        if (child & 0x8000) {
            if (child & leaf)
                { result = (char *)cg->aface + (child & 0x3FFF) * 12; goto done; }
            { result = 0; goto done; }
        }
        node = anode + child;
        if (node == end)
            return 0;
    }
done:
    return result;
}
