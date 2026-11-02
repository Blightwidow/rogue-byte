// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct VT { char pad[0x108]; short delta; short index; QW (*fnVel)(void *); };
struct TARMISS { char pad0[0xC]; VT *vt; char pad1[0x1E8 - 0x10]; int stuck; char pad2[0x278 - 0x1EC]; float tExpire; char pad3[4]; QW vTarget; };
struct CLOCKS { float t; float dt; };
extern CLOCKS g_2dded0;
extern QW g_2a2dd0;
static inline QW Word(float f) { QW r; asm("mfc1 %0, %1" : "=r" (r) : "f" (f)); return r; }
static inline float Lane(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" {
void PosPredictMissileTarget(VECTOR *, TARMISS *, float);
int FFloatsNear__Ffff(float, float);
QW PosLoWorld(void *);
void EvaluateBezierPos__FfffP6VECTORN63(float, float, float, QW, QW, QW, QW, QW *, QW *, QW *);
void AddSoAcceleration(TARMISS *, QW);
}
struct SLOTS { VECTOR s00; QW s10; QW s20; QW s30; QW s40; QW s50; QW s60; QW s70; };
/* lane 2 of a QW: pextuw into the low word of a temporary */
static inline QW Upper(QW q) { QW r; asm("pextuw %0, $0, %1" : "=r" (r) : "r" (q)); return r; }
void PresetTarmissAccel(TARMISS *self)
{
    if (self->stuck != 0)
        return;
    SLOTS L;
    float left = self->tExpire - g_2dded0.t;
    float zero = 0.0f;
    float remaining = (left > zero ? left : zero) + g_2dded0.dt;
    float half0 = 0.5f;
    float predict = half0 < remaining ? half0 : remaining;
    PosPredictMissileTarget(&L.s00, self, predict);
    QW posTarget = *(QW *)&L.s00;
    L.s30 = posTarget;
    QW target = self->vTarget;
    QW zeroVec = g_2a2dd0;
    int isZero = 0;
    if (FFloatsNear__Ffff(Lane(zeroVec), Lane(target))) {
        if (FFloatsNear__Ffff(Lane(__builtin_prot3w(zeroVec)), Lane(__builtin_prot3w(target))))
            isZero = FFloatsNear__Ffff(Lane(Upper(zeroVec)), Lane(Upper(target))) != 0;
    }
    if (isZero) {
        float rDt = 1.5f / remaining;
        QW splat = Word(rDt);
        asm volatile("sq %1, %0" : "=m" (L.s40) : "r" (splat));
        asm volatile("sq %1, %0" : "=m" (L.s10) : "r" (splat));
        QW pos0 = PosLoWorld(self);
        QW dpos;
        asm("lqc2 vf1, %1\n\tqmtc2.ni %2, vf2\n\tvsub.xyzw vf2, vf1, vf2\n\tsqc2 vf2, %0" : "=m" (L.s50) : "m" (L.s30), "r" (pos0));
        float half = -0.5f;
        QW splat2 = Word(half);
        asm volatile("sq %1, %0" : "=m" (L.s60) : "r" (splat2));
        QW vel0 = self->vt->fnVel((char *)self + self->vt->delta);
        asm volatile("lqc2 vf2, %1\n\tlqc2 vf3, %2\n\tlqc2 vf4, %3\n\tqmtc2.ni %4, vf5\n\tvmulax.xyzw ACC, vf3, vf2x\n\tvmaddx.xyzw vf1, vf5, vf4x\n\tsqc2 vf1, %0" : "=m" (*(QW *)&L.s00) : "m" (L.s40), "m" (L.s50), "m" (L.s60), "r" (vel0));
    } else {
        *(QW *)&L.s00 = self->vTarget;
    }
    float dt = g_2dded0.dt;
    QW pos = PosLoWorld(self);
    QW vel = self->vt->fnVel((char *)self + self->vt->delta);
    QW velNew = L.s10;
    EvaluateBezierPos__FfffP6VECTORN63(remaining, dt, 1.0f, pos, vel, L.s30, *(QW *)&L.s00, 0, &L.s10, 0);
    asm volatile("sq %1, %0" : "=m" (L.s70) : "r" (velNew));
    QW velNow = self->vt->fnVel((char *)self + self->vt->delta);
    int dtBits = *(int *)&g_2dded0.dt;
    QW accel;
    asm("lqc2 vf1, %2\n\tqmtc2.ni %3, vf3\n\tvsub.xyzw vf2, vf1, vf3\n\tqmtc2.ni %4, vf1\n\tvdiv Q, vf0w, vf1x\n\tvwaitq\n\tvmulq.xyzw vf4, vf2, Q\n\tsqc2 vf1, %0\n\tqmfc2.ni %1, vf4" : "=m" (L.s20), "=r" (accel) : "m" (L.s70), "r" (velNow), "r" (dtBits));
    AddSoAcceleration(self, accel);
}
