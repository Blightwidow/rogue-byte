/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct XF { char pad[0xA0]; void *parent; char pad2[0x4C]; QW acc; };
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct SO { char pad[0xC]; VT *vt; char pad2[0x58 - 0x10]; XF *lin; };
struct CLQ { float s0, s4, s8; };
extern "C" QW PosLoWorld(void *);
extern "C" QW ConvertXfVec(void *, void *, QW);
extern "C" float g_2dded4;
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }

void AccelSoTowardPosSpring(SO *pso, QW posTarget, CLQ *pclqPos, QW vTarget, CLQ *pclqV)
{
    XF *pxf = pso->lin;
    if (pclqPos != 0) {
        QW pos = PosLoWorld(pso);
        QW lenWord;
        asm volatile("qmtc2.ni %0, vf2" : : "r" (pos));
        float eps = 0.0001f;
        asm volatile("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf1, vf2\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\t"
            "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
            : "=r" (lenWord) : "m" (posTarget));
        float len = Lane(lenWord);
        if (eps < len) {
            QW d;
            asm volatile("qmfc2.ni %0, vf3" : "=r" (d));
            float scale = pclqPos->s8 * len + pclqPos->s4 + pclqPos->s0 / len;
            QW accel = pxf->acc;
            QW sv = Word(scale);
            QW dummy = sv;
            asm volatile("" : : "m" (dummy));
            QW r = ConvertXfVec(0, pxf->parent, d);
            asm volatile("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tqmtc2.ni %3, vf4\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf4, vf3x\n\tsqc2 vf1, %0"
                : "=m" (pxf->acc) : "m" (accel), "m" (sv), "r" (r));
        }
    }
    if (pclqV != 0) {
        QW v = pso->vt->fn((char *)pso + pso->vt->delta);
        QW lenWord;
        asm volatile("qmtc2.ni %0, vf2" : : "r" (v));
        float eps = 0.0001f;
        asm volatile("lqc2 vf1, %1\n\tvsub.xyzw vf3, vf1, vf2\n\tvmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\t"
            "vadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1"
            : "=r" (lenWord) : "m" (vTarget));
        float len = Lane(lenWord);
        if (eps < len) {
            QW d;
            asm volatile("qmfc2.ni %0, vf3" : "=r" (d));
            float scale = pclqV->s8 * len + pclqV->s4 + pclqV->s0 / len;
            float cap = 1.0f / g_2dded4;
            if (cap < scale)
                scale = cap;
            QW sv = Word(scale);
            QW accel = pxf->acc;
            QW dummy = sv;
            asm volatile("" : : "m" (dummy));
            QW r = ConvertXfVec(0, pxf->parent, d);
            asm volatile("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tqmtc2.ni %3, vf4\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddx.xyzw vf1, vf4, vf3x\n\tsqc2 vf1, %0"
                : "=m" (pxf->acc) : "m" (accel), "m" (sv), "r" (r));
        }
    }
}
