#include "sly2.h"
struct AMB;
struct SPRITEINST { char pad[8]; short ilabel; short pad2; float t; int fPaused; AMB *pamb; };
struct SPRITE { char pad[8]; SPRITEINST *ainst; long stamp; float tStopped; int ilabelStopped; int ilabelPending; };
extern "C" {
extern long g_2ddf18;
void StopAmb(AMB *, float);
void VirtualRefPtr_Assign(AMB **, AMB *);
void ClearSpriteInstance(SPRITE *, int);
void StopSpriteInstance(SPRITE *psprite, int iinst)
{
    SPRITEINST *pinst = (SPRITEINST *)(iinst * 0x18 + (int)psprite->ainst);
    if (pinst->ilabel >= 0) {
        int ilabel = pinst->ilabel;
        float t = pinst->t;
        psprite->ilabelStopped = ilabel;
        psprite->tStopped = t;
        pinst->fPaused = 0;
        psprite->ilabelPending = -1;
        psprite->stamp = g_2ddf18;
        pinst->ilabel = -1;
        if (&pinst->pamb != 0) {
            if (pinst->pamb != 0) {
                StopAmb(pinst->pamb, 0.0f);
                VirtualRefPtr_Assign(&pinst->pamb, 0);
            }
        }
    }
    ClearSpriteInstance(psprite, iinst);
}
}
