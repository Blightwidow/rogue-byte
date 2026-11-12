/* SPDX-License-Identifier: GPL-3.0-or-later */
#include "types.h"
#include "sly2.h"
#include "vu0inline.h"

extern "C" {
QW PosLoWorld(void *);
float GRandInRange(float low, float high);
QW SetVectorCylind__FP6VECTORfff(float radius, float height, float unused);
extern QW g_2a2dc0;
extern float g_2be8c4;
}

extern "C" void AttachCyl_GetRandomPos(void *self, QW *outPos, QW *outCopy)
{
    float angle = GRandInRange(-3.14159265f, 3.14159265f);
    float height = GRandInRange(0.0f, g_2be8c4) + *(float *)((char *)self + 0x10C);
    QW base = PosLoWorld(self);
    QW cylinder = SetVectorCylind__FP6VECTORfff(angle, height, 0.0f);
    *outPos = VectorAdd(base, cylinder);
    *outCopy = g_2a2dc0;
}
