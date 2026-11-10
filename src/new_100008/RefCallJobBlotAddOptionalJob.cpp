#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void JobBlot_AddOptionalJob(BASIC *, int);

CRef RefCallJobBlotAddOptionalJob(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x6};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    JobBlot_AddOptionalJob(object, value);
    return refResult;
}
