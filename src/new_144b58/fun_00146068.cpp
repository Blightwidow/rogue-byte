#include "sly2.h"
struct Vjoy { char p0[0x18]; float radLeft; float sLeft; char p1[0x30 - 0x20]; unsigned grfbtn; };
struct Goal { char p0[0x10]; void *powner; char p1[0x30 - 0x14]; int state; float tState; void *ptarget; };
extern "C" {
void Goal_FillVjoy(Goal *, Vjoy *);
QW PosLoWorld(void *);
float atan2f(float, float);
void UpdateVjoyPressTimes(Vjoy *);
extern float g_2dded0;
}
void func_00146068(Goal *pgoal, Vjoy *pvjoy)
{
    Goal_FillVjoy(pgoal, pvjoy);
    int state = pgoal->state;
    if (state < 3) {
        if (state >= 0) {
            QW target = PosLoWorld(pgoal->ptarget);
            QW owner = PosLoWorld(pgoal->powner);
            QW diff;
            asm("qmtc2.ni %0, vf2" : : "r" (owner));
            float speed = 1.0f;
            asm("lqc2 vf1, %0\n\tvsub.xyzw vf1, vf1, vf2" : : "m" (target));
            asm("qmfc2.ni %0, vf1" : "=r" (diff));
            if (pgoal->state == 0)
                speed = 0.1f;
            float x, y;
            asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f" (x), "=f" (y) : "r" (diff) : "$2");
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
