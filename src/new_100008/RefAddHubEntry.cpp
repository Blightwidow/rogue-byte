#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };
extern "C" void AddHubEntry(BASIC *, int, int, int);
extern const B8 RO_002A4038;

CRef RefAddHubEntry(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A4038;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddHubEntry(object, a, b, c);
    return ref;
}
