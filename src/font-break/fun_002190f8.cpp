#include "sly2.h"
struct KEY { char pad[7]; unsigned char caction; unsigned char* aaction; char pad2[0x20 - 12]; };
struct LABEL { int unk0; KEY* akey; int unk8; int unkC; void* sprite; };
extern "C" void PauseSpriteInstance(void*, int);
extern "C" void func_002190F8(LABEL* plabel, int ikey, int iinst)
{
    KEY* pkey = &plabel->akey[ikey];
    for (int iaction = 0; iaction < pkey->caction; iaction++) {
        if (pkey->aaction[iaction] == 7)
            PauseSpriteInstance(plabel->sprite, iinst);
    }
}
