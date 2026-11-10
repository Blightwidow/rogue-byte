#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_001BA980(BASIC *, int);

CRef RefCallSetGuardScriptCommand(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2071};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001BA980(object, value);
    return refResult;
}
