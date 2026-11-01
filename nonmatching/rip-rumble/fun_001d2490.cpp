// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct OBJ1D2490 { char pad0[0x51C]; float speed; char pad1[0x544 - 0x520]; float heading; char pad2[0x550 - 0x548]; float turn; char pad3[0x5AC - 0x554]; void *crv; float s; };
extern "C" {
QW PosLoWorld(OBJ1D2490 *);
void FindCrvClosestPointFromS(void *, QW, int, QW *, QW *, int, float *, float);
float atan2f(float, float);
extern const float g_2c20d0[];
extern const float g_2c20e0[];
void func_001D2490(OBJ1D2490 *obj)
{
    struct { QW closest; QW tangent; QW scale; QW pos; } stack;
    QW pos = PosLoWorld(obj);
    stack.pos = pos;
    FindCrvClosestPointFromS(obj->crv, pos, 0, &stack.closest, &stack.tangent, 0, &obj->s, obj->s);
    const float *coefficients = g_2c20d0;
    float distance;
    asm volatile("lqc2 vf1, 0(%0)" : : "r"(&stack.closest));
    asm volatile("lqc2 vf2, 0x30(%0)" : : "r"(&stack.closest));
    asm volatile("vsub.xyzw vf1, vf2, vf1");
    asm volatile("vmul.xy vf1, vf1, vf1");
    asm volatile("vaddy.x vf1, vf1, vf1y");
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f"(distance) : : "$2");
    float t = coefficients[0] + distance * (coefficients[1] + distance * coefficients[2]);
    if (t < g_2c20e0[0])
        t = g_2c20e0[0];
    else if (g_2c20e0[1] < t)
        t = g_2c20e0[1];
    asm volatile("qmtc2.ni %0, vf2" : : "r"(t));
    asm volatile("lqc2 vf1, 0(%0)" : : "r"(&stack.closest));
    asm volatile("lqc2 vf5, 0x10(%0)" : : "r"(&stack.closest));
    asm volatile("vadda.xyzw ACC, vf1, vf0");
    asm volatile("vmaddx.xyzw vf1, vf5, vf2x");
    asm volatile("lqc2 vf3, 0x30(%0)" : : "r"(&stack.closest));
    asm volatile("vsub.xyzw vf4, vf1, vf3");
    asm volatile("vmul.xyz vf1, vf4, vf4");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf3, vf1z");
    asm volatile("sqc2 vf2, 0x20(%0)" : : "r"(&stack.closest));
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    QW direction;
    float length;
    asm volatile("qmfc2.ni %0, vf5" : "=r"(direction));
    asm volatile("qmfc2.ni $2, vf1\n\tmtc1 $2, %0" : "=f"(length) : : "$2");
    if (length < 0.0001f) {
    } else {
        asm volatile("vdiv Q, vf0w, vf1x");
        asm volatile("vwaitq");
        asm volatile("vmulq.xyzw vf2, vf4, Q");
        asm volatile("qmfc2.ni %0, vf2" : "=r"(direction));
    }
    float x, y;
    asm("prot3w $2, %2\n\tmtc1 %2, %0\n\tmtc1 $2, %1" : "=f"(x), "=f"(y) : "r"(direction) : "$2");
    obj->heading = atan2f(y, x);
    obj->turn = obj->speed * 0.75f;
}
}
