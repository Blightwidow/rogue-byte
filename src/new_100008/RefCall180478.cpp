#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_00180478(BASIC *, int);

extern "C" CRef RefCall180478(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2030};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00180478(object, a);
    return refResult;
}
