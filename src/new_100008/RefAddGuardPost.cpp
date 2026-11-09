#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A4048;
extern "C" void AddGuardPost(OBJ *, int, int, int, int);

CRef RefAddGuardPost(OBJ *object, int count, CRef *args)
{
    B16 types;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A4048;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddGuardPost(object, a,b,c,d);
    return ref;
}
