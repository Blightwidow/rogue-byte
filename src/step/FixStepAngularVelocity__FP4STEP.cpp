#include "sly2.h"
struct SMP { float a, b, c; };
struct VTS { char pad0[0xF8]; short d0; short i0; float *(*fn0)(void *); char pad1[0x20]; short d1; short i1; void (*fn1)(void *, QW); };
struct VEC { float x,y,z,w; } __attribute__((aligned(16)));
struct XFS { char pad[0xB0]; VEC w; };
struct STEP { char pad0[0xC]; VTS *vptr; char pad1[0x4C]; XFS *pxf; char pad2[0x148]; float radTarget; char pad3[0x48]; SMP smp; };
extern "C" float atan2f(float, float);
float RadSmooth(float, float, float, SMP *, float *);
void FixStepAngularVelocity(STEP *pstep)
{
    VEC w = pstep->pxf->w;
    float *pmat = pstep->vptr->fn0((char *)pstep + pstep->vptr->d0);
    float *pmat2 = pstep->vptr->fn0((char *)pstep + pstep->vptr->d0);
    float radCur = atan2f(pmat[1], pmat2[0]);
    RadSmooth(radCur, pstep->radTarget, 0.0f, &pstep->smp, &w.z);
    pstep->vptr->fn1((char *)pstep + pstep->vptr->d1, *(QW *)&w);
}
