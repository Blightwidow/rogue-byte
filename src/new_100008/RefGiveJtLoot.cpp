#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void GiveJtLoot(BASIC *, int);

CRef RefGiveJtLoot(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 6;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    GiveJtLoot(object, arg);
    return refResult;
}
