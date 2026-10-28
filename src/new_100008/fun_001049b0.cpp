#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 a; int b; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001F0128(BASIC *, int, int, int);
extern const B12 RO_002A3BE0;

CRef *Thunk_1049B0(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B12 aotyp; int pad; CRef ref; int a; int b; int c; } l;
    l.aotyp = RO_002A3BE0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_001F0128(object, l.a, l.b, l.c);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
