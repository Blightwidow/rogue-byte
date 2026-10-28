#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void RequestTaskState(BASIC *, int, int);
extern const B8 RO_002A4000;

CRef *RefCallRequestTaskState(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad[2]; CRef ref; int first; int second; } l;
    l.aotyp = RO_002A4000;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, (const int *)&l.aotyp, &l.first, &l.second);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    RequestTaskState(object, l.first, l.second);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
