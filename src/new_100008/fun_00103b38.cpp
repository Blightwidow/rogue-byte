#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void SetGuardRefLists(BASIC *, CRef *, CRef *);
extern const struct B8 { char b[8]; } RO_002A3B70;

CRef *func_00103B38(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad[2]; CRef a; CRef b; CRef ref; } l;
    l.aotyp = RO_002A3B70;
    l.a.tagk = -1;
    l.b.tagk = -1;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, (const int *)&l.aotyp, &l.a, &l.b);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    SetGuardRefLists(object, &l.a, &l.b);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    CRef_Destruct(&l.b);
    CRef_Destruct(&l.a);
    return result;
}
