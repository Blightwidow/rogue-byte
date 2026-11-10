#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };

struct Raw16 { B8 x; B8 y; };
extern "C" void func_001816E8(BASIC *, int, int, int, int);
extern "C" const Raw16 RO_002A3BF8;

CRef RefGrab_FAddRsmg(BASIC *object, int count, CRef *args)
{
    Raw16 types;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A3BF8;
    RefSetArgsFromSplice(4, args, &types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001816E8(object, a, b, c, d);
    return ref;
}
