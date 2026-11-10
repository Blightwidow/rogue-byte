#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void LaunchSoAtTarget(BASIC *, int);

extern "C" CRef RefLaunchSoAtTarget(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {8240};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    LaunchSoAtTarget(object, value);
    return refResult;
}
