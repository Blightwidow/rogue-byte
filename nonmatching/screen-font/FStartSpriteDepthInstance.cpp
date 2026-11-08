/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct CHAR { int pad0; int kind; char pad1[8]; int isprite; };
struct SLOT { char pad0[0x10]; char pos[0x20]; CHAR *pchar; char pad1[0x58 - 0x34]; int iinst; char pad2[0x64 - 0x5C]; int idDepth; char sle[8]; char pad3[0x70 - 0x6C - 8 + 4 + 4 - 4]; };
struct INST { int cslot; SLOT *aslot; int pad[4]; };
struct SPRITE { char pad0[8]; INST *ainst; char pad1[0x30 - 0xC]; };
struct BLOT { char pad[0x84]; SPRITE *psprite; };
/* Retail loads slot->iinst (lw 0x58($s0)) in the delay slot of the isprite test, before either branch,
 * so the source reads it into a local after the pchar checks; the else branch indexes the child sprite's
 * INST array with it and passes cslot/aslot straight from ainst[iinst]. The add/mul colours are literal
 * stores that loop.c hoists and reload spills to 0x24/0x28, as in PlayRootSpriteLabelIndex.
 * NEAR 4: retail keeps iinst in $a1, ours in $t2 (global-alloc choice); every other instruction matches. */
extern "C" {
void StopSpriteInstance(SPRITE *);
void ClearSle(void *);
int IinstFindFreeSprite(SPRITE *);
void StartSpriteInstance(float, SPRITE *, int, int, void *, unsigned *, unsigned *);
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
        int iinst = slot->iinst;
        if (pchar->isprite == isprite) {
            if (idDepth == slot->idDepth) {
                StopSpriteInstance(&pblot->psprite[isprite]);
                ClearSle(slot->sle);
                slot->iinst = IinstFindFreeSprite(&pblot->psprite[isprite]);
                unsigned argbaAdd[4];
                unsigned argbaMul[4];
                argbaAdd[0] = 0x7F7F7F7F;
                argbaMul[0] = 0xFFFFFFFF;
                StartSpriteInstance(0.0f, &pblot->psprite[isprite], ilabel, slot->iinst, slot->pos, argbaAdd, argbaMul);
                return 1;
            }
        } else {
            INST *ainst = pblot->psprite[pchar->isprite].ainst;
            if (FStartSpriteDepthInstance(pblot, isprite, ilabel, idDepth, ainst[iinst].cslot, ainst[iinst].aslot))
                return 1;
        }
    }
    return 0;
}
}
