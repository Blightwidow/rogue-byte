#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddStgActionSound(BASIC *, int);

CRef func_0010CB60(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {5};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddStgActionSound(object, value);
    return refResult;
}
