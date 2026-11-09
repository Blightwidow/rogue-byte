#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct VSlot { short delta; short index; void (*fn)(void *, int); };
struct VTable { char pad[0x188]; VSlot slot; };
struct BASIC { char pad[0xC]; VTable *vtbl; };

CRef func_0010DAF0(BASIC *object, int count, CRef *args)
{
    RefSetArgsFromSplice(0, args, 0);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    VSlot *slot = &object->vtbl->slot;
    slot->fn((char *)object + slot->delta, -1);
    return refResult;
}
