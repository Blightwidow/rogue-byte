#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 a; int b; };
struct B16 { B8 a; B8 b; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" CRef * CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern "C" CRef * CRef_SetBasic(CRef *, BASIC *);
extern "C" BASIC *PsmaApplySmEx(BASIC *, int, int, int, int);
extern const B16 RO_002A3BD0;
CRef *T(CRef *result, BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    CRef ref;
    int a;
    int b;
    int c;
    int d;
    aotyp = RO_002A3BD0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, (const int *)&aotyp, &a, &b, &c, &d);
    CRef_SetBasic(&ref, PsmaApplySmEx(object, a, b, c, d));
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
