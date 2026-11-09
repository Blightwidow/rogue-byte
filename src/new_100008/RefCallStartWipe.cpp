#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void StartWipe(BASIC *, int, int);
extern const B8 RO_002A3F88;

CRef *RefCallStartWipe(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    int first;
    int second;
    aotyp = RO_002A3F88;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, (const int *)&aotyp, &first, &second);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    StartWipe(object, first, second);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
