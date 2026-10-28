#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { char b[8]; };
typedef int QW __attribute__((mode(TI)));
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" CRef *CRef_SetBool(CRef *, int);
extern "C" CRef *CRef_SetS32(CRef *, int);
extern "C" CRef *CRef_SetBasic(CRef *, BASIC *);

extern "C" const Raw8 RO_002A3BB8;
extern "C" int func_00227D20(BASIC *, QW, float);
CRef *RefCallCheckSphere(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { Raw8 types; char pad[8]; QW vec; CRef ref; float x; } f;
    f.types = RO_002A3BB8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 2, args, &f.types, &f.vec, &f.x);
    int r = func_00227D20(object, f.vec, f.x);
    CRef_SetBool(&f.ref, r != 0);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
