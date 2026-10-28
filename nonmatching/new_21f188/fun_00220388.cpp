#include "sly2.h"
struct CARRY { char pad0[4]; int state; };
struct LOC { QW a; QW b; };
extern float g_2c4108, g_2c410c;
extern char g_2ddfa0[];
extern QW g_2a2dd0;
extern "C" void CarryThrow_AdjustCameraGoal(CARRY *pcarry, char *pcam)
{
    LOC l;
    float back = g_2c4108;
    char *axis = g_2ddfa0;
    int t0, t1, t2, t3, t4, t5, t6;
    int bits;
    asm volatile("lqc2 vf2, 0x10(%1)" : "=r" (t0) : "r" (pcam));
    asm volatile("mfc1 %0, %1" : "=r" (bits) : "f" (back), "r" (t0));
    asm volatile("qmtc2.ni %1, vf3" : "=r" (t1) : "r" (bits));
    asm volatile("lqc2 vf1, 0x10(%1)" : "=r" (t2) : "r" (axis), "r" (t1));
    asm volatile("sqc2 vf3, %1" : "=r" (t3), "=m" (l.a) : "r" (t2));
    asm volatile("vadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf5, vf1, vf3x" : "=r" (t4) : "r" (t3));
    asm volatile("sqc2 vf5, 0x10(%1)" : "=r" (t5) : "r" (pcam), "r" (t4) : "memory");
    int state = pcarry->state;
    if (state < 7) {
        if (state >= 4) {
            QW *dst = (QW *)(pcam + 0x20);
            float nback = -back;
            int nbits, gbits;
            QW zero;
            asm volatile("lqc2 vf2, 0x10(%1)" : "=r" (t0) : "r" (axis), "r" (t5));
            asm volatile("mfc1 %0, %1" : "=r" (gbits) : "f" (-1.0f), "r" (t0));
            asm volatile("qmtc2.ni %1, vf3" : "=r" (t1) : "r" (gbits));
            asm volatile("lqc2 vf1, 0xE0(%1)" : "=r" (t2) : "r" (pcarry), "r" (t1));
            asm volatile("mfc1 %0, %1" : "=r" (nbits) : "f" (nback), "r" (t2));
            asm volatile("qmtc2.ni %1, vf4" : "=r" (t3) : "r" (nbits));
            asm volatile("sqc2 vf3, %1" : "=r" (t4), "=m" (l.b) : "r" (t3));
            asm volatile("vadda.xyzw ACC, vf0, vf1\n\tvmaddax.xyzw ACC, vf5, vf3x\n\tvmaddx.xyzw vf1, vf2, vf4x" : "=r" (t5) : "r" (t4));
            asm volatile("sqc2 vf1, %1" : "=r" (t6), "=m" (l.a) : "r" (t5));
            *(volatile int *)&((int *)&l.a)[2] = 0;
            int reach = *(volatile int *)&g_2c410c;
            float eps = 0.0001f;
            int rt1, rt2, rt3, rt4;
            asm volatile("lqc2 vf3, %1" : "=r" (rt1) : "m" (l.a), "r" (t6));
            asm volatile("qmtc2.ni %1, vf6" : "=r" (rt2) : "r" (reach), "r" (rt1));
            asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z" : "=r" (rt3) : "r" (rt2));
            asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q" : "=r" (rt4) : "r" (rt3), "f" (eps));
            int lenbits;
            asm volatile("qmfc2.ni %0, vf1" : "=r" (lenbits) : "r" (rt4));
            float len;
            asm volatile("mtc1 %1, %0" : "=f" (len) : "r" (lenbits));
            QW dirq = g_2a2dd0;
            asm("sqc2 vf4, %0" : "=m" (l.b));
            asm volatile("sqc2 vf6, %0" : "=m" (l.b));
            if (len < eps) {
                asm volatile("qmtc2.ni %0, vf1" : : "r" (dirq));
            } else {
                asm volatile("nop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q");
            }
            asm volatile("vmulx.xyzw vf1, vf1, vf6x\n\tsqc2 vf1, %0" : "=m" (*dst));
        }
    }
}
