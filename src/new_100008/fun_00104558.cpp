#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_0020AFF0(BASIC *, int, float, float, float, float);
extern const struct B20 { char b[16]; int w; } RO_002A3BA0;

CRef func_00104558(BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    int a;
    float b;
    float c;
    float d;
    float e;
    aotyp = RO_002A3BA0;
    RefSetArgsFromSplice(5, args, (const int *)&aotyp, &a, &b, &c, &d, &e);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_0020AFF0(object, a, b, c, d, e);
    return ref;
}
