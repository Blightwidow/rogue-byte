#include "types.h"
struct ALO_15C198;
struct EXPLP_15C198 {
    unsigned grfexpl;
    ALO_15C198 *palo;
    float r1;
    float r2;
    QW pos;
    QW normal;
    QW unk0x30;
};
struct VTable_15C198 { char pad[0x198]; short delta; short index; void (*fn)(void *, EXPLP_15C198 *); };
struct EXPL_15C198 { char pad[0xC]; VTable_15C198 *vtable; };
extern "C" void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(EXPL_15C198 *pexpl, unsigned grfexpl, ALO_15C198 *palo,
                                                               QW pos, QW normal, float r1, float r2)
{
    EXPLP_15C198 params;
    params.grfexpl = grfexpl;
    params.palo = palo;
    params.r1 = r1;
    params.r2 = r2;
    params.pos = pos;
    params.normal = normal;
    VTable_15C198 *vtable = pexpl->vtable;
    vtable->fn((char *)pexpl + vtable->delta, &params);
}
