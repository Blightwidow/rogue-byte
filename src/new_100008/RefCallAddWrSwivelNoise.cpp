#include "sly2.h"
#include "cref.h"
struct OBJ;
struct B16 { char b[16]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" const B16 RO_002A3F40;
extern "C" void AddWrSwivelNoise(OBJ *, float, float, float, float);

CRef *RefCallAddWrSwivelNoise(CRef *result, OBJ *object, int count, CRef *args)
{
    B16 types;
    CRef ref;
    float a;
    float b;
    float c;
    float d;
    types = RO_002A3F40;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, (const int *)&types, &a, &b, &c, &d);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddWrSwivelNoise(object, a,b,c,d);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
