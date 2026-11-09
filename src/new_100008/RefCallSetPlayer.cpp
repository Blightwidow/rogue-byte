#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddSeqRecordSetPlayer(BASIC *, int);

CRef RefCallSetPlayer(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {6};
    int oid;
    RefSetArgsFromSplice(1, args, aotyp, &oid);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordSetPlayer(object, oid);
    return refResult;
}
