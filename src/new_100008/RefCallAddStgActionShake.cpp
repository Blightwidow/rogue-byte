#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddStgActionShake(BASIC *, int);

CRef func_0010CA50(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1004};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddStgActionShake(object, value);
    return refResult;
}
