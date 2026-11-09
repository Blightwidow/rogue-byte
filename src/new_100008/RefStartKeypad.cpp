#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_001C8AF0(BASIC *, BASIC *);

CRef RefStartKeypad(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2034};
    BASIC *thief;
    RefSetArgsFromSplice(1, args, aotyp, &thief);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001C8AF0(object, thief);
    return refResult;
}
