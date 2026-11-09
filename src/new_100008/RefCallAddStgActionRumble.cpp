#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddStgActionRumble(BASIC *, int);

CRef func_0010CAD8(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1003};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddStgActionRumble(object, value);
    return refResult;
}
