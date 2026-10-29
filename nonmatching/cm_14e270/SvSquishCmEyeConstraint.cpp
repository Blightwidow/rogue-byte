#include "sly2.h"
struct SMP;
struct Cm { char pad[0x48]; float radius; };
struct Sbi { QW contact; QW normal; };
extern "C" {
extern const float D_FLT_002BD8D8;
extern float B_FLT_002DDEE0;
extern SMP D_002BD8E0;
void *func_002564B8(void *);
float GSmooth__FfffP3SMPPf(float g, float gGoal, float dt, SMP *psmp, float *psv);
float SvSquishCmEyeConstraint(Cm *pcm, QW posEyePrev, QW vEye, Sbi *psbi)
{
    struct { QW a; QW b; float svSmooth; QW normal; QW contact; QW vEye; } l;
    l.vEye = vEye;
    l.normal = psbi->normal;
    func_002564B8(&l.a);
    l.contact = psbi->contact;
    func_002564B8(&l.b);
    float dist;
    asm("lqc2 vf3, %0" : : "m" (l.normal));
    asm("lqc2 vf4, %0" : : "m" (l.contact));
    asm("vmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w\n\tqmfc2.ni %0, vf2" : "=r" (dist));
    asm("sqc2 vf1, %0" : "=m" (l.b));
    asm("sqc2 vf2, %0" : "=m" (l.a));
    GSmooth__FfffP3SMPPf(dist, pcm->radius - D_FLT_002BD8D8, B_FLT_002DDEE0, &D_002BD8E0, &l.svSmooth);
    float dot;
    asm("lqc2 vf1, %1\n\tlqc2 vf3, %2\n\tvmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tqmfc2.ni %0, vf1" : "=r" (dot) : "m" (psbi->normal), "m" (l.vEye));
    return dot - l.svSmooth;
}
}
