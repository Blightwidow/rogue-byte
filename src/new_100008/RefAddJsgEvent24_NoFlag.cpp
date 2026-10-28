#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3D00;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001E0C08(BASIC *, int, float, float, int, int, int);

CRef *RefAddJsgEvent24_NoFlag(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B24 aotyp; int padA[2]; CRef ref; int v0; float v1; float v2; int v3; int v4; int v5; } l;
    l.aotyp = RO_002A3D00;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 6, args, &l.aotyp, &l.v0, &l.v1, &l.v2, &l.v3, &l.v4, &l.v5);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    func_001E0C08(object, l.v0, l.v1, l.v2, l.v3, l.v4, l.v5);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
