#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" void SetJtAttach5(BASIC *, int);

CRef RefCallSetJtAttach5(BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x2002;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    SetJtAttach5(object, arg);
    return refResult;
}
