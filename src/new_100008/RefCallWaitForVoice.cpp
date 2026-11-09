#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordWaitForVoice(BASIC *, float);

extern "C" CRef RefCallWaitForVoice(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1};
    float a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordWaitForVoice(object, a);
    return refResult;
}
