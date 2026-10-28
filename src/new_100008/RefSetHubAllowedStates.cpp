#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void SetHubAllowedStates(BASIC *, CRef *);
CRef *RefSetHubAllowedStates(CRef *result, BASIC *object, int count, CRef *args)
{
    struct F { CRef states; CRef ref; int types; } f;
    f.types = 0x8006;
    f.states.tagk = -1;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&f.ref, 1, args, &f.types, &f.states);
    CRef_Destruct(&f.ref);
    SetTag__4CRef4TAGK(&f.ref, 0x24);
    SetHubAllowedStates(object, &f.states);
    CRef_CopyConstruct(result, &f.ref);
    CRef_Destruct(&f.ref);
    CRef_Destruct(&f.states);
    return result;
}
