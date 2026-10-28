#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct EXPL;
struct AOT { int v[6]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(EXPL *, unsigned, int, QW, QW, float, float);
extern const AOT RO_002A3C38;

struct L { AOT aotyp; QW vec; QW origin; CRef refResult; int flags; int palo; float scale; float radius; };

CRef *RefCallExplodeOvr(CRef *result, EXPL *expl, int count, CRef *args)
{
    L l;
    l.aotyp = RO_002A3C38;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.refResult, 6, args, &l.aotyp, &l.flags, &l.palo, &l.vec, &l.origin, &l.scale, &l.radius);
    CRef_Destruct(&l.refResult);
    SetTag__4CRef4TAGK(&l.refResult, 0x24);
    ExplodeExplParams__FP4EXPLUiP3ALOP6VECTORT3ff(expl, l.flags, l.palo, l.vec, l.origin, l.scale, l.radius);
    CRef_CopyConstruct(result, &l.refResult);
    CRef_Destruct(&l.refResult);
    return result;
}
