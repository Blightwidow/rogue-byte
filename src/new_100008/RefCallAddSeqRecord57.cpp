#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void func_001E1A60(BASIC *, int);

extern "C" CRef RefCallAddSeqRecord57(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int a;
    RefSetArgsFromSplice(1, args, (const AOT *)aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001E1A60(object, a);
    return refResult;
}
