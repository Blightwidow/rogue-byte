#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
extern "C" void StickGadgetObj(BASIC *, int);

CRef RefCallStickGadgetObj(BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x2030};
    int value;
    RefSetArgsFromSplice(1, args, aotyp, &value);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    StickGadgetObj(object, value);
    return refResult;
}
