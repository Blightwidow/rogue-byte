#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void PauseEmitter__FP7EMITTERf(BASIC *, float);

extern "C" CRef RefPauseEmitter(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {1};
    float value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    PauseEmitter__FP7EMITTERf(object, value);
    return refResult;
}
