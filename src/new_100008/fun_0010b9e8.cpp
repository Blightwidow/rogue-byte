#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[1]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddBrkTouchClass(BASIC *, int);

CRef *func_0010B9E8(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 6;
    int arg;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, &aotyp, &arg);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    AddBrkTouchClass(object, arg);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
