#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 x; int y; };
struct RANGE { float v[4]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void Chaser_SetStateAnim(BASIC *, int, int, int);
extern const B12 RO_002A4088;

CRef *RefChaser_SetStateAnim(CRef *result, BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    CRef ref;
    int a;
    int b;
    int c;
    aotyp = RO_002A4088;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &a, &b, &c);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    Chaser_SetStateAnim(object, a, b, c);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
