#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };

extern "C" void func_001F8AD8(BASIC *, int, int, void *);
extern const B8 RO_002A3FA0;

CRef RefCallXfRefSetGoalEulerWorld(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int mat[16];
    int a;
    int b;
    aotyp = RO_002A3FA0;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, mat);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001F8AD8(object, a, b, mat);
    return ref;
}
