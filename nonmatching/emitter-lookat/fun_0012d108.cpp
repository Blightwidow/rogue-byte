#include "sly2.h"
struct Owner { char pad[0x90]; void *first; char pad2[0x2C]; QW pos; };
struct Lookat { int pad0; void *palo; Owner *owner; char pad1[0x14]; QW pos; };
extern "C" {
int FFloatsNear__Ffff(float, float, float);
void WakeXf(void *, void *);
}
extern QW g_2a2dd0;
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
static inline float LaneY(QW q) { QW t; float f; asm("prot3w %0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }
void func_0012D108(Lookat *self, QW pos)
{
    QW diff;
    asm("qmtc2.ni %0, vf2" : : "r" (pos));
    asm("lqc2 vf1, %0" : : "m" (self->pos));
    self->pos = pos;
    QW *ppos = &pos;
    asm volatile("" : : "r" (ppos));
    asm("vsub.xyzw vf2, vf2, vf1");
    if (self->owner->first != self)
        return;
    asm("qmfc2.ni %0, vf2" : "=r" (diff));
    QW g = g_2a2dd0;
    int unchanged = 0;
    if (FFloatsNear__Ffff(LaneX(g), LaneX(diff), 0.0001f)) {
        if (FFloatsNear__Ffff(LaneY(g), LaneY(diff), 0.0001f))
            unchanged = FFloatsNear__Ffff(LaneZ(g), LaneZ(diff), 0.0001f) != 0;
    }
    if (!unchanged) {
        self->owner->pos = pos;
        WakeXf(self->palo, self->owner);
    }
}
