#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 x; int y; };
struct RANGE { float v[4]; };
extern "C" void func_001816C0(BASIC *, int, int, int);
extern const B12 RO_002A40A8;

CRef RefGrab_SetStateAnim(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A40A8;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001816C0(object, a, b, c);
    return ref;
}
