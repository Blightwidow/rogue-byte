#include "sly2.h"
extern float g_2c1ec4, g_2c1ec8, g_2c1ecc;
extern QW g_2a2dc0, g_2a2da0;
extern "C" {
float SRandNearCrv(void *, float, float);
void GetPathPosFromS(float, void *, QW *, QW *);
float GRandInRange(float, float);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
}
struct Frame { QW pos; QW lift; QW right; QW tangent; QW q40; QW q50; QW offset; QW q70; };

extern "C" void func_001CBBA8(void *pcrv, QW *pposOut, QW *pvecOut, float s)
{
    Frame f;
    float sProbe = SRandNearCrv(pcrv, s, g_2c1ec4);
    GetPathPosFromS(sProbe, pcrv, &f.pos, &f.tangent);
    float epsilon = 0.0001f;
    register QW v1 asm("vf1");
    register QW v2 asm("vf2");
    register QW v3 asm("vf3");
    register QW v4 asm("vf4");
    asm volatile("lqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf3, vf1, vf2\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=j" (v1), "=j" (v2), "=j" (v3) : "m" (f.tangent), "m" (g_2a2dc0));
    QW fallback = g_2a2da0;
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=j" (v1) : "j" (v1));
    QW lengthBits;
    asm volatile("qmfc2.ni %0, vf1" : "=r" (lengthBits));
    float length;
    asm volatile("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (lengthBits));
    asm("qmtc2.ni %1, vf2" : "=j" (v2) : "r" (fallback));
    if (length < epsilon)
        goto skip;
    {
        asm volatile("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf2, vf3, Q" : "=j" (v2) : "j" (v1), "j" (v3));
    }
skip:
    asm volatile("lqc2 vf1, %2\n\tvopmula.xyz ACC, vf2, vf1\n\tvopmsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0\n\tsqc2 vf2, %1" : "=m" (f.lift), "=m" (f.right) : "m" (f.tangent), "j" (v2) : "memory");
    float rnd = GRandInRange(-1.0f, 1.0f);
    float rndAbs = __builtin_fabsf(rnd);
    QW offset2d = SetVectorCylind__FP6VECTORfff(rnd * rndAbs * g_2c1ec8, 1.0f, 0.0f);
    asm volatile("qmtc2.ni %1, vf4\n\tlqc2 vf3, %2\n\tlqc2 vf2, %3\n\tlqc2 vf1, %4\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z" : "=j" (v4) : "r" (offset2d), "m" (f.lift), "m" (f.right), "m" (f.tangent));
    QW offsetBits;
    asm volatile("qmfc2.ni %0, vf4" : "=r" (offsetBits));
    asm volatile("sqc2 vf4, %0" : "=m" (f.offset) : "j" (v4));
    f.q50 = offsetBits;
    if (pposOut != 0) {
        f.q70 = f.pos;
        float along = GRandInRange(0.0f, g_2c1ecc);
        float scale = rndAbs * along;
        QW scaleBits;
        asm volatile("lqc2 vf3, %2\n\tlqc2 vf4, %3\n\tmfc1 %1, %5\n\tqmtc2.ni %1, vf1\n\tvadda.xyzw ACC, vf0, vf3\n\tvmaddx.xyzw vf2, vf4, vf1x\n\tsqc2 vf1, %0\n\tsqc2 vf2, %4" : "=m" (f.q40), "=&r" (scaleBits) : "m" (f.q70), "m" (f.q50), "m" (*pposOut), "f" (scale) : "memory");
    }
    if (pvecOut != 0)
        *pvecOut = f.offset;
}
