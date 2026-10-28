#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
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
    struct L { B20 types; int pad4[3]; CRef ref; int a; int b; int c; int d; int e; } l;
    l.types = RO_002A3FE8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, (const int *)&l.types, &l.a, &l.b, &l.c, &l.d, &l.e);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddJobAnim(object, l.a, l.b, l.c, l.d, l.e);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
