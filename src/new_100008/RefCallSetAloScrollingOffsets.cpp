#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001F8038(BASIC *, float, float);
extern const B8 RO_002A3A80;

CRef *RefCallSetAloScrollingOffsets(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    float a;
    float b;
    aotyp = RO_002A3A80;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, (const int *)&aotyp, &a, &b);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_001F8038(object, a, b);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
