#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void StartMurrayLift(BASIC *, int);

CRef RefCallStartMurrayLift(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {8228};
    int oid;
    RefSetArgsFromSplice(1, args, aotyp, &oid);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    StartMurrayLift(object, oid);
    return refResult;
}
