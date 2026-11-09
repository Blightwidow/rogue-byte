#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3FD8;
extern "C" void AddJobToggle(OBJ *, int, int, int, int);

CRef RefCallAddJobToggle(OBJ *object, int count, CRef *args)
{
    B16 types;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A3FD8;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddJobToggle(object, a,b,c,d);
    return ref;
}
