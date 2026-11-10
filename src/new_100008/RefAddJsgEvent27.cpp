#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3D18;
extern "C" void func_001E0CB8(BASIC *, int, float, int, int, int, int);

CRef RefAddJsgEvent27(BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    int v0;
    int v1;
    int v2;
    float v3;
    int v4;
    int v5;
    aotyp = RO_002A3D18;
    RefSetArgsFromSplice(6, args, &aotyp, &v0, &v1, &v2, &v3, &v4, &v5);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001E0CB8(object, v0, v3, v1, v2, v4, v5);
    return ref;
}
