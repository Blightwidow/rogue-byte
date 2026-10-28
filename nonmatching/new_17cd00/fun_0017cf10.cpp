#include "sly2.h"
struct JT;
struct PIPE;
struct SMP { float a; float b; float c; };
struct GUARD { char pad0[0x198]; float speed; char pad1[0xF84 - 0x19C]; PIPE *pcrv; float sPath; int fForward; };
struct GOAL { char pad0[0x10]; GUARD *pguard; char pad1[0x30 - 0x14]; int state; char pad2[0x38 - 0x34]; float sTarget; float speed; };
extern "C" {
void func_001EEF98();
int func_0017D188(GOAL *);
void func_0017D058(GOAL *, int);
float SWrapCrv(PIPE *, float);
}
float GSmooth__FfffP3SMPPf(float, float, float, SMP *, float *);
void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(JT *, PIPE *, float, MATRIX3 *);
extern float g_2dded0[2];
extern float g_2dfb7c;
extern float D_002DFB7C;
extern "C" void func_0017CF10(GOAL *pgoal)
{
    func_001EEF98();
    int previous;
    do {
        previous = pgoal->state;
        if (previous == 0) {
            if (func_0017D188(pgoal) != 0) {
                func_0017D058(pgoal, 1);
            } else {
                GUARD *pguard = pgoal->pguard;
                pguard->fForward = pguard->sPath < pgoal->sTarget;
                pguard = pgoal->pguard;
                float gSpeed = pguard->speed;
                g_2dfb7c = pguard->fForward == 0 ? gSpeed : -gSpeed;
                SMP smp;
                asm volatile("" : : : "memory");
                float target = D_002DFB7C;
                smp.a = __builtin_fabsf(target);
                smp.b = 0.0f;
                smp.c = 0.1f;
                float speedNow = GSmooth__FfffP3SMPPf(pgoal->speed, target, g_2dded0[1], &smp, 0);
                pgoal->speed = speedNow;
                pguard = pgoal->pguard;
                float sNew = SWrapCrv(pguard->pcrv, pguard->sPath + speedNow * g_2dded0[1]);
                pgoal->pguard->sPath = sNew;
            }
        }
    } while (previous != pgoal->state);
    GUARD *pguardEnd = pgoal->pguard;
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3((JT *)pguardEnd->pcrv, (PIPE *)pguardEnd->fForward, pguardEnd->sPath, (MATRIX3 *)((char *)pguardEnd + 0x1B0));
}
