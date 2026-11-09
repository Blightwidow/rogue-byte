#include "sly2.h"
#include "cref.h"
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void func_001E0790(BASIC *, int, int);
extern "C" const Raw8 RO_002A3CB8;

CRef *func_00107728(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw8 types;
    CRef ref;
    int a;
    int b;
    types = RO_002A3CB8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, &types, &a, &b);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    func_001E0790(object, a, b);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
