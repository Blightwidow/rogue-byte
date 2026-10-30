#include "sly2.h"
extern "C" char B_003DD490;
extern "C" QW g_2a2dc0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" int FFilterHitTestDefault(void *, void *);
extern "C" void bevy_camera_follow_push_out(void *, QW, QW, void *, void *, int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, void *);
extern "C" int FFindSurfaceAlongUp(float sStart, float sEnd, QW *ppos, long fSteepOk, void *pfnFilter)
{
    char frame[0x10];
    int csoAso[2];
    char lsg[0x60];
    char spill[16];
    QW posEnd;
    QW posStart;
    int chain;
    register int bits asm("$2");
    CStackFrame_Construct(frame);
    asm("" : "=m" (posStart));
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (sStart));
    asm("qmtc2.ni %1, vf4" : "=r" (chain) : "r" (bits));
    asm("mfc1 %0, %1" : "=r" (bits) : "f" (sEnd));
    asm("lqc2 vf2, %1" : "+r" (chain) : "m" (g_2a2dc0));
    asm("qmtc2.ni %1, vf3" : "+r" (chain) : "r" (bits));
    asm("lqc2 vf1, %1" : "+r" (chain) : "m" (*ppos));
    asm("vadda.xyzw ACC, vf0, vf1" : "+r" (chain));
    asm("vmaddx.xyzw vf5, vf2, vf3x" : "+r" (chain));
    asm("sqc2 vf4, %1" : "+r" (chain), "=m" (*(QW *)spill));
    asm("sqc2 vf5, %1" : "+r" (chain), "=m" (posEnd));
    asm("vadda.xyzw ACC, vf0, vf1" : "+r" (chain));
    asm("vmaddx.xyzw vf5, vf2, vf4x" : "+r" (chain));
    asm("sqc2 vf3, %1" : "+r" (chain), "=m" (*(QW *)spill));
    asm("sqc2 vf5, %0" : "=m" (posStart));
    if (pfnFilter == 0)
        pfnFilter = (void *)FFilterHitTestDefault;
    bevy_camera_follow_push_out(&B_003DD490, posStart, posEnd, pfnFilter, 0, &csoAso[0], &csoAso[1]);
    void *pso = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(1, posStart, posEnd, csoAso[0], csoAso[1], lsg);
    if (pso == 0 || *(float *)(lsg + 0x40) == 0.0f || (fSteepOk == 0 && *(float *)(lsg + 0x28) < 0.7f)) {
        CStackFrame_Destructor(frame, 2);
        return 0;
    }
    *ppos = *(QW *)lsg;
    CStackFrame_Destructor(frame, 2);
    return 1;
}
