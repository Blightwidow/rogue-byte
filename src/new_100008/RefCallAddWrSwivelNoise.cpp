#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3F40;
extern "C" void AddWrSwivelNoise(OBJ *, float, float, float, float);

CRef RefCallAddWrSwivelNoise(OBJ *object, int count, CRef *args)
{
    B16 types;
    float a;
    float b;
    float c;
    float d;
    types = RO_002A3F40;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddWrSwivelNoise(object, a,b,c,d);
    return ref;
}
