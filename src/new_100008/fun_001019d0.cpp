#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_0012FDE8(BASIC *, int, float, float);
extern const struct B12 { int w[3]; } RO_002A3AD0;

CRef *func_001019D0(CRef *result, BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    CRef ref;
    float a;
    float b;
    int c;
    aotyp = RO_002A3AD0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &a, &b, &c);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_0012FDE8(object, c, a, b);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
