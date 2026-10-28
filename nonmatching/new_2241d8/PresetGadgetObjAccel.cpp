/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct SO { char pad[0x150]; int state; int pad154; int pad158; int kind; };
struct SOSTATE { char pad[0x150]; int state; char pad2[0x15C - 0x154]; int kind; };
struct MAT48 { float mat[12]; } __attribute__((aligned(16)));
struct CLQ { char pad[0x10]; };
extern "C" {
extern QW g_2a2dc0;
extern QW g_2a2da0;
extern QW g_2a2dd0;
extern char D_002C4300[];
extern char D_002C4310[];
void AddSoGravityAcceleration(void *);
QW PosLoWorld(void *);
void *PmatLoWorld(void *);
void TiltMatUpright__FP7MATRIX3N20(void *, void *, void *);
MAT48 BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(QW, QW);
void AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(void *, void *, void *, QW, void *, float);
}

extern "C" void PresetGadgetObjAccel(void *pgadget)
{
    SOSTATE *pso = (SOSTATE *)pgadget;
    if (pso->state == 0 || pso->state == 4)
        return;
    AddSoGravityAcceleration(pgadget);
    if (pso->kind != 0x1a && pso->kind != 0x29)
        return;
    MAT48 matGoal;
    void *ploTarget = *(void **)((char *)pgadget + 0x160);
    if (ploTarget != 0) {
        QW posTarget = PosLoWorld(ploTarget);
        QW posTargetSpill;
        asm("qmtc2.ni %0, vf3" : : "r"(posTarget));
        QW posSelf = PosLoWorld(pgadget);
        asm("sqc2 vf3, %0" : "=m"(posTargetSpill));
        asm("qmtc2.ni %0, vf1" : : "r"(posSelf));
        asm("lqc2 vf3, %0" : : "m"(posTargetSpill));
        asm("vsub.xyzw vf3, vf3, vf1");
        QW *pvecUp = &g_2a2dc0;
        asm("lqc2 vf1, 0x0(%0)" : : "r"(pvecUp));
        asm("vmul.xyz vf2, vf3, vf1");
        asm("vaddw.x vf4, vf0, vf0w");
        asm("vadday.x ACC, vf2, vf2y");
        asm("vmaddz.x vf2, vf4, vf2z");
        asm("vmulx.xyzw vf2, vf1, vf2x");
        QW vecAxisX = g_2a2da0;
        asm("vsub.xyzw vf3, vf3, vf2");
        float sEpsilon = 0.0001f;
        float sFlat;
        asm("vmul.xyz vf1, vf3, vf3");
        asm("vaddw.x vf2, vf0, vf0w");
        asm("vadday.x ACC, vf1, vf1y");
        asm("vmaddz.x vf1, vf2, vf1z");
        asm("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f"(sFlat));
        QW vecDir;
        if (sFlat < sEpsilon) {
            vecDir = vecAxisX;
        } else {
            asm("vdiv Q, vf0w, vf1x");
            asm("vwaitq");
            asm("vmulq.xyzw vf1, vf3, Q");
            asm("qmfc2.ni %0, vf1" : "=r"(vecDir));
        }
        MAT48 matTemp = BuildOrthonormalMatrixY__FP6VECTORT0P7MATRIX3(vecDir, *pvecUp);
        matGoal = matTemp;
    } else {
        TiltMatUpright__FP7MATRIX3N20(PmatLoWorld(pgadget), 0, &matGoal);
    }
    register float sUnused asm("$f12");
    AccelSoTowardMatSpring__FP2SOP7MATRIX3P3CLQP6VECTORT2f(pgadget, &matGoal, D_002C4300, g_2a2dd0, D_002C4310, sUnused);
}
