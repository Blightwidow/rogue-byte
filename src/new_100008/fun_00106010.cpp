#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddScriptPause(BASIC *, float);

CRef func_00106010(BASIC *object, int count, CRef *args)
{
    int aotyp = 1;
    float value;
    RefSetArgsFromSplice(1, args, &aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddScriptPause(object, value);
    return refResult;
}
