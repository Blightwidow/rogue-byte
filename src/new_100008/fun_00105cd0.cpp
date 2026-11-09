#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void RunGuardScriptIfActor(BASIC *, int);

extern "C" CRef RefRunGuardScriptIfActor(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {8248};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    RunGuardScriptIfActor(object, value);
    return refResult;
}
