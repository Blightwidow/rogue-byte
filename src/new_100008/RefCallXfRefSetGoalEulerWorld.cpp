#include "sly2.h"
#include "cref.h"
struct BASIC;
struct B8 { int w[3]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);

extern "C" void func_001F8AD8(BASIC *, int, int, void *);
extern const B8 RO_002A3FA0;

CRef *RefCallXfRefSetGoalEulerWorld(CRef *result, BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int mat[16];
    CRef ref;
    int a;
    int b;
    aotyp = RO_002A3FA0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 3, args, (const int *)&aotyp, &a, &b, mat);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_001F8AD8(object, a, b, mat);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
