#include "sly2.h"
struct Label { char p0[0x14]; int id; };
struct Inst { char p0[8]; short state; char p1[0x18 - 0xA]; };
struct Sprite { unsigned short clabel; unsigned short cinst; Label *plabel; Inst *pinst; char p0[0x20 - 0xC]; int pending; char p1[0x30 - 0x24]; };
struct Blot { char p0[0x80]; unsigned short csprite; Sprite *psprite; };
static inline Label *PlabelFromIndex(Sprite *p, int i) { return &p->plabel[i]; }
extern "C" void FStartSpriteLabelInstance(Blot *, int, int, int, int);
void func_00213928(Blot *pblot, int label)
{
    for (int isprite = 0; isprite < pblot->csprite; isprite++) {
        Sprite *psprite = &pblot->psprite[isprite];
        for (int ilabel = 0; ilabel < psprite->clabel; ilabel++) {
            if (label != PlabelFromIndex(psprite, ilabel)->id)
                continue;
            int fPlaying = 0;
            for (int iinst = 0; iinst < psprite->cinst; iinst++) {
                if (psprite->pinst[iinst].state != -1)
                    fPlaying = 1;
            }
            if (fPlaying) {
                FStartSpriteLabelInstance(pblot, isprite, 0, 0, 0);
                return;
            }
            psprite->pending = -1;
            return;
        }
    }
}
