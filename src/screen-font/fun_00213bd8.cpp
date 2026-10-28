#include "sly2.h"
struct LABEL { char pad[0x14]; int id; };
struct SPRITE { unsigned short clabel; short pad; LABEL* labels; char pad2[0x30 - 8]; };
struct BLOT { char pad[0x80]; unsigned short csprite; short pad2; SPRITE* sprites; };
extern "C" void FStartSpriteDepthInstance(BLOT*, int, int, int, int, int);
extern "C" void func_00213BD8(BLOT* pblot, int label, int idDepth)
{
    for (int isprite = 0; isprite < pblot->csprite; isprite++) {
        SPRITE* psprite = &pblot->sprites[isprite];
        for (int ilabel = 0; ilabel < psprite->clabel; ilabel++) {
            LABEL* plabel = &psprite->labels[ilabel];
            if (label == plabel->id) {
                FStartSpriteDepthInstance(pblot, isprite, ilabel, idDepth, 0, 0);
                return;
            }
        }
    }
}
