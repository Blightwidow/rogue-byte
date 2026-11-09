#include "sly2.h"
#include "cref.h"
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" CRef *CRef_SetBool(CRef *, int);
extern "C" CRef *CRef_SetS32(CRef *, int);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);

extern "C" const Raw8 RO_002A3B80;
extern "C" int NNextSensorState(BASIC *, int, int);
CRef *func_00104188(CRef *result, BASIC *object, int count, CRef *args)
{
    Raw8 types;
    CRef ref;
    int a;
    int b;
    types = RO_002A3B80;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 2, args, &types, &a, &b);
    CRef_SetS32(&ref, NNextSensorState(object, a, b));
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
