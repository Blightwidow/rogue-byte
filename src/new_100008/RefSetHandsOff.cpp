#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void SetHandsOff(BASIC *, int);

CRef func_0010C1D8(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1058};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    SetHandsOff(object, value);
    return refResult;
}
