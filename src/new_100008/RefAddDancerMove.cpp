#include "sly2.h"
#include "cref.h"
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
    Raw20 types;
    CRef ref;
    int a;
    int b;
    int c;
    int d;
    int e;
    types = RO_002A4058;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, &types, &a, &b, &c, &d, &e);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddDancerMove(object, a, b, c, d, e);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
