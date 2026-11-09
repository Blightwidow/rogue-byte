#include "sly2.h"
#include "cref.h"
struct OBJ;
struct B8 { char b[8]; };
struct B20 { B8 a; B8 b; int c; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" const B20 RO_002A3FE8;
extern "C" void AddJobAnim(OBJ *, int, int, int, int, int);

CRef *RefCallAddJobAnim(CRef *result, OBJ *object, int count, CRef *args)
{
    B20 types;
    CRef ref;
    int a;
    int b;
    int c;
    int d;
    int e;
    types = RO_002A3FE8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, (const int *)&types, &a, &b, &c, &d, &e);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddJobAnim(object, a, b, c, d, e);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
