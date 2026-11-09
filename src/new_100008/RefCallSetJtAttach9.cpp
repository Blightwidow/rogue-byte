#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void SetJtAttach9(BASIC *, int);

CRef RefCallSetJtAttach9(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x2002;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    SetJtAttach9(object, arg);
    return refResult;
}
