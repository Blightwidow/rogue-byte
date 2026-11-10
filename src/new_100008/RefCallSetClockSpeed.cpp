#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddSeqRecordSetClockSpeed(BASIC *, float);

CRef RefCallSetClockSpeed(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {1};
    float oid;
    RefSetArgsFromSplice(1, args, aotyp, &oid);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordSetClockSpeed(object, oid);
    return refResult;
}
