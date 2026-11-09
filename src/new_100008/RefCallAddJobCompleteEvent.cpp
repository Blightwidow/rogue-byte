#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddJobCompleteEvent(BASIC *, int);

extern "C" CRef RefCallAddJobCompleteEvent(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x104E};
    int a;
    RefSetArgsFromSplice(1, args, aotyp, &a);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddJobCompleteEvent(object, a);
    return refResult;
}
