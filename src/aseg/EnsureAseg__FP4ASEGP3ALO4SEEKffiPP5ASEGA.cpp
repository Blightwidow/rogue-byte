#include "sly2.h"
struct ASEG;
struct ALO;
struct ASEGA;
extern "C" ASEGA *PasegaFindAseg__FP4ASEGP3ALO(ASEG *, ALO *);
extern "C" void ApplyAseg(ASEG *, ALO *, int, float, float, ASEGA **);
extern "C" void SeekAsega(ASEGA *, int, float, float);

extern "C" void EnsureAseg__FP4ASEGP3ALO4SEEKffiPP5ASEGA(ASEG *paseg, ALO *paloRoot, int seek, float t, float svt, int grfapl, ASEGA **ppasega)
{
    ASEGA *pasegaLocal;
    ASEGA **ppasegaOut = ppasega ? ppasega : &pasegaLocal;
    pasegaLocal = PasegaFindAseg__FP4ASEGP3ALO(paseg, paloRoot);
    if (pasegaLocal != 0)
        *ppasegaOut = pasegaLocal;
    else
        ApplyAseg(paseg, paloRoot, grfapl, 0.0f, 1.0f, ppasegaOut);
    SeekAsega(*ppasegaOut, seek, t, svt);
}
