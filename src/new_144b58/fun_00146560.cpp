/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
#include "ps2inline.h"
#include "vu0inline.h"

struct Vjoy { char p0[0x18]; float radLeft; float sLeft; char p1[0x30 - 0x20]; unsigned grfbtn; };
struct Goal { char p0[0x10]; void *powner; char p1[0x30 - 0x14]; int state; float tState; void *ptarget; };
extern "C" {
void Goal_FillVjoy(Goal *, Vjoy *);
QW PosLoWorld(void *);
float atan2f(float, float);
void UpdateVjoyPressTimes(Vjoy *);
extern float g_2dded0;
}

extern "C" void func_00146560(Goal *pgoal, Vjoy *pvjoy)
{
    Goal_FillVjoy(pgoal, pvjoy);
    int state = pgoal->state;
    if (state < 3) {
        if (state >= 0) {
            QW target = PosLoWorld(pgoal->ptarget);
            QW owner = PosLoWorld(pgoal->powner);
            QW diff = VectorSub(target, owner);
            float speed = 1.0f;
            if (pgoal->state == 0)
                speed = 0.1f;
            float x = LaneX(diff);
            float y = LaneX(RotateWords3(diff));
            pvjoy->sLeft = speed;
            pvjoy->radLeft = atan2f(y, x);
            if (pgoal->state == 2) {
                if (g_2dded0 - pgoal->tState < 0.1f) {
                    pvjoy->grfbtn |= 0x80;
                    UpdateVjoyPressTimes(pvjoy);
                }
            }
        }
    }
}
