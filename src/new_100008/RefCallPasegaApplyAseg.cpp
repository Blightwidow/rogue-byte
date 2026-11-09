#include "sly2.h"
#include "cref.h"
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
    B16 aotyp;
    CRef ref;
    int oid;
    float a;
    float b;
    int c;
    aotyp = RO_002A3AC0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, (const int *)&aotyp, &oid, &a, &b, &c);
    CRef_SetBasic(&ref, PasegaApplyAseg(object, oid, a, b, c));
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
