#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
typedef int QW __attribute__((mode(TI)));
struct B8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const B8 *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" BASIC *PhitfxSpawn(BASIC *, QW, int);
extern const B8 RO_002A3F68;

CRef *RefCallPhitfxSpawn(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; QW vec; CRef ref; int arg; } l;
    l.aotyp = RO_002A3F68;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, &l.aotyp, &l.vec, &l.arg);
    BASIC *spawned = PhitfxSpawn(object, l.vec, l.arg);
    CRef_SetBasic(&l.ref, spawned);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
