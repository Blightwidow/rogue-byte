#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);

struct Raw16 { B8 x; B8 y; };
extern "C" void func_001816E8(BASIC *, int, int, int, int);
extern "C" const Raw16 RO_002A3BF8;

CRef *RefGrab_FAddRsmg(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { Raw16 types; CRef ref; int a; int b; int c; int d; } l;
    l.types = RO_002A3BF8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, &l.types, &l.a, &l.b, &l.c, &l.d);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_001816E8(object, l.a, l.b, l.c, l.d);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
