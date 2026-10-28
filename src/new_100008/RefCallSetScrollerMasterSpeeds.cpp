#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct SCROLLER;
struct Raw8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" const Raw8 RO_002A3A80;
void SetScrollerMasterSpeeds__FP8SCROLLERff(SCROLLER *, float, float);
CRef *RefCallSetScrollerMasterSpeeds(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { Raw8 types; char pad[8]; CRef ref; float first; float second; } f;
    f.types = RO_002A3A80;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 2, args, &f.types, &f.first, &f.second);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    SetScrollerMasterSpeeds__FP8SCROLLERff((SCROLLER *)object, f.first, f.second);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    return result;
}
