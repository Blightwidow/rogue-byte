#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { int w[3]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordAddObject(BASIC *, float, int, int);
extern "C" const B8 RO_002A3D78;

CRef *RefCallAddObject(CRef *result, BASIC *obj, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    int a;
    float b;
    int c;
    aotyp = RO_002A3D78;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &a, &b, &c);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddSeqRecordAddObject(obj,b,a,c);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
