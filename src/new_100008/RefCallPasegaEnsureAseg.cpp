#include "sly2.h"
#include "cref.h"
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" BASIC *PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(BASIC *, int, int, float, float, int);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);
extern const struct B20 { char b[16]; int w; } RO_002A3AE0;

CRef *RefCallPasegaEnsureAseg(CRef *result, BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    CRef ref;
    int a;
    int b;
    float d;
    float e;
    int c;
    aotyp = RO_002A3AE0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, (const int *)&aotyp, &a, &b, &d, &e, &c);
    CRef_SetBasic(&ref, PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(object, a, b, d, e, c));
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
