#include "sly2.h"
struct RIDER { QW pos; QW tangent; char pad[0x4C - 0x20]; int hp; char pad2[0x58 - 0x50]; float vSide; float vRoll; };
struct MSG { char pad[0x10]; int dhp; char pad1[0x20 - 0x14]; QW hitPos; QW hitDir; char pad2[0x44 - 0x40]; unsigned flags; };
struct SWARM { char pad[0x190]; void *pexpl; };
extern "C" {
RIDER *Swarm_PriderNearest(SWARM *, QW);
float GRandInRange(float, float);
void Swarm_SetRiderState(SWARM *, RIDER *, int);
void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(void *, unsigned, void *, QW, QW, float, float);
extern QW g_2a2dc0;
extern QW g_2a2dd0;
extern float D_FLT_002BE8A8;
}
extern "C" int Swarm_FTakeHit(SWARM *pswarm, MSG *pmsg)
{
    if (!(pmsg->flags & 8))
        return 0;
    RIDER *prider = Swarm_PriderNearest(pswarm, pmsg->hitPos);
    if (!prider)
        return 1;
    int hp = prider->hp + pmsg->dhp;
    prider->hp = hp;
    if (hp > 0) {
        QW *pup = &g_2a2dc0;
        asm("lqc2 vf3, 0x10(%0)" : : "r" (prider));
        asm("lqc2 vf2, 0x30(%0)" : : "r" (pmsg));
        asm("lqc2 vf1, 0(%0)" : : "r" (pup));
        asm("vopmula.xyz ACC, vf1, vf3\n\tvopmsub.xyz vf1, vf3, vf1");
        float kick = D_FLT_002BE8A8;
        asm("vmul.xyz vf2, vf2, vf1\n\tvaddw.x vf3, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf3, vf2z");
        int bits;
        asm("qmfc2.ni %0, vf2" : "=r" (bits));
        float dot;
        asm("mtc1 %1, %0\n\tnop" : "=f" (dot) : "r" (bits));
        prider->vSide = dot * kick;
        prider->vRoll = GRandInRange(-15.0f, 15.0f);
        Swarm_SetRiderState(pswarm, prider, 1);
        asm volatile("");
        return 1;
    }
    if (pswarm->pexpl)
        ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(pswarm->pexpl, 4, 0, g_2a2dd0, prider->pos, 0.0f, 0.0f);
    Swarm_SetRiderState(pswarm, prider, 2);
    return 1;
}
