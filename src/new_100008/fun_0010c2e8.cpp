#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_00195608(BASIC *, int);

CRef func_0010C2E8(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2002};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00195608(object, value);
    return refResult;
}
