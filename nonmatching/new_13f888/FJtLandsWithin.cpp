#include "sly2.h"
typedef QW (*PFNVEC)(void *);
struct VT { char pad0[0x108]; short d108; short i108; PFNVEC f10C; };
struct PHYS { char pad[0x88]; float gravity; };
struct JT { char pad0[0xC]; VT *vt; char pad1[0xE8 - 0x10]; PHYS *phys; char pad2[0x248 - 0xEC]; float height; };
extern "C" QW PosLoWorld(void *);
extern "C" int FFindSurfaceAlongUp(float, float, void *, int, int);
static inline float LaneZ(QW q) { QW t; float f; asm("pextuw %0, $0, %1" : "=&r" (t) : "r" (q)); asm("mtc1 %1, %0" : "=f" (f) : "r" (t)); return f; }

int FJtLandsWithin(JT *jt, float dt)
{
    float zStart = jt->height;
    float zero = 0.0f;
    VT *vt = jt->vt;
    float vz = LaneZ(vt->f10C((char *)jt + vt->d108));
    float h = dt * 0.5f;
    float t1 = dt * vz;
    float gravity = jt->phys->gravity;
    float zAhead = zStart + t1 + dt * h * gravity;
    if (zAhead > zero)
        return 0;
    QW pos = PosLoWorld(jt);
    return FFindSurfaceAlongUp(zero, zAhead, &pos, 0, 0);
}
