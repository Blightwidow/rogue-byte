#include "sly2.h"
extern "C" {
QW PosLoWorld(void *);
void Goal_FillVjoy(void *, void *);
void UpdateVjoyPressTimes(void *);
float atan2f(float, float);
extern float g_2dded0;
}
struct Range { float lo; float hi; };
extern "C" const Range g_2a4e58;
void func_00146B18(char *self, char *vjoy)
{
    Goal_FillVjoy(self, vjoy);
    int state = *(int *)(self + 0x30);
    int c1, c2, c3, bits, rot;
    switch (state) {
    case 1: {
        QW target = PosLoWorld(*(void **)(self + 0x38));
        QW owner = PosLoWorld(*(void **)(self + 0x10));
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2" : "=r" (c2) : "m" (target), "r" (owner));
        asm("vsub.xyzw vf1, vf1, vf2" : "=r" (c3) : "r" (c2));
        asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (c3));
        *(float *)(vjoy + 0x1C) = 1.0f;
        asm("prot3w %0, %1" : "=r" (rot) : "r" (bits));
        float y, x;
        asm("mtc1 %1, %0" : "=f" (x) : "r" (bits));
        asm("mtc1 %1, %0" : "=f" (y) : "r" (rot));
        *(float *)(vjoy + 0x18) = atan2f(y, x);
        break;
    }
    case 2: {
        QW target = PosLoWorld(*(void **)(self + 0x38));
        QW owner = PosLoWorld(*(void **)(self + 0x10));
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2" : "=r" (c2) : "m" (target), "r" (owner));
        asm("vsub.xyzw vf1, vf1, vf2" : "=r" (c3) : "r" (c2));
        asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (c3));
        *(float *)(vjoy + 0x1C) = 1.0f;
        asm("prot3w %0, %1" : "=r" (rot) : "r" (bits));
        float y, x;
        asm("mtc1 %1, %0" : "=f" (x) : "r" (bits));
        asm("mtc1 %1, %0" : "=f" (y) : "r" (rot));
        *(float *)(vjoy + 0x18) = atan2f(y, x);
        if (g_2dded0 - *(float *)(self + 0x34) < 0.1f) {
            *(int *)(vjoy + 0x30) |= 0x80;
            UpdateVjoyPressTimes(vjoy);
        }
        break;
    }
    case 3: {
        QW target = PosLoWorld(*(void **)(self + 0x38));
        QW owner = PosLoWorld(*(void **)(self + 0x10));
        asm volatile("qmtc2.ni %1, vf3" : "=r" (c1) : "r" (owner));
        union { QW q; float f[4]; } k;
        k.q = (QW)0;
        asm("lqc2 vf1, %1" : "=r" (c2) : "m" (target), "r" (c1));
        k.f[0] = -0.25f;
        asm("vsub.xyzw vf2, vf1, vf3" : "=r" (c3) : "r" (c2));
        k.f[1] = 0.00156249990f;
        asm("vmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y" : "=r" (c1) : "r" (c3));
        Range range = g_2a4e58;
        asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (bits) : "r" (c1));
        float distance;
        asm("mtc1 %1, %0" : "=f" (distance) : "r" (bits));
        float stick = k.f[0] + distance * (k.f[1] + distance * k.f[2]);
        if (stick < range.lo)
            stick = range.lo;
        else if (range.hi < stick)
            stick = range.hi;
        int bits2;
        asm("qmfc2.ni %0, vf2" : "=r" (bits2) : "r" (c3));
        *(float *)(vjoy + 0x1C) = stick;
        float y, x;
        asm("mtc1 %1, %0" : "=f" (x) : "r" (bits2));
        asm("prot3w %0, %0" : "+r" (bits2));
        asm("mtc1 %1, %0" : "=f" (y) : "r" (bits2));
        *(float *)(vjoy + 0x18) = atan2f(y, x);
        if (g_2dded0 - *(float *)(self + 0x34) < 0.1f) {
            if (*(int *)(*(char **)(self + 0x10) + 0x2DC) == -1) {
                *(int *)(vjoy + 0x30) |= 0x40;
                UpdateVjoyPressTimes(vjoy);
            }
        }
        break;
    }
    case 4: {
        QW target = PosLoWorld(*(void **)(self + 0x38));
        QW owner = PosLoWorld(*(void **)(self + 0x10));
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2" : "=r" (c2) : "m" (target), "r" (owner));
        asm("vsub.xyzw vf1, vf1, vf2" : "=r" (c3) : "r" (c2));
        asm("qmfc2.ni %0, vf1" : "=r" (bits) : "r" (c3));
        *(float *)(vjoy + 0x1C) = 1.0f;
        asm("prot3w %0, %1" : "=r" (rot) : "r" (bits));
        float y, x;
        asm("mtc1 %1, %0" : "=f" (x) : "r" (bits));
        asm("mtc1 %1, %0" : "=f" (y) : "r" (rot));
        *(float *)(vjoy + 0x18) = atan2f(y, x);
        if (g_2dded0 - *(float *)(self + 0x34) < 0.1f) {
            *(int *)(vjoy + 0x30) |= 0x80;
            UpdateVjoyPressTimes(vjoy);
        }
        break;
    }
    }
}
