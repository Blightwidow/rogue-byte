#include "sly2.h"
static inline float GClampUnit(float g)
{
    float lo = 0.0f;
    float hi = 1.0f;
    if (g < lo)
        return lo;
    if (hi < g)
        return hi;
    return g;
}
extern "C" void FindClosestPointBetweenLines__FP6VECTORN30PfT4T0(QW, QW, QW, QW, float *, float *, QW *);
extern "C" const QW g_2a2da0;
extern "C" void FindClosestPointBetweenLineSegments__FP6VECTORN40PfT0(QW posA0, QW posA1, QW posB0, QW posB1, float *pau, float *ps, QW *pvecDirection)
{
    QW junk;
    FindClosestPointBetweenLines__FP6VECTORN30PfT4T0(posA0, posA1, posB0, posB1, pau, ps, pvecDirection);
    float uA = GClampUnit(pau[0]);
    pau[0] = uA;
    float uBreg = GClampUnit(pau[1]);
    register int lengthWord asm("$2");
    asm volatile("" : "=m" (junk));
    asm volatile(".set noreorder\n\tlwc1 $f0, 0(%2)\n\tlui $1, 0x3F80\n\tmtc1 $1, $f3\n\tneg.s $f1, $f0\n\tlqc2 vf2, %3\n\tsub.s $f2, $f3, %1\n\tlqc2 vf6, %4\n\tsub.s $f0, $f0, $f3\n\tlqc2 vf8, %5\n\tmfc1 $3, $f1\n\tqmtc2.ni $3, vf3\n\tmfc1 $2, %1\n\tmfc1 $3, $f2\n\tqmtc2.ni $2, vf5\n\tqmtc2.ni $3, vf4\n\tlqc2 vf9, %6\n\tmfc1 $3, $f0\n\tlui $2, %%hi(g_2a2da0)\n\tqmtc2.ni $3, vf1\n\tlui $1, 0x38D1\n\tori $1, $1, 0xB717\n\tmtc1 $1, $f4\n\tvmulax.xyzw ACC, vf2, vf1x\n\tvmaddax.xyzw ACC, vf6, vf3x\n\tvmaddax.xyzw ACC, vf8, vf4x\n\tvmaddx.xyzw vf7, vf9, vf5x\n\tsqc2 vf1, 0($sp)\n\tvmul.xyz vf2, vf7, vf7\n\tvaddw.x vf6, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf6, vf2z\n\tsqc2 vf3, 0($sp)\n\tvsqrt Q, vf2x\n\tvwaitq\n\tvaddq.x vf2, vf0, Q\n\tswc1 %1, 4(%7)\n\tqmfc2.ni $3, vf2\n\taddiu $2, $2, %%lo(g_2a2da0)\n\tmtc1 $3, $f0\n\tsqc2 vf4, 0($sp)\n\tc.lt.s $f0, $f4\n\tsqc2 vf5, 0($sp)\n\tbc1f 1f\n\tsqc2 vf7, 0(%8)\n\tlq $2, 0($2)\n\tb 2f\n\tsq $2, 0(%8)\n1:\n\tnop\n\tnop\n\tvdiv Q, vf0w, vf2x\n\tvwaitq\n\tvmulq.xyzw vf1, vf7, Q\n\tsqc2 vf1, 0(%8)\n2:\n\tqmfc2.ni %0, vf2\n\t.set reorder"
        : "=r" (lengthWord) : "f" (uBreg), "r" (pau), "m" (posA0), "m" (posA1), "m" (posB0), "m" (posB1), "r" (pau), "r" (pvecDirection) : "$1", "$2", "$3", "$f0", "$f1", "$f2", "$f3", "$f4", "memory");
    *(int *)ps = lengthWord;
}
