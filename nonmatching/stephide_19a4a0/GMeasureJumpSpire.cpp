#include "sly2.h"
struct B8 { char b[8]; };
struct TRI19AC88 { B8 first; int third; };
struct Locals19AC88 { TRI19AC88 tri; char pad[4]; QW landing; QW velocity; QW bez0; QW bez1; };
struct Jt19AC88 { char pad[0xE8]; char *pdt; char pad2[0x1F30 - 0xEC]; float gStandoff; };
struct Spire19AC88 { Jt19AC88 **ppjt; void *plo; char pad8[8]; QW vel; };
extern "C" QW PosLoWorld(void *);
extern "C" int PredictSurfaceLanding(void *plo, QW pos, QW vel, QW gravity, TRI19AC88 *ptri, QW *pposLanding, QW *pvelLanding, float gStandoff, float dt);
extern "C" void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
static inline float GMin19AC88(float a, float b) { return a < b ? a : b; }
static inline float Length19AC88(QW *pvec)
{
    int token;
    int bits;
    float length;
    asm("lqc2 vf1, %1\n\tvmul.xyz vf1, vf1, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (token) : "m" (*pvec));
    int token2;
    asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (token2) : "r" (token));
    asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (token2));
    asm("mtc1 %1, %0" : "=f" (length) : "r" (bits));
    return length;
}
extern "C" float GMeasureJumpSpire(Spire19AC88 *spire, float time)
{
    Locals19AC88 l;
    void *plo = spire->plo;
    Jt19AC88 *pjt = *spire->ppjt;
    QW pos = PosLoWorld(pjt);
    QW vel = spire->vel;
    PredictSurfaceLanding(plo, pos, vel, *(QW *)(*(char **)((char *)pjt + 0xE8) + 0x80), &l.tri, &l.landing, &l.velocity, pjt->gStandoff, time);
    EvaluateBezierPos__FfffP6VECTORN63(time, 0.0f, 1.0f, pos, vel, l.landing, l.velocity, 0, 0, &l.bez0);
    float first = Length19AC88(&l.bez0);
    EvaluateBezierPos__FfffP6VECTORN63(time, time, 1.0f, pos, vel, l.landing, l.velocity, 0, 0, &l.bez1);
    float second = Length19AC88(&l.bez1);
    time *= 0.5f;
    first += second;
    first *= time;
    return GMin19AC88(first, 1000000.0f);
}
