#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void *CRef_SetVector(CRef *, QW);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" QW PosAimAtPlayer(BASIC *, QW);

struct Frame { QW pos; CRef ref; int aotyp[4]; };
extern "C" CRef *RefPosAimAtPlayer(CRef *result, BASIC *object, int count, CRef *args)
{
    Frame f;
    f.aotyp[0] = 2;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 1, args, f.aotyp, &f.pos);
    CRef_SetVector(&f.ref, PosAimAtPlayer(object, f.pos));
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
