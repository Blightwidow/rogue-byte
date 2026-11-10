#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void SetAsegaPriority__FP5ASEGAi(BASIC *, int);

CRef RefCallSetAsegaPriority(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {5};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    SetAsegaPriority__FP5ASEGAi(object, value);
    return refResult;
}
