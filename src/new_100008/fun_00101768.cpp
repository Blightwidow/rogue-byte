#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddProxySnd(BASIC *, int, int, int, float, float);
extern const struct B20 { char b[16]; int w; } RO_002A3A98;

CRef func_00101768(BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    int a;
    int b;
    int c;
    float d;
    float e;
    aotyp = RO_002A3A98;
    RefSetArgsFromSplice(5, args, (const int *)&aotyp, &a, &b, &c, &d, &e);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddProxySnd(object, a, b, c, d, e);
    return ref;
}
