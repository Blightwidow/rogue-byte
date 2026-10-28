#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { char b[8]; };
typedef int QW __attribute__((mode(TI)));
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3B98;
extern "C" void func_0020AF88(BASIC *, int, int);
CRef *func_001044B0(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { Raw8 types; char pad[8]; CRef ref; int first; int second; } f;
    f.types = RO_002A3B98;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 2, args, &f.types, &f.first, &f.second);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    func_0020AF88(object, f.first, f.second);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
