#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void StartMurrayThrow(BASIC *, int);

CRef RefCallStartMurrayThrow(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {8194};
    int oid;
    RefSetArgsFromSplice(1, args, aotyp, &oid);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    StartMurrayThrow(object, oid);
    return refResult;
}
