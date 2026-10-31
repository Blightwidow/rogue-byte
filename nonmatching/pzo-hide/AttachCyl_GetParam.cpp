#include "sly2.h"
struct Alo_1834D0 { char pad0[0x10C]; float scale; };
struct Obj_1834D0 { char pad0[0x218]; QW *pos; };
static inline float LaneX(QW q) { float f; asm("mtc1 %1, %0" : "=f" (f) : "r" (q)); return f; }
extern "C" {
QW PosLoWorld(Alo_1834D0 *);
float atan2f(float, float);
void AttachCyl_GetParam(Alo_1834D0 *self, Obj_1834D0 *obj, float *out) {
    QW local = *obj->pos;
    QW world = PosLoWorld(self);
    QW diff;
    asm("qmtc2.ni %1, vf2\n\tlqc2 vf1, %2\n\tvsub.xyzw vf1, vf1, vf2\n\tqmfc2.ni %0, vf1" : "=r" (diff) : "r" (world), "m" (local));
    *out = atan2f(LaneX(__builtin_prot3w(diff)), LaneX(diff)) * self->scale;
}
}
