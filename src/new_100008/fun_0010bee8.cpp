#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void func_001C7A10(BASIC *, int);

CRef func_0010BEE8(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 6;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001C7A10(object, arg);
    return refResult;
}
