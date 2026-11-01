// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
extern "C" {
void ClosestPointOnSegment(QW, QW, QW, void *, float *, float *);
extern const float g_2a2dc0[];
}
struct TRI1BFDB0 { QW *pposA; QW *pposB; QW *pposC; };
struct OUT1BFDB0 { QW closest; QW second; };
static inline float TopZ(void)
{
    float z;
    int tmp;
    asm volatile("qmfc2.ni %1, vf1\n\tpextuw %1, $0, %1\n\tmtc1 %1, %0" : "=f"(z), "=&r"(tmp));
    return z;
}
static inline QW Get(void) { QW r; asm volatile("qmfc2.ni %0, vf4" : "=r"(r)); return r; }
#define GETVF(var, vf) asm volatile("qmfc2.ni %0, " #vf : "=r"(var))
extern "C" QW PosClosestOnCgt(TRI1BFDB0 *tri, QW pos)
{
    OUT1BFDB0 out;
    QW a, b, c;
    asm volatile("qmtc2.ni %0, vf4" : : "r"(pos));
    asm volatile("lqc2 vf6, 0(%0)" : : "r"(tri->pposA));
    asm volatile("lqc2 vf5, 0(%0)" : : "r"(tri->pposB));
    asm volatile("vsub.xyzw vf1, vf4, vf6");
    asm volatile("vsub.xyzw vf9, vf5, vf6");
    asm volatile("vopmula.xyz ACC, vf1, vf9");
    asm volatile("vopmsub.xyz vf1, vf9, vf1");
    asm volatile("vmove.xyzw vf8, vf6");
    asm volatile("lqc2 vf3, 0(%0)" : : "r"(tri->pposC));
    asm volatile("vmove.xyzw vf7, vf3");
    if (0.0f < TopZ()) {
        GETVF(a, vf4); GETVF(b, vf6); GETVF(c, vf5);
        ClosestPointOnSegment(a, b, c, &out, 0, 0);
        return out.closest;
    }
    asm volatile("vsub.xyzw vf1, vf4, vf5");
    asm volatile("vsub.xyzw vf2, vf3, vf5");
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    if (0.0f < TopZ()) {
        GETVF(a, vf4); GETVF(b, vf5); GETVF(c, vf3);
        ClosestPointOnSegment(a, b, c, &out, 0, 0);
        return out.closest;
    }
    asm volatile("vsub.xyzw vf1, vf4, vf3");
    asm volatile("vsub.xyzw vf2, vf6, vf3");
    asm volatile("vopmula.xyz ACC, vf1, vf2");
    asm volatile("vopmsub.xyz vf1, vf2, vf1");
    if (0.0f < TopZ()) {
        GETVF(a, vf4); GETVF(b, vf3); GETVF(c, vf6);
        ClosestPointOnSegment(a, b, c, &out, 0, 0);
        return out.closest;
    }
    asm volatile("vsub.xyzw vf1, vf7, vf8");
    asm volatile("vsub.xyzw vf2, vf8, vf4");
    asm volatile("vopmula.xyz ACC, vf9, vf1");
    asm volatile("vopmsub.xyz vf1, vf1, vf9");
    {
    float denominator = TopZ();
    asm volatile("vmul.xyz vf2, vf2, vf1");
    asm volatile("vaddw.x vf3, vf0, vf0w");
    asm volatile("vadday.x ACC, vf2, vf2y");
    asm volatile("vmaddz.x vf2, vf3, vf2z");
    asm volatile("lqc2 vf1, 0(%0)" : : "r"(g_2a2dc0));
    float numerator;
    asm volatile("qmfc2.ni $2, vf2\n\tmtc1 $2, %0" : "=f"(numerator) : : "$2");
    float ratio = numerator / denominator;
    asm volatile("qmtc2.ni %0, vf2" : : "r"(ratio));
    asm volatile("vadda.xyzw ACC, vf0, vf4");
    asm volatile("vmaddx.xyzw vf1, vf1, vf2x");
    asm volatile("sqc2 vf2, 0x10(%0)" : : "r"(&out.second));
    asm volatile("sqc2 vf1, 0(%0)" : : "r"(&out.closest));
    return out.closest;
    }
}
