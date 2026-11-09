#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B8 { char b[8]; };
struct B20 { B8 a; B8 b; int c; };
extern "C" const B20 RO_002A3FE8;
extern "C" void AddJobAnim(OBJ *, int, int, int, int, int);

CRef RefCallAddJobAnim(OBJ *object, int count, CRef *args)
{
    B20 types;
    int a;
    int b;
    int c;
    int d;
    int e;
    types = RO_002A3FE8;
    RefSetArgsFromSplice(5, args, (const int *)&types, &a, &b, &c, &d, &e);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddJobAnim(object, a, b, c, d, e);
    return ref;
}
