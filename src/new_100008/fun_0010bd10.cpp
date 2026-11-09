#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; int w; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001C64F8(BASIC *, int, int, int);
extern const B8 RO_002A3B88;

CRef *func_0010BD10(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    int a;
    int b;
    int c;
    aotyp = RO_002A3B88;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &a, &b, &c);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_001C64F8(object, a, b, c);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
