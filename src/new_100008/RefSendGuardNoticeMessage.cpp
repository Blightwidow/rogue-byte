#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_0014B468(BASIC *, int);

extern "C" CRef RefSendGuardNoticeMessage(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x207B};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_0014B468(object, a);
    return refResult;
}
