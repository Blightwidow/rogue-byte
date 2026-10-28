#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void SetButtonRsmg(BASIC *, int, int, int, int);
extern const struct B16 { char b[16]; } RO_002A3BF8;

CRef *func_00105090(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B16 aotyp; CRef ref; int a; int b; int c; int d; } l;
    l.aotyp = RO_002A3BF8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c, &l.d);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    SetButtonRsmg(object, l.a, l.b, l.c, l.d);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
