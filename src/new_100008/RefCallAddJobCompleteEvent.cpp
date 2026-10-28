#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddJobCompleteEvent(BASIC *, int);

extern "C" CRef *RefCallAddJobCompleteEvent(CRef *result, BASIC *object, int count, CRef *args)
{
    int aotyp[1] = {0x104E};
    int a;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, aotyp, &a);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    AddJobCompleteEvent(object, a);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
