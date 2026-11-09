#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddTrigBombCid(BASIC *, int);

extern "C" CRef RefAddTrigBombCid(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {7};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddTrigBombCid(object, value);
    return refResult;
}
