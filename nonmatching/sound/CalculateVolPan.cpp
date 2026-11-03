#include "sly2.h"
struct LM;
struct Falloff { float near; float far; };
extern "C" {
QW ConvertAloVec(int, void *, QW);
float GLimitLm__FP2LMf(LM *, float);
QW PosLoWorld(void *);
void *PpoSwFocus(void *);
float atan2f(float, float);
extern char B_002DDF40[];
extern char B_003DD490[];
extern LM g_2bbb60;
}
extern "C" void CalculateVolPan(void *psnd, QW pos, Falloff *pfalloff, float *pvolume, int *ppan)
{
    QW delta;
    float length;
    void *pfocus = PpoSwFocus(B_003DD490);
    if (pfocus != 0)
        asm volatile("qmtc2.ni %0, vf1" : : "r" (PosLoWorld(pfocus)));
    else
        asm volatile("lqc2 vf1, 0x90(%0)" : : "r" (B_002DDF40));
    asm volatile("lqc2 vf2, %0" : : "m" (pos));
    asm volatile("vsub.xyzw vf3, vf2, vf1");
    float farDistance = pfalloff->far;
    asm volatile("vmul.xyz vf1, vf3, vf3");
    asm volatile("vaddw.x vf2, vf0, vf0w");
    asm volatile("vadday.x ACC, vf1, vf1y");
    asm volatile("vmaddz.x vf1, vf2, vf1z");
    float nearDistance = pfalloff->near;
    asm volatile("vsqrt Q, vf1x");
    asm volatile("vwaitq");
    asm volatile("vaddq.x vf1, vf0, Q");
    asm volatile("sqc2 vf3, %0" : "=m" (delta));
    asm volatile("qmfc2.ni %0, vf1" : "=r" (length));
    float volume = GLimitLm__FP2LMf(&g_2bbb60, (farDistance - length) / (farDistance - nearDistance));
    asm volatile("lqc2 vf3, %0" : : "m" (delta));
    if (pvolume != 0)
        *pvolume = volume;
    if (ppan != 0) {
        if (volume > 0.0f) {
            QW local;
            asm volatile("qmfc2.ni %0, vf3" : "=r" (local));
            QW world = ConvertAloVec(0, pfalloff, local);
            QW rotated = __builtin_prot3w(world);
            float fx, fy;
            asm("mtc1 %2, %0\n\tmtc1 %3, %1" : "=f" (fx), "=f" (fy) : "r" (world), "r" (rotated));
            float angle = atan2f(-fy, fx);
            if (pfalloff->far < pfalloff->near)
                angle += 3.1415927f;
            *ppan = (int)(angle * 57.295776f);
        } else {
            *ppan = 0;
        }
    }
}
