#include "sly2.h"
struct LABEL { char pad[0x14]; int id; };
struct SPRITE { unsigned short clabel; short pad; LABEL *alabel; char pad2[0x28]; };
struct BLOT { char pad[0x7C]; int labelCur; unsigned short csprite; short pad2; SPRITE *asprite; };
extern "C" {
int func_00218738(void *);
int func_00218710(void *);
int FBlotLabelPlaying(BLOT *pblot, int label)
{
    if (label == -1)
        return 0;
    if (pblot->labelCur == -1)
        return 0;
    if (label == 0x314)
        return func_00218738(pblot->asprite) == 0;
    int isprite;
    for (isprite = 0; isprite < (int)pblot->csprite; isprite++) {
        SPRITE *psprite = &pblot->asprite[isprite];
        int ilabel;
        for (ilabel = 0; ilabel < (int)psprite->clabel; ilabel++) {
            if (label == psprite->alabel[ilabel].id)
                return func_00218710(psprite);
        }
    }
    return 0;
}
}
