#include "sly2.h"
struct INST { char pad[8]; short ilabel; };
struct SPRITE { char pad0[8]; INST *pinst; char pad1[0x28 - 0xC]; int fRoot; };
extern char RO_002A3A10[];
extern "C" void StopRootSprite(SPRITE *);
extern "C" void StartSpriteInstance(float, SPRITE *, int, int, void *, unsigned *, unsigned *);

void PlayRootSpriteLabelIndex(SPRITE *psprite, int ilabel)
{
    if (psprite->fRoot) {
        if (psprite->pinst->ilabel >= 0)
            StopRootSprite(psprite);
        unsigned argbaAdd[4];
        unsigned argbaMul[4];
        argbaAdd[0] = 0x7F7F7F7F;
        argbaMul[0] = 0xFFFFFFFF;
        StartSpriteInstance(0.0f, psprite, ilabel, 0, RO_002A3A10, argbaAdd, argbaMul);
    }
}
