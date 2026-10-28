// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct GUARD { char pad[0x190]; QW vel; };
struct GOAL { char pad[0x10]; GUARD *guard; char pad2[0x1C]; int state; char pad3[4]; void *aim; char pad4[4]; void *anim; };
extern QW g_2a2dd0;
extern "C" {
void func_001EEFB8(GOAL *);
void func_00209618(void *, GUARD *);
QW PosLoWorld(void *);
void func_00209818(void *, float);
float atan2f(float, float);
}
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
void func_00174F08(GOAL *goal)
{
    func_001EEFB8(goal);
    if (goal->state == 0)
        func_00209618(goal->anim, goal->guard);
    else
        goal->guard->vel = g_2a2dd0;
    if (goal->aim) {
        QW posAim = PosLoWorld(goal->aim);
        QW posGuard = PosLoWorld(goal->guard);
        QW diff, rotated;
        asm volatile("qmtc2.ni %0, vf2" : : "r" (posGuard));
        GUARD *guard = goal->guard;
        asm volatile("lqc2 vf1, %0" : : "m" (posAim));
        asm volatile("vsub.xyzw vf1, vf1, vf2");
        char *motion = (char *)guard + 0xFD0;
        asm volatile("qmfc2.ni %0, vf1" : "=r" (diff));
        asm volatile("prot3w %0, %1" : "=r" (rotated) : "r" (diff));
        float x, y;
        asm volatile("mtc1 %1, %0" : "=f" (x) : "r" (diff));
        asm volatile("mtc1 %1, %0" : "=f" (y) : "r" (rotated));
        func_00209818(motion, atan2f(y, x));
    }
}
