// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct PHYS { char pad[0x80]; QW grav; };
struct VT { char pad[0x108]; short delta; short index; QW (*fn)(void *); };
struct JTO { char pad0[0xC]; VT *vt; char pad1[0xE8 - 0x10]; PHYS *phys; char pad2[0x198 - 0xEC]; float scale; };
struct ZAP { JTO *jt; int state; };
extern QW g_2a2dd0;
extern float g_2dded4;
extern char D_002BFA90[];
extern "C" {
void AddSoAcceleration(JTO *, QW);
void AccelSoTowardPosSpring(JTO *, QW, int, QW, void *);
}
void PresetJtAccelZap(ZAP *zap)
{
    union QF { QW q; float f[4]; };
    struct { QF a; QF t; QW sp; } L;
    switch (zap->state) {
    case 1:
    case 2: {
        JTO *jt = zap->jt;
        PHYS *phys = jt->phys;
        float minus = -1.0f;
        int neg;
        QW accel;
        
        asm volatile("" : : "r" (phys));
        asm volatile("mfc1 %0, %1" : "=&r" (neg) : "f" (minus));
        asm("lqc2 vf1, 0x80(%0)" : : "r" (phys));
        asm("qmtc2.ni %0, vf2" : : "r" (neg));
        asm("vmulx.xyzw vf3, vf1, vf2x");
        asm volatile("sqc2 vf2, %0" : "=m" (L.a.q));
        asm("qmfc2.ni %0, vf3" : "=r" (accel));
        AddSoAcceleration(jt, accel);
        QW zero = g_2a2dd0;
        AccelSoTowardPosSpring(zap->jt, zero, 0, zero, D_002BFA90);
        return;
    }
    case 5:
    case 0xB:
        break;
    default:
        return;
    }
    JTO *jt = zap->jt;
    PHYS *phys = jt->phys;
    float minus = -1.0f;
    register int neg asm("$3");
    QW accel;
    asm volatile("" : : "r" (phys));
    asm volatile("mfc1 %0, %1" : "=&r" (neg) : "f" (minus));
    asm("qmtc2.ni %0, vf2" : : "r" (neg));
    asm("lqc2 vf1, 0x80(%0)" : : "r" (phys));
    asm("vmulx.xyzw vf3, vf1, vf2x");
    asm volatile("sqc2 vf2, %0" : "=m" (L.sp));
    asm("qmfc2.ni %0, vf3" : "=r" (accel));
    AddSoAcceleration(jt, accel);
    L.t.f[2] = 0.0f;
    L.t.f[1] = 0.0f;
    L.t.f[0] = 0.0f;
    JTO *jt2 = zap->jt;
    float zero = L.t.f[2];
    if (jt2->scale != zero) {
        QW vel = jt2->vt->fn((char *)jt2 + jt2->vt->delta);
        int word;
        float zval;
        asm("pextuw %1, $0, %2\n\tmtc1 %1, %0\n\tnop" : "=f" (zval), "=&r" (word) : "r" (vel));
        L.t.f[2] = zval;
    }
    AccelSoTowardPosSpring(zap->jt, g_2a2dd0, 0, L.t.q, D_002BFA90);
    JTO *jt3 = zap->jt;
    if (jt3->scale != zero) {
        L.a.f[2] = zero;
        L.a.f[1] = zero;
        L.a.f[0] = zero;
        L.a.f[2] = (-jt3->scale - L.t.f[2]) / g_2dded4;
        AddSoAcceleration(jt3, L.a.q);
    }
}
