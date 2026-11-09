#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddBarrierClass(BASIC *, int);

extern "C" CRef RefAddBarrierClass(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {7};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddBarrierClass(object, value);
    return refResult;
}
