#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);

struct Raw12 { B8 x; int z; };
extern "C" void Chaser_SetStateAngleRanges(BASIC *, int, void *, void *);
extern "C" const Raw12 RO_002A4098;

CRef *RefChaser_SetStateAngleRanges(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw12 types;
    char v1[16];
    char v2[16];
    CRef ref;
    int a;
    types = RO_002A4098;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, &types, &a, v1, v2);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    Chaser_SetStateAngleRanges(object, a, v1, v2);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
