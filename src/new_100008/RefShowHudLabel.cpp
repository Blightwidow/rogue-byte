#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void ShowHudLabel(BASIC *, int, float);
extern const B8 RO_002A4030;

CRef *RefShowHudLabel(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    int first;
    float second;
    aotyp = RO_002A4030;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, (const int *)&aotyp, &first, &second);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    ShowHudLabel(object, first, second);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
