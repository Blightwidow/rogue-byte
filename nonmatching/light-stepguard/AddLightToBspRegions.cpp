#include "sly2.h"
struct BspNode1A3B80 { QW plane; BspNode1A3B80 *pfront; BspNode1A3B80 *pback; int regionFront; int regionBack; };
struct Bsp1A3B80 { char pad[0x4564]; char *pregions; };
extern "C" void *func_002564B8(void *);
extern "C" void AddLightToBspRegions(Bsp1A3B80 *pbsp, BspNode1A3B80 *pnode, QW pos, float radius, int ilight)
{
    struct { QW vecA; QW vecB; QW pos; QW plane; } l;
    l.pos = pos;
    l.plane = pnode->plane;
    func_002564B8(&l.vecA);
    func_002564B8(&l.vecB);
    float dist;
    int distBits;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    asm("lqc2 vf3, %0" : : "m" (l.plane));
    asm("lqc2 vf4, %0" : : "m" (l.pos));
    asm("vmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w" : "=j" (v1), "=j" (v2));
    asm("vadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w" : "=j" (v2) : "j" (v1), "j" (v2));
    asm("qmfc2.ni %0, vf2" : "=r" (distBits) : "j" (v2));
    asm("mtc1 %1, %0" : "=f" (dist) : "r" (distBits));
    asm volatile("sqc2 vf1, %0" : "=m" (l.vecB) : "j" (v1));
    asm volatile("sqc2 vf2, %0" : "=m" (l.vecA) : "j" (v2));
    if (dist < radius) {
        if (pnode->pfront != 0) {
            AddLightToBspRegions(pbsp, pnode->pfront, l.pos, radius, ilight);
        } else {
            unsigned *pword = (unsigned *)((pnode->regionFront << 5) + (int)pbsp->pregions + (ilight / 32) * 4);
            *pword |= 1 << ilight;
        }
    }
    if (-radius < dist) {
        if (pnode->pback != 0) {
            AddLightToBspRegions(pbsp, pnode->pback, l.pos, radius, ilight);
            return;
        }
        unsigned *pword = (unsigned *)((pnode->regionBack << 5) + (int)pbsp->pregions + (ilight / 32) * 4);
        *pword |= 1 << ilight;
    }
}
