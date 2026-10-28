#include "sly2.h"
struct CHILD { char pad[0x30]; int state; };
struct GOAL { char pad[0x10]; void *guard; int gap; CHILD *child; char pad2[0x30 - 0x1C]; int state; char pad3[4]; void *target; };
extern "C" void func_001EEF98(GOAL *);
extern "C" int func_001EF0A8(GOAL *);
extern "C" void func_00155788(GOAL *, int);
extern "C" QW PosLoWorld(void *);
extern "C" void GoalPostRun_Update(GOAL *goal)
{
    func_001EEF98(goal);
    int previous;
    while (!func_001EF0A8(goal)) {
        previous = goal->state;
        if (previous == 0) {
            CHILD *child = goal->child;
            QW posGuard = PosLoWorld(goal->guard);
            QW posTarget = PosLoWorld(goal->target);
            int result = 0;
            float length;
            asm volatile("lqc2 vf1, %1\n\tqmtc2.ni %2, vf3\n\tvsub.xyzw vf2, vf1, vf3\n\tvmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (length) : "m" (posGuard), "r" (posTarget));
            if (length < 850.0f) {
                float z;
                asm volatile("qmfc2.ni %0, vf2\n\tpextuw %0, $0, %0" : "=r" (z));
                if (__builtin_fabsf(z) < 400.0f) {
                    if (child->state) result = 1;
                }
            }
            if (result) func_00155788(goal, 1);
        }
        if (goal->state == previous) return;
    }
}
