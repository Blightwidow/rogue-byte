#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_00213928(BASIC *, int);

CRef RefCallRewindBlotLabel(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00213928(object, value);
    return refResult;
}
