#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void ClearHudLabel(BASIC *, int);

extern "C" CRef RefClearHudLabel(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x10};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    ClearHudLabel(object, a);
    return refResult;
}
