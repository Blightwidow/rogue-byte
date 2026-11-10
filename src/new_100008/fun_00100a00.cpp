#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct VT { char pad[304]; short delta; short index; void (*fn)(void *, int); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" CRef *CRef_SetBool(CRef *, int);

CRef func_00100A00(OBJ *object, int count, CRef *args)
{
    int aotyp[1];
    int arg;
    aotyp[0] = 0x2002;
    RefSetArgsFromSplice(1, args, aotyp, &arg);
    CRef ref;
    ref.SetTag(TAGK_Void);
    VT *vtable = object->vptr;
    vtable->fn((char *)object + vtable->delta, arg);
    return ref;
}
