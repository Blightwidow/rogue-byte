#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void StartJsg(BASIC *, int);

CRef func_00106688(BASIC *object, int count, CRef *args)
{
    int aotyp = 8194;
    int value;
    RefSetArgsFromSplice(1, args, &aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    StartJsg(object, value);
    return refResult;
}
