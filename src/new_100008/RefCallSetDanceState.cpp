#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordSetDanceState(BASIC *, int);

extern "C" CRef RefCallSetDanceState(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1059};
    int a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordSetDanceState(object, a);
    return refResult;
}
