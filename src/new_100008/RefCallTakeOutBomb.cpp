#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordTakeOutBomb(BASIC *, int);

extern "C" CRef RefCallTakeOutBomb(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordTakeOutBomb(object, a);
    return refResult;
}
