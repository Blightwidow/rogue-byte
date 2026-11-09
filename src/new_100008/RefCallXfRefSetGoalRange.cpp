#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3FB0;
extern "C" void func_001F8B58(OBJ *, int, int, float, float);

CRef RefCallXfRefSetGoalRange(OBJ *object, int count, CRef *args)
{
    B16 types;
    int a;
    int b;
    float c;
    float d;
    types = RO_002A3FB0;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001F8B58(object, a,b,c,d);
    return ref;
}
