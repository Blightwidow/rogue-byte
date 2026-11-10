#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B24 { char b[8]; char c[8]; char d[8]; };
extern "C" void AddTaskAnim(BASIC *, int, int, int, int, int, int);
extern const B24 RO_002A4018;

CRef RefCallAddTaskAnim(BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    aotyp = RO_002A4018;
    RefSetArgsFromSplice(6, args, (const int *)&aotyp, &a, &b, &c, &d, &e, &f);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddTaskAnim(object, a, b, c, d, e, f);
    return ref;
}
