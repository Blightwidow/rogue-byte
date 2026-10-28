#include "sly2.h"
struct SMP { float a, b, c, d; };
struct STEP { char pad0[0x5C]; char *pxf; char pad1[0x1A4 - 0x60]; int mode; };
extern float g_2dded4;
extern "C" void AddSoGravityAcceleration(STEP *);
extern "C" void AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(STEP *, float, MATRIX3 *, SMP *);
void PresetStepAccel(STEP *pstep)
{
    SMP smp;
    register float dt asm("$f12");
    QW spare __attribute__((aligned(16)));
    AddSoGravityAcceleration(pstep);
    int mode = pstep->mode;
    switch (mode) {
    case 0: {
        float rSpin = *(float *)((char *)pstep + 0x200);
        smp.a = *(float *)((char *)pstep + 0x1F4) * rSpin;
        smp.b = *(float *)((char *)pstep + 0x1F8) * rSpin;
        smp.c = *(float *)((char *)pstep + 0x1FC);
        AccelSoTowardMatSmooth__FP2SOfP7MATRIX3P3SMP(pstep, dt, (MATRIX3 *)((char *)pstep + 0x1B0), &smp);
        break; }
    case 1: {
            char *pxf = pstep->pxf;
            int rate = *(int *)&g_2dded4;
            asm("lqc2 vf3, %0" : : "m" (*(QW *)((char *)pstep + 0x1E0)));
            asm("lqc2 vf1, %0" : : "m" (*(QW *)(pxf + 0xB0)));
            asm("qmtc2.ni %0, vf4" : : "r" (rate));
            asm("vsub.xyzw vf3, vf3, vf1");
            asm("lqc2 vf2, %0" : : "m" (*(QW *)(pxf + 0xF0)));
            asm("vdiv Q, vf0w, vf4x\n\tvwaitq\n\tvmulq.xyzw vf3, vf3, Q");
            asm("sqc2 vf4, %0" : "=m" (spare));
            asm("vadd.xyzw vf2, vf2, vf3");
            asm("sqc2 vf2, %0" : "=m" (*(QW *)(pxf + 0xF0)));
        break; }
    case -1: break;
    }
}
