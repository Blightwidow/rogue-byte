#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void func_00170BE0(BASIC *, int);

extern "C" CRef RefFunc170BE0(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {6};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_00170BE0(object, value);
    return refResult;
}
