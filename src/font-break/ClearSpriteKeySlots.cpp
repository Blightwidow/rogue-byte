#include "sly2.h"
struct DEPTHSLOT { char pad[0x30]; void *pchar; char pad2[0x3C]; };
struct SPRITEKEY { char pad[6]; unsigned char cclear; char pad2[13]; unsigned short *aclear; char pad3[8]; };
struct LABELINST { char pad[4]; DEPTHSLOT *aslot; char pad2[0x10]; };
struct SPRITELABEL { char pad[4]; SPRITEKEY *akey; char pad2[8]; struct { char pad[8]; LABELINST *ainst; } *pinfo; };
extern "C" {
void func_002158C0(void *, DEPTHSLOT *);
void InitDepthSlot(DEPTHSLOT *);
void ClearSpriteKeySlots(SPRITELABEL *plabel, int ikey, int iinst)
{
    SPRITEKEY *pkey = &plabel->akey[ikey];
    DEPTHSLOT *aslot = plabel->pinfo->ainst[iinst].aslot;
    for (int iclear = 0; iclear < pkey->cclear; iclear++) {
        DEPTHSLOT *pslot = &aslot[pkey->aclear[iclear]];
        if (pslot->pchar != 0)
            func_002158C0(pslot->pchar, pslot);
        else
            InitDepthSlot(pslot);
    }
}
}
