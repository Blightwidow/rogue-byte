#include "sly2.h"
struct Owner { char pad[0x90]; void *first; char pad2[0x2C]; VECTOR pos; char pad3[0x10]; VECTOR pos2; };
struct Act { int pad0; void *palo; Owner *owner; char pad1[0x14]; VECTOR pos; };
extern "C" {
int FFloatsNear__Ffff(float, float, float);
void WakeXf(void *, void *);
}
extern QW g_2a2dd0;
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline int Near(float a, float b) { return FFloatsNear__Ffff(a, b, 0.0001f); }
void SetActadjOffset(Act *self, QW offset)
{
    QW delta;
    asm("qmtc2.ni %0, vf2" : : "r" (offset));
    asm("lqc2 vf1, %0" : : "m" (self->pos));
    asm("vsub.xyzw vf3, vf2, vf1");
    asm("sqc2 vf3, %0" : "=m" (delta));
    asm("sqc2 vf2, %0" : "=m" (self->pos));
    if (self->owner->first != self)
        return;
    QW g = g_2a2dd0;
    QW dreg;
    asm("qmfc2.ni %0, vf3" : "=r" (dreg));
    int unchanged = 0;
    if (Near(LaneX(g), LaneX(dreg))) {
        if (Near(LaneY(g), LaneY(delta)))
            unchanged = Near(LaneZ(g), LaneZ(delta)) != 0;
    }
    if (!unchanged) {
        asm("lqc2 vf2, %0" : : "m" (delta));
        asm("lqc2 vf1, %0" : : "m" (self->owner->pos));
        asm("vadd.xyzw vf1, vf1, vf2");
        asm("sqc2 vf1, %0" : "=m" (self->owner->pos));
        asm("lqc2 vf1, %0" : : "m" (self->owner->pos2));
        asm("vadd.xyzw vf1, vf1, vf2");
        asm("sqc2 vf1, %0" : "=m" (self->owner->pos2));
        WakeXf(self->palo, self->owner);
    }
}
