#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3E30;
extern "C" void AddSeqRecordBinocZoom(BASIC *, float, int);
CRef *RefCallBinocZoom(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { Raw8 types; char pad[8]; CRef ref; float a; int b; } f;
    f.types = RO_002A3E30;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 2, args, &f.types, &f.a, &f.b);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    AddSeqRecordBinocZoom(object, f.a, f.b);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
