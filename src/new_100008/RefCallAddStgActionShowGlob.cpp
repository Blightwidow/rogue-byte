#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddStgActionShowGlob(BASIC *, int);

CRef func_0010CBE8(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {6};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddStgActionShowGlob(object, value);
    return refResult;
}
