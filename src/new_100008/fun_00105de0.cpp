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

extern "C" void func_00170B60(BASIC *, void *);
CRef *func_00105DE0(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { QW value; CRef ref; int types[1]; } f;
    f.types[0] = 0xA;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 1, args, f.types, &f.value);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    func_00170B60(object, &f.value);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
