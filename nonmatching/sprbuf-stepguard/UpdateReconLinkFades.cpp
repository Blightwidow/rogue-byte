#include "sly2.h"
struct Link { char pad[0x28]; unsigned long flags; };
struct Target { char pad[0x100]; Link *link; float sFade; };
struct Recon { char pad[0x30]; int count; Target *targets[1]; };
extern "C" QW PosLoWorld(void *);
extern "C" void FadeAloIn(Link *, float);
extern "C" void FadeAloOut(Link *, float);
extern "C" char B_002DDF40[];

void UpdateReconLinkFades(Recon *recon)
{
    for (int index = 0; index < recon->count; index++) {
        Target *target = recon->targets[index];
        if (target->link != 0) {
            QW pos = PosLoWorld(target);
            int token1, token2, token3;
            float distance;
            asm("qmtc2.ni %1, vf3" : "=r" (token1) : "r" (pos));
            register float sFade asm("$f0") = target->sFade;
            asm("lqc2 vf1, %1\n\tvsub.xyzw vf2, vf3, vf1\n\tvmul.xy vf2, vf2, vf2\n\tvaddy.x vf2, vf2, vf2y" : "=r" (token2) : "m" (B_002DDF40[0x90]), "r" (token1));
            asm("vsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q" : "=r" (token3) : "r" (token2));
            register int bits asm("$2");
            asm("qmfc2.ni %0, vf2" : "=r" (bits) : "r" (token3));
            asm("mtc1 %1, %0\n\tnop\n\tnop" : "=f" (distance) : "r" (bits));
            if (sFade < distance && ((target->link->flags >> 60) & 1) == 0)
                FadeAloIn(target->link, 0.25f);
            else if (distance <= sFade && ((target->link->flags >> 60) & 1) == 1)
                FadeAloOut(target->link, 0.25f);
        }
    }
}
