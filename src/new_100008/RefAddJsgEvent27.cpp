#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3D18;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001E0CB8(BASIC *, int, float, int, int, int, int);

CRef *RefAddJsgEvent27(CRef *result, BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    CRef ref;
    int v0;
    int v1;
    int v2;
    float v3;
    int v4;
    int v5;
    aotyp = RO_002A3D18;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 6, args, &aotyp, &v0, &v1, &v2, &v3, &v4, &v5);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_001E0CB8(object, v0, v3, v1, v2, v4, v5);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
