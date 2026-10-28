#include "sly2.h"
struct B4 { char b[4]; };
struct Slot { B4 add; B4 mul; char pad[8]; QW mat0; QW mat1; };
struct LABEL { char pad0[8]; float dt; char pad1[0x18 - 0xC]; };
struct INST { char pad0[8]; short ilabel; short ikeyNext; float t; int fPaused; char pad1[0x18 - 0x14]; };
struct SPRITE;
struct BLOT { char pad[0x84]; SPRITE *sprites; };
struct SPRITE { char pad0[4]; LABEL *labels; INST *insts; char pad1[0x24 - 0xC]; BLOT *pmovie; char pad2[0x30 - 0x28]; };
extern "C" {
int FGetSpriteSlotTransform(BLOT *, int, QW *, B4 *, B4 *, int, void *);
void ClearSpriteInstance(SPRITE *, int);
void UpdateSpriteInstance(float, SPRITE *, int, QW *, B4 *, B4 *);
}
void SeekSpriteInstanceTime(float t, SPRITE *sprite, int iinst, Slot *slot)
{
    struct { QW mat[2]; B4 add[4]; B4 mul[4]; B4 ca[4]; B4 cm[4]; B4 cm2[4]; } l;
    if (sprite->insts[iinst].ilabel < 0)
        return;
    float dt = sprite->labels[sprite->insts[iinst].ilabel].dt;
    register float lo asm("$f0");
    asm("mtc1 $0, %0\n\tnop\n\tmax.s %0, %0, %1" : "=&f" (lo) : "f" (t));
    float tc = lo < dt ? lo : dt;
    if (slot != 0) {
        l.mat[0] = slot->mat0;
        l.mat[1] = slot->mat1;
        l.add[0] = slot->add;
        l.mul[0] = slot->mul;
    } else {
        BLOT *blot = sprite->pmovie;
        int index = sprite - blot->sprites;
        if (!FGetSpriteSlotTransform(blot, index, l.mat, l.add, l.mul, 0, 0))
            return;
    }
    ClearSpriteInstance(sprite, iinst);
    sprite->insts[iinst].t = 0.0f;
    sprite->insts[iinst].ikeyNext = 0;
    sprite->insts[iinst].fPaused = 0;
    l.ca[0] = l.add[0];
    l.cm[0] = l.mul[0];
    UpdateSpriteInstance(0.0f, sprite, iinst, l.mat, l.ca, l.cm);
    sprite->insts[iinst].fPaused = 0;
    l.ca[0] = l.add[0];
    l.cm2[0] = l.mul[0];
    UpdateSpriteInstance(tc, sprite, iinst, l.mat, l.ca, l.cm2);
    sprite->insts[iinst].fPaused = 1;
}
