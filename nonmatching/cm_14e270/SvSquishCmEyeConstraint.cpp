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
    l.contact = psbi->contact;
    func_002564B8(&l.a);
    func_002564B8(&l.b);
    float radius = pcm->radius;
    float offset = D_FLT_002BD8D8;
    float dist;
    asm("lqc2 vf3, %0" : : "m" (l.normal));
    asm("lqc2 vf4, %0" : : "m" (l.contact));
    float goal = radius - offset;
    asm("vmul.xyz vf2, vf3, vf4\n\tvaddw.x vf1, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddaz.x ACC, vf1, vf2z\n\tvmsubw.x vf2, vf1, vf3w");
    float dt = B_FLT_002DDEE0;
    asm("qmfc2.ni %0, vf2" : "=r" (dist));
    asm("sqc2 vf1, %0" : "=m" (l.b));
    asm("sqc2 vf2, %0" : "=m" (l.a));
    GSmooth__FfffP3SMPPf(dist, goal, dt, &D_002BD8E0, &l.svSmooth);
    float dot;
    asm("lqc2 vf1, %0\n\tlqc2 vf3, %1\n\tvmul.xyz vf1, vf3, vf1\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : : "m" (psbi->normal), "m" (l.vEye));
    float sv = l.svSmooth;
    asm("qmfc2.ni %0, vf1" : "=r" (dot));
    return dot - sv;
}
}
