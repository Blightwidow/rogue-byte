#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void DequeueStream(BASIC *, int);

CRef RefCallDequeueStream(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {19};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    DequeueStream(object, value);
    return refResult;
}
