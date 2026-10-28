#include "sly2.h"
struct XP { char pad[0x30]; QW vel0; char pad1[0x70 - 0x40]; QW vel1; QW normal; float gDist; char pad2[0x9C - 0x94]; int kind; };
struct STEP { char pad[0x180]; int uTarget; char pad1[0x190 - 0x184]; QW vTarget; char pad2[0x1B0 - 0x1A0]; QW row0; QW row1; QW row2; char pad3[0x210 - 0x1E0]; float reach; char pad4[0x248 - 0x214]; float reachBase; };
struct SMP;
extern "C" {
extern float g_2dded0[];
extern char D_002C3C98[];
extern char D_002C3CA8[];
void func_001F4FC0(STEP *);
void GSmooth__FfffP3SMPPf(float, float, float, void *, float *);
void AdjustStepXpVelocity(STEP *pstep, XP *pxp, int iside)
{
    struct { QW junk; float asv[2]; } l;
    int bits;
    func_001F4FC0(pstep);
    if (pxp->kind != 0xE) return;
    asm("lqc2 vf2, %0" : : "m" (pxp->vel1));
    asm("lqc2 vf3, %0" : : "m" (pxp->vel0));
    asm("lqc2 vf1, %0" : : "m" (pxp->normal));
    asm("vsub.xyzw vf3, vf3, vf2\n\tvmul.xyz vf3, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf3, vf3y\n\tvmaddz.x vf3, vf2, vf3z");
    asm("qmfc2.ni %0, vf3" : "=r" (bits));
    float gSpeed;
    asm("mtc1 %1, %0" : "=f" (gSpeed) : "r" (bits));
    GSmooth__FfffP3SMPPf(pxp->gDist, pstep->reach, g_2dded0[1], D_002C3C98, &l.asv[0]);
    GSmooth__FfffP3SMPPf(pxp->gDist, 0.0f, g_2dded0[1], D_002C3CA8, &l.asv[1]);
    float svCompress = l.asv[0];
    float svExpand = l.asv[1];
    gSpeed = gSpeed > svCompress ? gSpeed : svCompress;
    float limited;
    if (gSpeed < svExpand) {
        float delta = svExpand - gSpeed;
        register float f0 asm("$f0") = g_2dded0[1];
        register float f2 asm("$f2") = delta;
        asm(".set noat\n\tlui $1, 0x460C\n\tori $1, $1, 0xA000\n\tmtc1 $1, $f1\n\tnop\n\tmul.s $f0, $f0, $f1\n\tmin.s $f0, $f0, $f2\n\t.set at" : "+f" (f0) : "f" (f2) : "$1", "$f1");
        limited = f0;
    } else {
        float delta = svExpand - gSpeed;
        register float f0 asm("$f0") = g_2dded0[1];
        register float f2 asm("$f2") = delta;
        asm(".set noat\n\tlui $1, 0xC58C\n\tori $1, $1, 0xA000\n\tmtc1 $1, $f1\n\tnop\n\tmul.s $f0, $f0, $f1\n\tmax.s $f0, $f0, $f2\n\t.set at" : "+f" (f0) : "f" (f2) : "$1", "$f1");
        limited = f0;
    }
    asm("" : "+f" (limited));
    gSpeed = gSpeed + limited;
    float neg = -gSpeed;
    QW *pvSide = (QW *)((char *)pxp + iside * 0x40);
    int negBits;
    QW *pmat = &pstep->row0;
    asm("lqc2 vf5, %0" : : "m" (pmat[2]));
    asm("lqc2 vf1, %0" : : "m" (pmat[1]));
    asm("lqc2 vf2, %0" : : "m" (pstep->row0));
    asm("lqc2 vf3, %0" : : "m" (pstep->vTarget));
    asm("lqc2 vf4, %0" : : "m" (pxp->normal));
    asm("vmulax.xyz ACC, vf2, vf3x\n\tvmadday.xyz ACC, vf1, vf3y\n\tvmaddz.xyz vf3, vf5, vf3z");
    asm("mfc1 %0, %1" : "=r" (negBits) : "f" (neg));
    asm("vmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf1, vf2z");
    asm("qmtc2.ni %0, vf5" : : "r" (negBits));
    asm("vmulx.xyzw vf2, vf4, vf2x");
    int uBits = pstep->uTarget;
    asm("vsub.xyzw vf3, vf3, vf2");
    asm("lqc2 vf1, %0" : : "m" (pvSide[3]));
    asm("qmtc2.ni %0, vf6" : : "r" (uBits));
    asm("sqc2 vf5, %0" : "=m" (l.junk));
    asm("vadda.xyzw ACC, vf0, vf1\n\tvmaddax.xyzw ACC, vf4, vf5x\n\tvmaddx.xyzw vf1, vf3, vf6x");
    asm("sqc2 vf1, %0" : "=m" (pvSide[3]));
    asm("sqc2 vf6, %0" : "=m" (l.junk));
    pxp->gDist = pxp->gDist + (pstep->reach - pstep->reachBase);
}
}
