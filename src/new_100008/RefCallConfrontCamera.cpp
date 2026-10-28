#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
struct B20 { B8 x; B8 y; int z; };
extern "C" const B20 RO_002A3DE0;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordConfrontCamera(BASIC *, QW, QW, float, float, int);

CRef *RefCallConfrontCamera(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B20 aotyp; int pad[3]; QW v0; QW v1; CRef ref; float v2; float v3; int v4; } l;
    l.aotyp = RO_002A3DE0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, &l.aotyp, &l.v0, &l.v1, &l.v2, &l.v3, &l.v4);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordConfrontCamera(object, l.v0, l.v1, l.v2, l.v3, l.v4);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
