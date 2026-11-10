#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void PrimeBomb__FP4BOMBf(BASIC *, float);

extern "C" CRef RefPrimeBomb(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {1};
    float value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    PrimeBomb__FP4BOMBf(object, value);
    return refResult;
}
