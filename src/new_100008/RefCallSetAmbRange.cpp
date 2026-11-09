#include "sly2.h"
#include "cref.h"
struct BASIC;
struct SCROLLER;
struct Raw8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3A80;
extern "C" void SetAmbRange(BASIC *, float, float);
CRef *RefCallSetAmbRange(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw8 types;
    CRef ref;
    float first;
    float second;
    types = RO_002A3A80;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, &types, &first, &second);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    SetAmbRange(object, first, second);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
