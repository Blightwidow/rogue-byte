#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void AddStgActionDisablePart(BASIC *, int);

CRef RefCallAddStgActionDisablePart(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {6};
    int oid;
    RefSetArgsFromSplice(1, args, aotyp, &oid);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddStgActionDisablePart(object, oid);
    return refResult;
}
