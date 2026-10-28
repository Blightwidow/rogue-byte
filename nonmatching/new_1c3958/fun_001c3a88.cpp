/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "sly2.h"
struct PIPE;
extern "C" float g_2c0d10;
extern "C" float g_2c0d08;
extern "C" float g_2c0d0c;
extern "C" float SRandNearCrv(PIPE *, float, float);
extern "C" void GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(PIPE *, int, float, void *);
extern "C" void GetPathPosFromS(PIPE *, void *, int, float);
extern "C" float GRandInRange(float, float);
extern "C" QW SetVectorCylind__FP6VECTORfff(float, float, float);
extern "C" void func_001C3A88(PIPE *ppipe, QW *ppos, QW *pdir, float s)
{
    struct { QW posPath; QW mat[3]; QW tmpB; QW tmpA; QW posCopy; } l;
    float sNear = SRandNearCrv(ppipe, s, g_2c0d10);
    float zero;
    asm("mtc1 $0, %0" : "=f" (zero));
    GetJtPipeGoalMat__FP2JTP4PIPEfP7MATRIX3(ppipe, 1, sNear, l.mat);
    GetPathPosFromS(ppipe, &l.posPath, 0, sNear);
    float gRandom = GRandInRange(-1.0f, 1.0f);
    float gWeight = __builtin_fabsf(gRandom);
    QW local = SetVectorCylind__FP6VECTORfff(gRandom * gWeight * g_2c0d08, -1.0f, zero);
    asm volatile("qmtc2.ni %0, vf4" : : "r" (local));
    l.posCopy = l.posPath;
    asm volatile("lqc2 vf3, %1\n\tlqc2 vf2, %2\n\tlqc2 vf1, %3\n\tvmulax.xyz ACC, vf3, vf4x\n\tvmadday.xyz ACC, vf2, vf4y\n\tvmaddz.xyz vf4, vf1, vf4z\n\tsqc2 vf4, %0" : "=m" (l.tmpA) : "m" (l.mat[0]), "m" (l.mat[1]), "m" (l.mat[2]));
    float gDist = gWeight * GRandInRange(zero, g_2c0d0c);
    QW dir;
    int scratch;
    asm volatile("lqc2 vf4, %3\n\tlqc2 vf3, %4\n\tmfc1 %1, %5\n\tqmtc2.ni %1, vf1\n\tsqc2 vf1, %0\n\tvadda.xyzw ACC, vf0, vf3\n\tvmaddx.xyzw vf2, vf4, vf1x\n\tsqc2 vf2, 0(%6)\n\tqmfc2.ni %2, vf4" : "=m" (l.tmpB), "=&r" (scratch), "=r" (dir) : "m" (l.tmpA), "m" (l.posCopy), "f" (gDist), "r" (ppos));
    *pdir = dir;
}
