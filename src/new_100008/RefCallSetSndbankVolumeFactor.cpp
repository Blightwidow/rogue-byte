#include "sly2.h"
#include "cref.h"
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3B10;
extern "C" void SetSndbankVolumeFactor(BASIC *, int, int, float);
CRef *RefCallSetSndbankVolumeFactor(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw8 types;
    CRef ref;
    int first;
    float second;
    types = RO_002A3B10;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, &types, &first, &second);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    SetSndbankVolumeFactor(object, first, 0, second);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
