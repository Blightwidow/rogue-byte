#include "sly2.h"
struct LO { char pad[0x28]; unsigned long grfo; };
struct SW { char pad[0x3EB8]; int clo; LO *alo[1]; };
extern "C" QW PosLoWorld(LO *);
extern const float RO_002A7708;
LO *func_001C4AF8(SW *psw, QW pos)
{
    LO *ploNearest = 0;
    float best = RO_002A7708;
    LO **pplo;
    int index;
    for (index = 0, pplo = psw->alo; index < psw->clo; index++, pplo++) {
        LO *plo = *pplo;
        if ((plo->grfo >> 60 & 1) == 0)
            continue;
        QW world = PosLoWorld(plo);
        float dist;
        int tmp;
        asm("lqc2 vf2, %0" : : "m"(pos));
        asm("qmtc2.ni %0, vf3" : : "r"(world));
        asm("vsub.xyzw vf1, vf2, vf3");
        asm("vmul.xyz vf1, vf1, vf1");
        asm("vaddw.x vf2, vf0, vf0w");
        asm("vadday.x ACC, vf1, vf1y");
        asm("vmaddz.x vf1, vf2, vf1z");
        asm("qmfc2.ni %1, vf1\n\tmtc1 %1, %0\n\tnop" : "=f"(dist), "=r"(tmp));
        if (dist < best) {
            best = dist;
            ploNearest = plo;
        }
    }
    return ploNearest;
}
