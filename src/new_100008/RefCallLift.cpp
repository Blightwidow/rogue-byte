#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3E78;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordLift(BASIC *, int, int, int, int, int, int);

CRef *RefCallLift(CRef *result, BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    CRef ref;
    int v0, v1, v2, v3, v4, v5;
    aotyp = RO_002A3E78;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 6, args, &aotyp, &v0, &v1, &v2, &v3, &v4, &v5);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddSeqRecordLift(object, v0, v1, v2, v3, v4, v5);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
