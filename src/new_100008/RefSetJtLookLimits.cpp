#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { int b[3]; };
typedef int QW __attribute__((mode(TI)));
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3EC0;
extern "C" const int RO_002A3EC8;
extern "C" void SetJtLookLimits(BASIC *, QW *, QW *, QW *);
CRef *RefSetJtLookLimits(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { Raw8 types; int pad; QW a; QW b; QW c; CRef ref; } f;
    f.types = RO_002A3EC0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 3, args, &f.types, &f.a, &f.b, &f.c);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    SetJtLookLimits(object, &f.a, &f.b, &f.c);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
