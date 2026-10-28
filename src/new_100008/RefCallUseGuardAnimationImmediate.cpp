#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[3]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void UseGuardAnimationImmediate(BASIC *, CRef *, int, int);
extern const AOT RO_002A3B20;

CRef *RefCallUseGuardAnimationImmediate(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3B20;
    CRef crefArg;
    crefArg.tagk = -1;
    int a, b;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 3, args, &aotyp, &crefArg, &a, &b);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    UseGuardAnimationImmediate(object, &crefArg, a, b);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    CRef_Destruct(&crefArg);
    return result;
}
