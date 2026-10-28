#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
struct Raw20 { B8 x; B8 y; int z; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddDancerMove(BASIC *, int, int, int, int, int);
extern "C" const Raw20 RO_002A4058;

CRef *RefAddDancerMove(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { Raw20 types; int pad[3]; CRef ref; int a; int b; int c; int d; int e; } l;
    l.types = RO_002A4058;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, &l.types, &l.a, &l.b, &l.c, &l.d, &l.e);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddDancerMove(object, l.a, l.b, l.c, l.d, l.e);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
