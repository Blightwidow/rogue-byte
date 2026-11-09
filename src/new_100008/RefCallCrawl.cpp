#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
struct B20 { B8 x; B8 y; int z; };
extern "C" const B20 RO_002A3D48;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordCrawl(BASIC *, int, float, float, int, int);

CRef *RefCallCrawl(CRef *result, BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    CRef ref;
    int v0;
    float v1;
    float v2;
    int v3;
    int v4;
    aotyp = RO_002A3D48;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 5, args, &aotyp, &v0, &v1, &v2, &v3, &v4);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddSeqRecordCrawl(object, v0, v1, v2, v3, v4);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
