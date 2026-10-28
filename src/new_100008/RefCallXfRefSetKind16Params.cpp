#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3FC0;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001F8BF0(BASIC *, int, QW, float, float, float, float);

CRef *RefCallXfRefSetKind16Params(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B24 aotyp; int padA[2]; QW vec; CRef ref; int v0; float v1, v2, v3, v4; } l;
    l.aotyp = RO_002A3FC0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 6, args, &l.aotyp, &l.v0, &l.v1, &l.v2, &l.v3, &l.v4, &l.vec);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_001F8BF0(object, l.v0, l.vec, l.v1, l.v2, l.v3, l.v4);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
