#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_001E0070(BASIC *, int);

CRef func_00106888(BASIC *object, int count, CRef *args)
{
    int aotyp = 6;
    int value;
    RefSetArgsFromSplice(1, args, &aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001E0070(object, value);
    return refResult;
}
