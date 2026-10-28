#include "sly2.h"
struct ALOBJ { char pad[0x70]; QW pos; };
struct PART { ALOBJ *palo; int unk4; float radius; int unkc; unsigned long grf; char pad[0x74 - 0x18]; void *pcbsp; char pad2[0xB0 - 0x78]; };
struct ALO { char pad[0xE0]; int cpart; PART *aparts; };
extern "C" int PcgtPointInCbspQuick__FP4CBSPP6VECTOR(void *, int, QW);
int FPointInAloParts(ALO *palo, QW pos)
{
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW vpos asm("vf3");
    asm("qmtc2.ni %1, vf3" : "=j" (vpos) : "r" (pos));
    for (int ipart = 0; ipart < palo->cpart; ipart++) {
        PART *ppart = &palo->aparts[ipart];
        unsigned long grf = ppart->grf;
        if ((grf & 0x4000000000000UL) != 0) continue;
        if ((grf & 0x2000000000000UL) != 0) {
            ALOBJ *pobj = ppart->palo;
            float radius = ppart->radius;
            asm("lqc2 vf1, 0x70(%1)\n\tvsub.xyzw vf1, vf3, vf1" : "=j" (v1) : "r" (pobj), "j" (vpos));
            float radiusSquared = radius * radius;
            asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1) : "j" (v1));
            float dist;
            int bits;
            asm("qmfc2.ni %0, vf1\n\tmtc1 %0, %1\n\tnop" : "=&r" (bits), "=f" (dist) : "j" (v1));
            int inside = dist < radiusSquared;
            if (inside) return 1;
        }
        void *pcbsp = ppart->pcbsp;
        if (pcbsp != 0) {
            QW arg;
            QW slot;
            asm("qmfc2.ni %0, vf3\n\tsqc2 vf3, %1" : "=r" (arg), "=m" (slot) : "j" (vpos));
            int hit = PcgtPointInCbspQuick__FP4CBSPP6VECTOR(pcbsp, 0x7FFFFFFF, arg);
            asm("lqc2 vf3, %1" : "=j" (vpos) : "m" (slot));
            if (hit != 0) return 1;
        }
    }
    return 0;
}
