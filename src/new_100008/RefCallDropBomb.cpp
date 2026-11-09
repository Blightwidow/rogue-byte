#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordDropBomb(BASIC *, int);

extern "C" CRef RefCallDropBomb(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordDropBomb(object, a);
    return refResult;
}
