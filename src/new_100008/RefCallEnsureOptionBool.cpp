#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void EnsureOptionBool(BASIC *, int, int);
extern const B8 RO_002A3A30;

CRef *RefCallEnsureOptionBool(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad[2]; CRef ref; int oid; int arg; } l;
    l.aotyp = RO_002A3A30;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, (const int *)&l.aotyp, &l.oid, &l.arg);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    EnsureOptionBool(object, l.oid, l.arg);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
