#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

struct BASIC {
    char pad[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
};
struct VT { short delta; short index; void (*fn)(void *, int); };

CRef *RefCallSlot2D0(CRef *result, BASIC *object, int count, CRef *args)
{
    int aotyp = 0;
    int arg;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, &aotyp, &arg);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    VT *vt = *(VT **)((char *)object + 0xC);
    VT *slot = (VT *)((char *)vt + 0x2D0);
    slot->fn((char *)object + slot->delta, arg);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
