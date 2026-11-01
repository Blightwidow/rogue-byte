#include "sly2.h"
extern "C" char B_003DD490;
extern "C" QW g_2a2dc0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int FFilterHitTestDefault(void *, void *);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, void *);
struct Locals { char frame[0x10]; char spill[0x10]; char lsg[0x60]; int csoAso[2]; int pad[2]; QW posStart; QW posEnd; };
extern "C" int FFindSurfaceAlongUp(float sStart, float sEnd, QW *ppos, long fSteepOk, void *pfnFilter)
{
    Locals l;
    int bits;
    CStackFrame_Construct(l.frame);
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (sStart));
    asm("qmtc2.ni %0, vf4" : : "r" (bits));
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (sEnd));
    asm("lqc2 vf2, %0" : : "m" (g_2a2dc0));
    asm("qmtc2.ni %0, vf3" : : "r" (bits));
    asm("lqc2 vf1, %0" : : "m" (*ppos));
    asm("vadda.xyzw ACC, vf1, vf0");
    asm("vmaddx.xyzw vf5, vf2, vf3x");
    asm("sqc2 vf4, %0" : "=m" (*(QW *)l.spill));
    asm("sqc2 vf5, %0" : "=m" (l.posEnd));
    asm("vadda.xyzw ACC, vf1, vf0");
    asm("vmaddx.xyzw vf5, vf2, vf4x");
    asm("sqc2 vf3, %0" : "=m" (*(QW *)l.spill));
    asm("sqc2 vf5, %0" : "=m" (l.posStart));
    if (pfnFilter == 0)
        pfnFilter = (void *)FFilterHitTestDefault;
    bevy_camera_follow_push_out(&B_003DD490, l.posStart, l.posEnd, pfnFilter, 0, &l.csoAso[0], &l.csoAso[1]);
    void *pso = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(1, l.posStart, l.posEnd, l.csoAso[0], l.csoAso[1], l.lsg);
    if (pso == 0 || *(float *)(l.lsg + 0x40) == 0.0f || (fSteepOk == 0 && *(float *)(l.lsg + 0x28) < 0.7f)) {
        CStackFrame_Destructor(l.frame, 2);
        return 0;
    }
    *ppos = *(QW *)l.lsg;
    CStackFrame_Destructor(l.frame, 2);
    return 1;
}
