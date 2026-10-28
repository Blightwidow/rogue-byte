#include "sly2.h"
struct VT { char pad[0xF8]; short delta; short index; float *(*fn)(void *); };
struct LO { char pad[0xC]; VT *vptr; };
extern "C" int FIsBasicDerivedFrom(void *, int);
extern "C" void FindCrvClosestPointAll(void *, QW, void *, void *, void *, void *, void *);
extern "C" QW PosLoWorld(void *);
extern "C" float atan2f(float, float);
extern "C" void GetScriptPose(void *pscript, QW posFrom, LO *plo, QW *ppos, float *prad)
{
    struct { QW pos; float normal[4]; } l;
    float rad;
    if (plo != 0) {
        if (FIsBasicDerivedFrom(plo, 10)) {
            FindCrvClosestPointAll(plo, posFrom, 0, &l.pos, l.normal, 0, 0);
            rad = atan2f(l.normal[1], l.normal[0]);
        } else {
            l.pos = PosLoWorld(plo);
            float *first = plo->vptr->fn((char *)plo + plo->vptr->delta);
            rad = atan2f(first[1], *plo->vptr->fn((char *)plo + plo->vptr->delta));
        }
    } else {
        l.pos = posFrom;
        rad = 0.0f;
    }
    if (ppos != 0)
        *ppos = l.pos;
    if (prad != 0)
        *prad = rad;
}
