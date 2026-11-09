#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_001F6B48(BASIC *, int);

CRef RefCallDisableAloPart(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {6};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001F6B48(object, value);
    return refResult;
}
