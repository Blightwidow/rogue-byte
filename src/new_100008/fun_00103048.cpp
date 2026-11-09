#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void func_00208038(BASIC *, int, int, int);
extern const struct B12 { int w[3]; } RO_002A3B60;

CRef func_00103048(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A3B60;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_00208038(object, a, b, c);
    return ref;
}
