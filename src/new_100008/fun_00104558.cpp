#include "sly2.h"
#include "cref.h"
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_0020AFF0(BASIC *, int, float, float, float, float);
extern const struct B20 { char b[16]; int w; } RO_002A3BA0;

CRef *func_00104558(CRef *result, BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    CRef ref;
    int a;
    float b;
    float c;
    float d;
    float e;
    aotyp = RO_002A3BA0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, (const int *)&aotyp, &a, &b, &c, &d, &e);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_0020AFF0(object, a, b, c, d, e);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
