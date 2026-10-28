#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_0020B060(BASIC *, int, float, float, float, float);
extern const struct B20 { char b[16]; int w; } RO_002A3BA0;

CRef *func_00104638(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B20 aotyp; int pad[3]; CRef ref; int a; float b; float c; float d; float e; } l;
    l.aotyp = RO_002A3BA0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c, &l.d, &l.e);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_0020B060(object, l.a, l.b, l.c, l.d, l.e);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
