#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 a; int b; };
struct B16 { B8 a; B8 b; };
extern "C" BASIC *PsmaApplySmEx(BASIC *, int, int, int, int);
extern const B16 RO_002A3BD0;
CRef T(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int a;
    int b;
    int c;
    int d;
    aotyp = RO_002A3BD0;
    CRef ref = RefSetArgsFromSplice(4, args, &aotyp, &a, &b, &c, &d);
    ref.SetBasic(PsmaApplySmEx(object, a, b, c, d));
    return ref;
}
