#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void func_0012FDE8(BASIC *, int, float, float);
extern const struct B12 { int w[3]; } RO_002A3AD0;

CRef func_001019D0(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    float a;
    float b;
    int c;
    aotyp = RO_002A3AD0;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_0012FDE8(object, c, a, b);
    return ref;
}
