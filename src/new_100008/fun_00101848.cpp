#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddProxySlotSource(BASIC *, int, int, int, float);
extern const struct B16 { char b[16]; } RO_002A3AB0;

CRef func_00101848(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int a;
    int b;
    int c;
    float d;
    aotyp = RO_002A3AB0;
    RefSetArgsFromSplice(4, args, (const int *)&aotyp, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddProxySlotSource(object, a, b, c, d);
    return ref;
}
