#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordApplyMusic(BASIC *, int);

extern "C" CRef RefCallApplyMusic(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x13};
    int a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordApplyMusic(object, a);
    return refResult;
}
