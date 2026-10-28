#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" BASIC *PasegaApplyAseg(BASIC *, int, float, float, int);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);
extern const struct B16 { char b[16]; } RO_002A3AC0;

CRef *RefCallPasegaApplyAseg(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B16 aotyp; CRef ref; int oid; float a; float b; int c; } l;
    l.aotyp = RO_002A3AC0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, (const int *)&l.aotyp, &l.oid, &l.a, &l.b, &l.c);
    CRef_SetBasic(&l.ref, PasegaApplyAseg(object, l.oid, l.a, l.b, l.c));
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
