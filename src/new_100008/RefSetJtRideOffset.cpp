#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
typedef int QW __attribute__((mode(TI)));
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void SetJtRideOffset(BASIC *, QW);

CRef *RefSetJtRideOffset(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { QW vec; CRef ref; int aotyp[1]; } l;
    l.aotyp[0] = 2;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 1, args, l.aotyp, &l.vec);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    SetJtRideOffset(object, l.vec);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
