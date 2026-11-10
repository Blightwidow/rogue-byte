#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void LockLeaseOfPlo(BASIC *, int);

extern "C" CRef RefCallLockLeaseOfPlo(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2002};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    LockLeaseOfPlo(object, a);
    return refResult;
}
