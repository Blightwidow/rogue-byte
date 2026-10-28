#include "sly2.h"
struct ANIM { char pad[0x10]; unsigned long grf; char pad2[8]; };
struct GUARD { char pad[0x4C0]; int count; char pad2[0x0C]; ANIM anims[1]; };
extern "C" {
unsigned long GrfsgsFromSgs(int);
int CsgsMatchGrfsgs(unsigned long, unsigned long);
}
extern "C" ANIM *PguardanimBestMatch(GUARD *pguard, unsigned long grf)
{
    unsigned long lowest = 0;
    int csgsBest = 0;
    ANIM *best = 0;
    for (int sgs = 0; sgs < 0x30;) {
        lowest = GrfsgsFromSgs(sgs);
        sgs++;
        if ((grf & lowest) != 0)
            break;
    }
    for (int index = 0; index < pguard->count; index++) {
        ANIM *anim = &pguard->anims[index];
        int csgs = CsgsMatchGrfsgs(anim->grf, grf);
        if (csgs != 0 && (anim->grf & lowest) != 0 && csgsBest < csgs) {
            csgsBest = csgs;
            best = anim;
        }
    }
    return best;
}
