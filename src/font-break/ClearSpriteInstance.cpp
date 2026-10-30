// SPDX-License-Identifier: GPL-3.0-or-later
struct SPRITESLOT { char pad[0x30]; void *pdepth; char pad2[0x70 - 0x34]; };
struct SPRITEGROUP { int count; SPRITESLOT *aslot; char pad[0x10]; };
struct SPRITES { char pad[8]; SPRITEGROUP *agroup; };
extern "C" void InitDepthSlot(SPRITESLOT *);
extern "C" void func_002158C0(void *, SPRITESLOT *);
extern "C" void ClearSpriteInstance(SPRITES *psprites, int igroup)
{
    SPRITEGROUP *pgroup = (SPRITEGROUP *)(igroup * 0x18 + (int)psprites->agroup);
    int count = pgroup->count;
    SPRITESLOT *aslot = pgroup->aslot;
    for (int i = 0; i < count; i++) {
        SPRITESLOT *pslot = &aslot[i];
        if (pslot->pdepth)
            func_002158C0(pslot->pdepth, pslot);
        else
            InitDepthSlot(pslot);
    }
}
