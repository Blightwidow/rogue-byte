#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_00132E40(BASIC *, int);

CRef RefCallEnsureOptionBasicNull(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {21};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00132E40(object, value);
    return refResult;
}
