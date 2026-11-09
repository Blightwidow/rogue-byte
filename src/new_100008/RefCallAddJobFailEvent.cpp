#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddJobFailEvent(BASIC *, int);

extern "C" CRef RefCallAddJobFailEvent(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x104E};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddJobFailEvent(object, a);
    return refResult;
}
