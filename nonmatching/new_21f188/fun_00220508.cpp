#include "sly2.h"
struct CT { int pad0; int state; char pad1[0x20]; float speed; char pad2[0xB4]; QW from; QW to; QW pad3; QW goalTo; char pad4[0]; };
struct CT2 { char pad[0x120]; float start; float dt; int active; };
extern "C" QW PosLoWorld(void *);
extern float g_2dded0;

void func_00220508(CT *c, void *object)
{
    int s = c->state;
    if (s < 7) {
        if (s >= 4) {
            QW pos = PosLoWorld(object);
            asm("qmtc2.ni %0, vf2" : : "r" (pos));
            float speed = c->speed;
            asm("lqc2 vf3, 0xE0(%0)" : : "r" (c));
            int one = 1;
            asm("vsub.xyzw vf1, vf3, vf2");
            asm("sqc2 vf2, 0x110(%0)" : : "r" (c) : "memory");
            asm("vmul.xyz vf1, vf1, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf4, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
            asm("sqc2 vf3, 0x100(%0)" : : "r" (c) : "memory");
            QW len;
            asm("qmfc2.ni %0, vf1" : "=r" (len));
            float length;
            asm("mtc1 %1, %0" : "=f" (length) : "r" (len));
            float result = length / speed;
            CT2 *d = (CT2 *)c;
            d->active = one;
            d->start = g_2dded0;
            d->dt = result;
        }
    }
}
