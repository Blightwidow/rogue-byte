#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 a; int b; };
struct B16 { B8 a; B8 b; };
extern "C" BASIC *PsmaApplySm(BASIC *, int, int, int);
extern const B12 RO_002A3BC0;
CRef T(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A3BC0;
    CRef ref = RefSetArgsFromSplice(3, args, &aotyp, &a, &b, &c);
    ref.SetBasic(PsmaApplySm(object, a, b, c));
    return ref;
}
