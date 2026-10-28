#include "sly2.h"
struct LM { float lo; float hi; };
struct EMITVX;
struct EMITO;
struct EMITV { char pad0[0xC]; float rSvz; char pad1[0x38 - 0x10]; float uRandom; float dtLife; char pad2[0x48 - 0x40]; LM skip; LM birth; };
extern "C" float GRandInRange(float, float);
extern float g_2dded0;
void ChooseEmitVelocity(EMITVX *, float, float, LM *, VECTOR *, int, VECTOR *);
void ChooseEmitvVelocityAge(EMITV *pemitv, EMITVX *pemitvx, EMITO *pemitb, int iParticle, VECTOR *ppos, VECTOR *pnormal, VECTOR *pv, float *ptCreated, float *ptDestroy)
{
    ChooseEmitVelocity(pemitvx, pemitv->uRandom, pemitv->rSvz, (LM *)pemitv, pnormal, iParticle, pv);
    float tNow = g_2dded0;
    float dtBirth = GRandInRange(pemitv->birth.lo, pemitv->birth.hi);
    *ptCreated = tNow - dtBirth;
    *ptDestroy = (tNow - dtBirth) + pemitv->dtLife;
    float dtSkip = GRandInRange(pemitv->skip.lo, pemitv->skip.hi);
    float zero = 0.0f;
    asm volatile("nop" : : "f" (zero));
    if (dtSkip != zero) {
        QW junk;
        asm("lqc2 vf2, %2\n\tqmtc2.ni %3, vf3\n\tlqc2 vf1, %4\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf2, vf3x\n\tsqc2 vf3, %1\n\tsqc2 vf1, %0" : "=m" (*ppos), "=m" (junk) : "m" (*pv), "r" (dtSkip), "m" (*ppos));
    }
}
