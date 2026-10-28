// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct LOB { char pad0[0xE0]; LOB *next; char pad1[4]; unsigned flags; };
struct MURRAY { char pad0[0x13F0]; void *carried; char pad1[0x1410 - 0x13F4]; float sThrow; char pad2[0x1420 - 0x1414]; QW goal; };
extern "C" {
extern float D_002C0984;
extern float D_002C0988;
extern LOB *B_003E13B4;
int func_00184380(void *, LOB *);
QW PosLoWorld(void *);
float atan2f(float, float);
float RadYawSo(MURRAY *);
float RadNormalize__Ff(float);
QW SetVectorCylind__FP6VECTORfff(float, float, float);
}
void ChooseMurrayThrowTarget(MURRAY *self)
{
    struct { QW unused; QW first; QW second; } frame;
    LOB *best = 0;
    float sBest = self->sThrow * D_002C0984;
    for (LOB *lo = B_003E13B4; lo != 0; lo = lo->next) {
        if ((lo->flags & 0x10000) == 0)
            continue;
        if (func_00184380(self->carried, lo) != 0)
            continue;
        frame.first = PosLoWorld(lo);
        QW posSelf = PosLoWorld(self);
        int lengthBits;
        asm volatile("lqc2 vf1, %1\n\tqmtc2.ni %2, vf3\n\tvsub.xyzw vf2, vf1, vf3\n\tvmul.xy vf1, vf2, vf2\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q\n\tqmfc2.ni %0, vf1" : "=r" (lengthBits) : "m" (frame.first), "r" (posSelf));
        float length;
        asm volatile("mtc1 %1, %0\n\tnop" : "=f" (length) : "r" (lengthBits));
        if (sBest < length)
            continue;
        if (length < 150.0f)
            continue;
        QW dposZ;
        asm volatile("qmfc2.ni %0, vf2" : "=r" (dposZ));
        int zBits;
        asm volatile("pextuw %0, $0, %1" : "=r" (zBits) : "r" (dposZ));
        float z;
        asm volatile("mtc1 %1, %0\n\tnop" : "=f" (z) : "r" (zBits));
        if (500.0f < z)
            continue;
        QW dposXY;
        asm volatile("qmfc2.ni %0, vf2" : "=r" (dposXY));
        float x;
        float y;
        asm volatile("mtc1 %2, %0\n\tprot3w %2, %2\n\tmtc1 %2, %1" : "=f" (x), "=f" (y), "+r" (dposXY));
        float toward = atan2f(y, x);
        float dyaw = RadNormalize__Ff(toward - RadYawSo(self));
        if (D_002C0988 < __builtin_fabsf(dyaw))
            continue;
        best = lo;
        sBest = length;
        self->goal = PosLoWorld(best);
    }
    if (best == 0) {
        QW tmp = PosLoWorld(self);
        float heading = *(float *)((char *)self + 0x1A8);
        asm volatile("sq %1, %0" : "=m" (frame.second) : "r" (tmp));
        QW offset = SetVectorCylind__FP6VECTORfff(heading, self->sThrow, 0.0f);
        asm("lqc2 vf2, %1\n\tqmtc2.ni %2, vf3\n\tvadd.xyzw vf1, vf2, vf3\n\tsqc2 vf1, %0" : "=m" (self->goal) : "m" (frame.second), "r" (offset));
    }
}
