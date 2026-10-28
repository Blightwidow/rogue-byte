#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" BASIC *PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(BASIC *, int, int, float, float, int);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);
extern const struct B20 { char b[16]; int w; } RO_002A3AE0;

CRef *RefCallPasegaEnsureAseg(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B20 aotyp; int pad[3]; CRef ref; int a; int b; float d; float e; int c; } l;
    l.aotyp = RO_002A3AE0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, (const int *)&l.aotyp, &l.a, &l.b, &l.d, &l.e, &l.c);
    CRef_SetBasic(&l.ref, PasegaEnsureAseg__FP4ASEGP3ALO4SEEKffi(object, l.a, l.b, l.d, l.e, l.c));
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
