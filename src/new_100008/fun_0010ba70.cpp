#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct OBJ;
struct B16 { char b[16]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" const B16 RO_002A3BF8;
extern "C" void Spawn_AddRsmg(OBJ *, int, int, int, int);

CRef *func_0010BA70(CRef *result, OBJ *object, int count, CRef *args)
{
    struct L { B16 types; CRef ref; int a; int b; int c; int d; } l;
    l.types = RO_002A3BF8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, (const int *)&l.types, &l.a, &l.b, &l.c, &l.d);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    Spawn_AddRsmg(object, l.a,l.b,l.c,l.d);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
