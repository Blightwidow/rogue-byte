#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3E40;
extern "C" void func_001E15B0(BASIC *, int, int);
CRef RefCallAddJsgKind43(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3E40;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001E15B0(object, a, b);
    return ref;
}
