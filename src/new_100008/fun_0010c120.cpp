#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };

extern "C" void func_001FF108(BASIC *, int, float, int);
extern const B8 RO_002A3F30;

CRef func_0010C120(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int a;
    float b;
    int c;
    aotyp = RO_002A3F30;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001FF108(object, a, b, c);
    return ref;
}
