#include "sly2.h"
struct SO { char pad0[0x1A8]; float radHeading; char pad1[0x1840 - 0x1AC]; int nSubState; };
struct GOAL { char pad0[0x10]; SO *powner; char pad1[0x30 - 0x14]; float radStart; };
extern "C" {
void func_001EEF98(GOAL *);
QW PosLoWorld(void *);
void SetStepRadTargetDir(void *, QW);
void SetStepRadTarget(void *, float);
float atan2f(float, float);
float RadNormalize__Ff(float);
float RadYawSo(void *);
float GLimitAbs__Fff(float, float);
float fabsf(float);
extern void *g_2e1e40;
extern float g_2dded4;
extern const float D_FLT_002BD374;
extern const float D_FLT_002BD378;
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }

extern "C" void GoalMurrayAi_Update(GOAL *pgoal)
{
    func_001EEF98(pgoal);
    int nSubState = pgoal->powner->nSubState;
    switch (nSubState) {
    case 0:
    {
        if (g_2e1e40 != 0) {
            QW posSly = PosLoWorld(g_2e1e40);
            QW posOwner = PosLoWorld(pgoal->powner);
            QW diff;
            asm("lqc2 vf1, %0" : : "m" (posSly));
            asm("qmtc2.ni %0, vf2" : : "r" (posOwner));
            SO *powner = pgoal->powner;
            asm("vsub.xyzw vf1, vf1, vf2" : : "r" (powner));
            asm("qmfc2.ni %0, vf1" : "=r" (diff));
            SetStepRadTargetDir(powner, diff);
        }
        pgoal->radStart = pgoal->powner->radHeading;
        break;
    }
    case 1:
    {
        if (g_2e1e40 != 0) {
            QW posSly = PosLoWorld(g_2e1e40);
            QW posOwner = PosLoWorld(pgoal->powner);
            QW diff;
            asm("qmtc2.ni %0, vf2" : : "r" (posOwner));
            asm("lqc2 vf1, %0" : : "m" (posSly));
            asm("vsub.xyzw vf1, vf1, vf2");
            asm("qmfc2.ni %0, vf1" : "=r" (diff));
            float radToSly = atan2f(Lane(__builtin_prot3w(diff)), Lane(diff));
            float radOff = RadNormalize__Ff(radToSly - pgoal->radStart);
            if (fabsf(radOff) < D_FLT_002BD374) {
                float radYaw = RadYawSo(pgoal->powner);
                float radNorm = RadNormalize__Ff(radToSly - radYaw);
                float d = g_2dded4;
                float c = D_FLT_002BD378;
                float radDelta = GLimitAbs__Fff(radNorm, c * d);
                SetStepRadTarget(pgoal->powner, radYaw + radDelta);
            }
        }
        break;
    }
    }
}
