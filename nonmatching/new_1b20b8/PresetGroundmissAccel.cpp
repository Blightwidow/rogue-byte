#include "sly2.h"
struct SMP { float a, b, c; };
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct PHYS { char pad[0xB0]; };
struct GM { char pad0[0xC]; VT *vt; char pad1[0x58 - 0x10]; void *pxf; char pad2[0xE8 - 0x5C]; PHYS *pphys; char pad3[0x1E8 - 0xEC]; int stuck; char pad4[0x270 - 0x1EC]; float svTrack; float sdvTrackMax; };
struct TIMEG { float t; float dt; };
extern "C" TIMEG g_2dded0;
extern "C" float GSmooth__FfffP3SMPPf(float g, float gGoal, float dt, SMP *psmp, float *psv);
extern "C" QW ApplyConstrLocal(void *, void *, QW);
extern "C" void AddSoAcceleration(GM *, QW);
extern "C" void PresetGroundmissAccel(GM *pgm)
{
    struct { SMP smpArg; int pad0; SMP smp; int pad1; QW spill; QW vel; QW heading; } l;
    if (pgm->stuck == 0) {
        VT *vt = pgm->vt;
        l.vel = vt->fn((char *)pgm + vt->delta);
        int lenBits;
        asm("qmtc2.ni %0, vf3" : : "r" (l.vel));
        asm("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
        register int n12 asm("$6") = 12;
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : : "r" (n12));
        register void *psmp asm("$4") = &l.smp;
        asm("qmfc2.ni %0, vf1" : "=r" (lenBits) : "r" (psmp));
        register int zero asm("$5") = 0;
        asm volatile("qmtc2.ni %0, vf2" : : "r" (lenBits), "r" (zero));
        asm("vdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf4, vf3, Q");
        asm("sqc2 vf2, %0" : "=m" (l.smpArg));
        asm("sqc2 vf4, %0" : "=m" (l.heading));
        memset(psmp, zero, n12);
        float len;
        asm volatile("mtc1 %1, %0" : "=f" (len) : "r" (lenBits));
        l.smp.a = pgm->sdvTrackMax;
        l.smp.c = 1.0f;
        l.smpArg = l.smp;
        TIMEG *pg = &g_2dded0;
        float sNew = GSmooth__FfffP3SMPPf(len, pgm->svTrack, pg->dt, &l.smpArg, 0);
        asm("qmtc2.ni %0, vf2" : : "r" (sNew));
        asm("lqc2 vf1, %0" : : "m" (l.heading));
        int dtBits = *(int *)&pg->dt;
        asm("vmulx.xyzw vf3, vf1, vf2x");
        asm("lqc2 vf4, %0" : : "m" (l.vel));
        asm("qmtc2.ni %0, vf1" : : "r" (dtBits));
        asm("vsub.xyzw vf3, vf3, vf4");
        asm("vdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf4, vf3, Q");
        QW accel;
        asm("qmfc2.ni %0, vf4" : "=r" (accel));
        asm("sqc2 vf2, %0" : "=m" (l.spill));
        asm("sqc2 vf1, %0" : "=m" (l.smp));
        QW result = ApplyConstrLocal((char *)pgm->pphys + 0xB0, pgm->pxf, accel);
        AddSoAcceleration(pgm, result);
    }
}
