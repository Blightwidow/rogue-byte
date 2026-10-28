#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3CD0;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordDamage(BASIC *, int, int, int, int);

CRef *RefCallDamage(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B16 aotyp; CRef ref; int v0; int v1; int v2; int v3; } l;
    l.aotyp = RO_002A3CD0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, &l.aotyp, &l.v0, &l.v1, &l.v2, &l.v3);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordDamage(object, l.v0, l.v1, l.v2, l.v3);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
