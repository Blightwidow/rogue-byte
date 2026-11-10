#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void ClearHandsOff(BASIC *, int);

CRef func_0010C260(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1058};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    ClearHandsOff(object, value);
    return refResult;
}
