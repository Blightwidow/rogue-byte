#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void SetVolbtnRsmg(BASIC *, int, int, int, int);
extern const struct B16 { char b[16]; } RO_002A3BF8;

CRef func_00105440(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int a;
    int b;
    int c;
    int d;
    aotyp = RO_002A3BF8;
    RefSetArgsFromSplice(4, args, (const int *)&aotyp, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    SetVolbtnRsmg(object, a, b, c, d);
    return ref;
}
