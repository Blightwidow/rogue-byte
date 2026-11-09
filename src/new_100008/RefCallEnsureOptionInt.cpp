#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void EnsureOptionInt(BASIC *, int, int);
extern const B8 RO_002A3A38;

CRef *RefCallEnsureOptionInt(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    CRef ref;
    int oid;
    int arg;
    aotyp = RO_002A3A38;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, (const int *)&aotyp, &oid, &arg);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    EnsureOptionInt(object, oid, arg);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
