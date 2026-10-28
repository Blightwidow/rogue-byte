#include "sly2.h"
struct VT { char pad[0x118]; short delta; short index; void (*fn)(void *, QW); };
struct LO { char pad0[0xC]; VT *vt; char pad1[0x28 - 0x10]; unsigned long flags; };
struct CARRY { char pad[0x180]; LO *plo; };
struct MURRAY { char pad0[0x13F0]; CARRY *pcarry; char pad1[0x1414 - 0x13F4]; float svThrow; char pad2[0x1420 - 0x1418]; QW posTarget; };
extern "C" void DetachMurrayObject(MURRAY *);
extern "C" int FIsBasicDerivedFrom(LO *, int);
extern "C" void func_00209FB8(LO *);
extern "C" QW PosLoWorld(LO *);
extern "C" QW GetSoDvGravity(LO *);
extern "C" QW VelBallistic(QW, QW, QW, float);
extern "C" void func_001F7A68(LO *, int);

void ThrowMurrayObject(MURRAY *self)
{
    DetachMurrayObject(self);
    LO *plo = self->pcarry->plo;
    self->pcarry = 0;
    if ((int)(plo->flags >> 60) & 1) {
        if (FIsBasicDerivedFrom(plo, 0x38))
            func_00209FB8(plo);
        QW pos = PosLoWorld(plo);
        int bits;
        asm("lqc2 vf2, %0" : : "m" (self->posTarget));
        asm("qmtc2.ni %0, vf3" : : "r" (pos));
        float sv = self->svThrow;
        asm("vsub.xyzw vf1, vf3, vf2\n\tvmul.xy vf1, vf1, vf1\n\tvaddy.x vf1, vf1, vf1y\n\tvsqrt Q, vf1x\n\tvwaitq\n\tvaddq.x vf1, vf0, Q");
        asm("qmfc2.ni %0, vf1" : "=r" (bits));
        float length = *(float *)&bits;
        float time = length / sv;
        QW pos2 = PosLoWorld(plo);
        QW target = self->posTarget;
        QW gravity = GetSoDvGravity(plo);
        QW velocity = VelBallistic(pos2, target, gravity, time);
        plo->vt->fn((char *)plo + plo->vt->delta, velocity);
        func_001F7A68(plo, 2);
    }
}
