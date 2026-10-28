#include "sly2.h"
struct Locals { char frame[0x10]; QW slot; char lsg[0x10]; QW hitEnd; char lsgRest[0x40]; int count; int list; };
extern "C" int g_2be750;
extern "C" int g_2be754;
extern "C" QW g_2a2dc0;
extern "C" void CStackFrame_Construct(void *);
extern "C" void CStackFrame_Destructor(void *, int);
extern "C" void func_001B44D8(int *, int *);
extern "C" void *PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(int, QW, QW, int, int, void *);
extern "C" int func_0017D608(QW *ppos)
{
    Locals l;
    CStackFrame_Construct(l.frame);
    func_001B44D8(&l.count, &l.list);
    QW posFrom, posTo;
    asm volatile("qmtc2.ni %0, vf4\n\tlqc2 vf2, 0(%1)" : : "r" (g_2be750), "r" (&g_2a2dc0));
    asm volatile("lqc2 vf1, 0(%0)" : : "r" (ppos));
    asm volatile("qmtc2.ni %1, vf3\n\tsqc2 vf4, %0" : "=m" (l.slot) : "r" (g_2be754));
    asm volatile("vadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf5, vf2, vf3x");
    asm("qmfc2.ni %0, vf5" : "=r" (posTo));
    asm volatile("vadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf5, vf2, vf4x\n\tsqc2 vf3, %0" : "=m" (l.slot));
    asm("qmfc2.ni %0, vf5" : "=r" (posFrom));
    void *pso = PsoHitTestLineObjects__FiP6VECTORT1iPP2SOP3LSG(0, posFrom, posTo, l.count, l.list, l.lsg);
    if (pso != 0) {
        *ppos = l.hitEnd;
        CStackFrame_Destructor(l.frame, 2);
        return 1;
    }
    CStackFrame_Destructor(l.frame, 2);
    return 0;
}
