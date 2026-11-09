#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3D00;
extern "C" void func_001E0B90(BASIC *, int, float, float, int, int, int);

CRef RefAddJsgEvent24_Flag(BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    int v0;
    float v1;
    float v2;
    int v3;
    int v4;
    int v5;
    aotyp = RO_002A3D00;
    RefSetArgsFromSplice(6, args, &aotyp, &v0, &v1, &v2, &v3, &v4, &v5);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001E0B90(object, v0, v1, v2, v3, v4, v5);
    return ref;
}
