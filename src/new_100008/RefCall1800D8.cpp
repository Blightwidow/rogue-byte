#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };
extern "C" void Mount_SetStateAnim(BASIC *, int, int, int);
extern const B8 RO_002A4078;

CRef RefCall1800D8(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A4078;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    Mount_SetStateAnim(object, a, b, c);
    return ref;
}
