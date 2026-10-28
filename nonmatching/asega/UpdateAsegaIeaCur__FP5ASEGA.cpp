#include "sly2.h"
struct EA { float tLocal; int pad[3]; };
struct ASEG { char pad[0xA0]; int cea; EA *aea; };
struct ASEGA { char pad[0x14]; ASEG *paseg; char pad18[4]; float tLocal; char pad20[0x20]; float svtLocal; char pad44[0xC]; int ieaCur; };

extern "C" void UpdateAsegaIeaCur__FP5ASEGA(ASEGA *pasega)
{
    ASEG *paseg = pasega->paseg;
    int iea = paseg->cea;
    if (iea == 0)
        return;
    if (pasega->svtLocal >= 0.0f) {
        int cea = iea;
        iea = 0;
        for (; iea < cea; iea++) {
            if (pasega->tLocal <= paseg->aea[iea].tLocal)
                break;
        }
        pasega->ieaCur = iea;
        return;
    }
    for (iea--; iea >= 0; iea--) {
        if (pasega->paseg->aea[iea].tLocal <= pasega->tLocal)
            break;
    }
    pasega->ieaCur = iea + 1;
}
