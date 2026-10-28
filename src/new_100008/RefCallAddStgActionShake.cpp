#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddStgActionShake(BASIC *, int);

CRef *func_0010CA50(CRef *result, BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x1004};
    int value;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, aotyp, &value);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    AddStgActionShake(object, value);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
