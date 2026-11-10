#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void JumpGuardScript(BASIC *, int);

extern "C" CRef RefJumpGuardScript(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    JumpGuardScript(object, a);
    return refResult;
}
