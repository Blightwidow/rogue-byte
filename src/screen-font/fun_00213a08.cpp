#include "sly2.h"
struct Label { char p0[0x14]; int id; };
struct Sprite { unsigned short clabel; unsigned short cinst; Label *plabel; char p0[0x30 - 8]; };
struct Blot { char p0[0x80]; unsigned short csprite; Sprite *psprite; };
static inline Label *PlabelFromIndex(Sprite *p, int i) { return &p->plabel[i]; }
extern "C" void FStartSpriteDepthInstance(Blot *, int, int, int, int, int);
void func_00213A08(Blot *pblot, int label, int idDepth)
{
    for (int isprite = 0; isprite < pblot->csprite; isprite++) {
        Sprite *psprite = &pblot->psprite[isprite];
        for (int ilabel = 0; ilabel < psprite->clabel; ilabel++) {
            if (label == PlabelFromIndex(psprite, ilabel)->id)
                FStartSpriteDepthInstance(pblot, isprite, 0, idDepth, 0, 0);
        }
    }
}
