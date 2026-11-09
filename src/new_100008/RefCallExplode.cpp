#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3DA0;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordExplode(BASIC *, int, int, int, float);

CRef *RefCallExplode(CRef *result, BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    CRef ref;
    int v0;
    int v1;
    int v2;
    float v3;
    aotyp = RO_002A3DA0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, &aotyp, &v0, &v1, &v2, &v3);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddSeqRecordExplode(object, v0, v1, v2, v3);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
