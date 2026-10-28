#include "sly2.h"
struct JOY { char pad[0x18]; float rad; float mag; };
struct M0 { char pad[0x150]; JOY *pjoy; };
struct M1 { char pad[0x190]; QW vGoal; };
struct M2 { char pad[0x1030]; int pasega; };
struct M3 { char pad[0x131C]; char vecStuck[4]; };
struct M4 { char pad[0x13D8]; int flops; float tStuck; char pad2[4]; int fContacts; };
struct MURRAY { union { M0 a; M1 b; M2 c; M3 d; M4 e; } u; };
extern "C" int FAsegaGone(int);
extern "C" int FJtStuck(MURRAY *, void *, float);
extern "C" void SetMurrayState(MURRAY *, int);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern "C" void WarpJtToSafePoint(MURRAY *, int);
extern "C" void func_001B6DA8(MURRAY *, int);
extern "C" float D_002BF730;
extern "C" float D_002C09A0;
extern "C" void func_001B6BA8(MURRAY *pmurray)
{
    int flops;
    for (;;) {
        int flopsStart = pmurray->u.e.flops;
        if (pmurray->u.c.pasega == 0 || FAsegaGone(pmurray->u.c.pasega)) {
            SetMurrayState(pmurray, 0);
        } else if (pmurray->u.e.flops == 1) {
            if (pmurray->u.e.fContacts != 0) {
                func_001B6DA8(pmurray, 2);
            } else if (FJtStuck(pmurray, pmurray->u.d.vecStuck, pmurray->u.e.tStuck)) {
                WarpJtToSafePoint(pmurray, 0);
            }
        }
        flops = pmurray->u.e.flops;
        if (flops == flopsStart || flops == -1)
            break;
    }
    if (flops < 2) {
        if (flops >= 0) {
            JOY *pjoy = pmurray->u.a.pjoy;
            pmurray->u.b.vGoal = SetVectorCylind__FP6VECTORfff(pjoy->rad + 3.1415927f, D_002C09A0 * D_002BF730 * pjoy->mag, 0.0f);
        }
    }
}
