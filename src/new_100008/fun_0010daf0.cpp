#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct VSlot { short delta; short index; void (*fn)(void *, int); };
struct VTable { char pad[0x188]; VSlot slot; };
struct BASIC { char pad[0xC]; VTable *vtbl; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *func_0010DAF0(CRef *result, BASIC *object, int count, CRef *args)
{
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 0, args, 0);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    VSlot *slot = &object->vtbl->slot;
    slot->fn((char *)object + slot->delta, -1);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
