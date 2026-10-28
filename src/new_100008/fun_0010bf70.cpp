#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[1]; };
typedef int QW __attribute__((mode(TI)));
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" BASIC *func_001C4AF8(BASIC *, QW);

CRef *func_0010BF70(CRef *result, BASIC *object, int count, CRef *args)
{
    VECTOR arg;
    CRef refResult;
    AOT aotyp;
    aotyp.v[0] = 2;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, &aotyp, &arg);
    BASIC *found = func_001C4AF8(object, *(QW *)&arg);
    CRef_SetBasic(&refResult, found);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
