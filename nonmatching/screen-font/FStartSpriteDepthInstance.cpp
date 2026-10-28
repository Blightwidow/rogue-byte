/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CHAR { int pad0; int kind; char pad1[8]; int isprite; };
struct SLOT { char pad0[0x10]; char pos[0x20]; CHAR *pchar; char pad1[0x58 - 0x34]; int iinst; char pad2[0x64 - 0x5C]; int idDepth; char sle[8]; char pad3[0x70 - 0x6C - 8 + 4 + 4 - 4]; };
struct INST { int cslot; SLOT *aslot; int pad[4]; };
struct SPRITE { char pad0[8]; INST *ainst; char pad1[0x30 - 0xC]; };
struct BLOT { char pad[0x84]; SPRITE *psprite; };
extern "C" {
void StopSpriteInstance(SPRITE *, int);
void ClearSle(void *);
int IinstFindFreeSprite(SPRITE *);
void StartSpriteInstance(float, SPRITE *, int, int, void *, void *, void *);
int FStartSpriteDepthInstance(BLOT *pblot, int isprite, int ilabel, int idDepth, int cslot, SLOT *aslot)
{
    if (aslot == 0) {
        INST *root = pblot->psprite[0].ainst;
        cslot = root->cslot;
        aslot = root->aslot;
    }
    for (int islot = 0; islot < cslot; islot++) {
        SLOT *slot = &aslot[islot];
        CHAR *pchar = slot->pchar;
        if (pchar == 0 || pchar->kind != 4)
            continue;
        if (pchar->isprite == isprite) {
            if (idDepth == slot->idDepth) {
                StopSpriteInstance(&pblot->psprite[isprite], slot->iinst);
                ClearSle(slot->sle);
                slot->iinst = IinstFindFreeSprite(&pblot->psprite[isprite]);
                unsigned addv = 0x7F7F7F7F;
                unsigned mulv = 0xFFFFFFFF;
                unsigned add[4];
                unsigned mul[4];
                add[0] = addv;
                mul[0] = mulv;
                StartSpriteInstance(0.0f, &pblot->psprite[isprite], ilabel, slot->iinst, slot->pos, add, mul);
                return 1;
            }
        } else {
            INST *pinst = &pblot->psprite[pchar->isprite].ainst[slot->iinst];
            if (FStartSpriteDepthInstance(pblot, isprite, ilabel, idDepth, pinst->cslot, pinst->aslot))
                return 1;
        }
    }
    return 0;
}
}
