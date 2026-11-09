#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B24 { char b[8]; char c[8]; char d[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddTaskAnim(BASIC *, int, int, int, int, int, int);
extern const B24 RO_002A4018;

CRef *RefCallAddTaskAnim(CRef *result, BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    CRef ref;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    aotyp = RO_002A4018;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 6, args, (const int *)&aotyp, &a, &b, &c, &d, &e, &f);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddTaskAnim(object, a, b, c, d, e, f);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
