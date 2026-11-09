#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3C70;
struct OID { int a; };
extern "C" void UseStepguardDeathAnimation__FP9STEPGUARDi3OID(BASIC *, int, int);
CRef RefUseStepguardDeathAnimation(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3C70;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    UseStepguardDeathAnimation__FP9STEPGUARDi3OID(object, a, b);
    return ref;
}
