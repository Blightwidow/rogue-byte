#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;

struct BASIC {
    char pad[0xC];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
};
struct VT { short delta; short index; void (*fn)(void *, int); };

CRef RefCallSlot2D0(BASIC *object, int count, CRef *args)
{
    int aotyp = 0;
    int arg;
    RefSetArgsFromSplice(1, args, &aotyp, &arg);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    VT *vt = *(VT **)((char *)object + 0xC);
    VT *slot = (VT *)((char *)vt + 0x2D0);
    slot->fn((char *)object + slot->delta, arg);
    return refResult;
}
