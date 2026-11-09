#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void EnsureSggAlarm__FP3SGGP5ALARM(BASIC *, int);

CRef func_00106800(BASIC *object, int count, CRef *args)
{
    int aotyp = 6;
    int value;
    RefSetArgsFromSplice(1, args, &aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    EnsureSggAlarm__FP3SGGP5ALARM(object, value);
    return refResult;
}
