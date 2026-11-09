#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void func_0018DE18(BASIC *, int);

CRef func_0010B510(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x2012;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_0018DE18(object, arg);
    return refResult;
}
