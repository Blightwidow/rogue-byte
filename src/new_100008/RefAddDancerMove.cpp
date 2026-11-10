#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct Raw20 { B8 x; B8 y; int z; };
extern "C" void AddDancerMove(BASIC *, int, int, int, int, int);
extern "C" const Raw20 RO_002A4058;

CRef RefAddDancerMove(BASIC *object, int count, CRef *args)
{
    Raw20 types;
    int a;
    int b;
    int c;
    int d;
    int e;
    types = RO_002A4058;
    RefSetArgsFromSplice(5, args, &types, &a, &b, &c, &d, &e);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddDancerMove(object, a, b, c, d, e);
    return ref;
}
