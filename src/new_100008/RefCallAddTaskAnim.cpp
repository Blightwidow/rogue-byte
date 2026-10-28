#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
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
    struct L { B24 aotyp; int pad[2]; CRef ref; int a; int b; int c; int d; int e; int f; } l;
    l.aotyp = RO_002A4018;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 6, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c, &l.d, &l.e, &l.f);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddTaskAnim(object, l.a, l.b, l.c, l.d, l.e, l.f);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
