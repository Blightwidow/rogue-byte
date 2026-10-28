#include "sly2.h"
struct XFM { char pad[0x10]; };
struct ROPE { char pad0[0x10]; void *plo[2]; char pad1[8]; QW anchor[2]; void *xf[2]; void *crv; };
struct VT { char pad[0x100]; short delta; short index; void *(*fn)(void *, void *); };
struct LO { char pad[0xC]; VT *vt; };
extern "C" char D_002C44F0;
extern "C" float UMinCrv(void *);
extern "C" float UMaxCrv(void *);
extern "C" void EvaluateCrvFromU(void *, float, void *, void *);
extern "C" void SetRopeSimEnd(ROPE *rope, int end, LO *plo)
{
    rope->plo[end] = plo;
    if (plo) {
        QW mat[4];
        rope->xf[end] = plo->vt->fn((char *)plo + plo->vt->delta, mat);
        *(QW *)((char *)rope + 0x20 + end * 16) = mat[3];
    } else {
        rope->xf[end] = &D_002C44F0;
        float u;
        if (end == 0) u = UMinCrv(rope->crv);
        else u = UMaxCrv(rope->crv);
        EvaluateCrvFromU(rope->crv, u, &rope->anchor[end], 0);
    }
}
