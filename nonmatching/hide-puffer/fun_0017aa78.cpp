#include "sly2.h"
struct GOAL { char pad0[0x10]; void *plo; char pad1[0x5C - 0x14]; void *ptarget; };
struct QUERY { char pad0[4]; int sAlong; int dzAbove; char pad1[4]; QW posBase; QW vecBase; };
extern "C" QW PosLoWorld(void *);
extern QW g_2a2dc0;
extern QW g_2a2da0;
extern int g_2be6c4;
extern "C" void func_0017AA78(GOAL *pgoalArg, QUERY *pqueryArg, QW *pposAimArg, QW *pvecAimArg)
{
    register GOAL *pgoal asm("$16") = pgoalArg;
    register QUERY *pquery asm("$17") = pqueryArg;
    register QW *pposAim asm("$18") = pposAimArg;
    register QW *pvecAim asm("$19") = pvecAimArg;
    QW junk;
    QW save;
    asm volatile("" : "=m"(junk));
    asm volatile("" : "=m"(save));
    QW posGuard = PosLoWorld(pgoal->plo);
    asm volatile("qmtc2.ni %0, vf3" : : "r" (posGuard));
    register void *arg asm("$4") = pgoal->ptarget;
    asm volatile("sqc2 vf3, %0" : "=m" (save) : "r" (arg));
    QW posTarget = PosLoWorld(arg);
    register unsigned hiup asm("$4");
    asm volatile("lui $3, %%hi(g_2a2dc0)" : : : "$3");
    asm volatile("qmtc2.ni %0, vf1" : : "r" (posTarget));
    asm volatile("lqc2 vf3, %0" : : "m" (save));
    asm volatile("daddu $4, $3, $0" : "=r" (hiup));
    asm volatile("vsub.xyzw vf3, vf3, vf1");
    asm volatile("addiu $3, $3, %%lo(g_2a2dc0)\n\tlqc2 vf1, 0($3)" : : : "$3");
    asm volatile("lui $2, %%hi(g_2a2da0)" : : : "$2");
    asm volatile("vmul.xyz vf2, vf3, vf1\n\tvaddw.x vf4, vf0, vf0w\n\tvadday.x ACC, vf2, vf2y\n\tvmaddz.x vf2, vf4, vf2z");
    register float limit asm("$f1") = 0.0001f;
    asm volatile("vmulx.xyzw vf2, vf1, vf2x");
    asm volatile("addiu $2, $2, %%lo(g_2a2da0)" : : : "$2");
    asm volatile("vsub.xyzw vf3, vf3, vf2");
    register QW unitX asm("$2");
    asm volatile("lq $2, 0($2)" : "=r" (unitX));
    asm volatile("vmul.xyz vf1, vf3, vf3\n\tvaddw.x vf2, vf0, vf0w\n\tvadday.x ACC, vf1, vf1y\n\tvmaddz.x vf1, vf2, vf1z");
    asm volatile("vsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
    register float length asm("$f0");
    asm volatile("qmfc2.ni $3, vf1\n\tmtc1 $3, %0\n\tnop" : "=f" (length) : : "$3");
    asm volatile(".set noreorder\n\tc.lt.s %0, %1\n\tnop\n\tbc1f 1f\n\tnop\n\tb 2f\n\tqmtc2.ni %2, vf1\n1:\n\tnop\n\tnop\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf1, vf3, Q\n2:\n\t.set reorder" : : "f" (length), "f" (limit), "r" (unitX));
    asm volatile("addiu $2, %3, %%lo(g_2a2dc0)\n\tlw $3, 4(%4)\n\tlqc2 vf5, 0($2)\n\tqmtc2.ni $3, vf4\n\tlw $2, 8(%4)\n\tlqc2 vf2, 0x10(%4)\n\tqmtc2.ni $2, vf6\n\tvadda.xyzw ACC, vf0, vf2\n\tvmaddax.xyzw ACC, vf1, vf4x\n\tvmaddx.xyzw vf2, vf5, vf6x\n\tlui $2, %%hi(g_2be6c4)\n\tlqc2 vf1, 0x20(%4)\n\tlw $2, %%lo(g_2be6c4)($2)\n\tqmtc2.ni $2, vf3\n\tsqc2 vf4, %0\n\tsqc2 vf2, 0(%5)\n\tvadda.xyzw ACC, vf0, vf1\n\tvmaddx.xyzw vf1, vf5, vf3x\n\tsqc2 vf6, %0\n\tsqc2 vf1, 0(%6)" : "=m" (junk), "=m" (*pposAim), "=m" (*pvecAim) : "r" (hiup), "r" (pquery), "r" (pposAim), "r" (pvecAim) : "$2", "$3");
    asm volatile("sqc2 vf3, %0" : "=m" (junk));
}
