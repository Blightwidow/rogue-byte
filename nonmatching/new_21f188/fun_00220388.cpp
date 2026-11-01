#include "sly2.h"
struct CARRY { char pad0[4]; int state; };
extern float g_2c4108;
extern int g_2c410c;
extern char g_2ddfa0[];
extern QW g_2a2dd0;
static inline int FloatBits(float value) { int bits; asm("mfc1 %0, %1" : "=r"(bits) : "f"(value)); return bits; }
extern "C" void CarryThrow_AdjustCameraGoal(CARRY *pcarry, char *pcam)
{
    char sp[0x20] __attribute__((aligned(16)));
    float back = g_2c4108;
    char *axis = g_2ddfa0;
    asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(pcam));
    asm volatile("qmtc2.ni %0, vf3" : : "r"(FloatBits(back)));
    asm volatile("lqc2 vf1, 0x10(%0)" : : "r"(axis));
    asm volatile("sqc2 vf3, (%0)" : : "r"(sp));
    asm volatile("vadda.xyzw ACC, vf0, vf2");
    asm volatile("vmaddx.xyzw vf5, vf1, vf3x");
    asm volatile("sqc2 vf5, 0x10(%0)" : : "r"(pcam));
    int state = pcarry->state;
    if (state < 7) {
        if (state >= 4) {
            QW *dst = (QW *)(pcam + 0x20);
            float nback = -back;
            asm volatile("lqc2 vf2, 0x10(%0)" : : "r"(axis));
            asm volatile("qmtc2.ni %0, vf3" : : "r"(FloatBits(-1.0f)));
            asm volatile("lqc2 vf1, 0xE0(%0)" : : "r"(pcarry));
            asm volatile("qmtc2.ni %0, vf4" : : "r"(FloatBits(nback)));
            asm volatile("sqc2 vf3, 0x10(%0)" : : "r"(sp));
            asm volatile("vadda.xyzw ACC, vf0, vf1");
            asm volatile("vmaddax.xyzw ACC, vf5, vf3x");
            asm volatile("vmaddx.xyzw vf1, vf2, vf4x");
            asm volatile("sqc2 vf1, (%0)" : : "r"(sp));
            ((int *)sp)[2] = 0;
            int reach = g_2c410c;
            float eps = 0.0001f;
            asm volatile("lqc2 vf3, (%0)" : : "r"(sp));
            asm volatile("qmtc2.ni %0, vf6" : : "r"(reach));
            asm volatile("vmul.xyz vf1, vf3, vf3");
            asm volatile("vaddw.x vf2, vf0, vf0w");
            asm volatile("vadday.x ACC, vf1, vf1y");
            asm volatile("vmaddz.x vf1, vf2, vf1z");
            asm volatile("vsqrt Q, vf1x");
            asm volatile("vwaitq");
            asm volatile("vaddq.x vf1, vf0, Q");
            int lenbits;
            asm volatile("qmfc2.ni %0, vf1" : "=r"(lenbits));
            float len;
            asm volatile("mtc1 %1, %0" : "=f"(len) : "r"(lenbits));
            QW dirq = g_2a2dd0;
            asm volatile("sqc2 vf4, 0x10(%0)" : : "r"(sp));
            asm volatile("sqc2 vf6, 0x10(%0)" : : "r"(sp));
            if (len < eps) {
                asm volatile("qmtc2.ni %0, vf1" : : "r"(dirq));
            } else {
                asm volatile("nop");
                asm volatile("nop");
                asm volatile("vdiv Q, vf0w, vf1x");
                asm volatile("vwaitq");
                asm volatile("vmulq.xyzw vf1, vf3, Q");
            }
            asm volatile("vmulx.xyzw vf1, vf1, vf6x");
            asm volatile("sqc2 vf1, (%0)" : : "r"(dst));
        }
    }
}
