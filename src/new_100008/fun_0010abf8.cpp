#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void func_001421A0(BASIC *, int);

CRef func_0010ABF8(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x2030;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    func_001421A0(object, arg);
    return refResult;
}
