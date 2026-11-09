#include "sly2.h"
#include "cref.h"
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddProxySnd(BASIC *, int, int, int, float, float);
extern const struct B20 { char b[16]; int w; } RO_002A3A98;

CRef *func_00101768(CRef *result, BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    CRef ref;
    int a;
    int b;
    int c;
    float d;
    float e;
    aotyp = RO_002A3A98;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, (const int *)&aotyp, &a, &b, &c, &d, &e);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddProxySnd(object, a, b, c, d, e);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
