#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
struct VT { char pad[0x260]; short delta; short index; int (*fn)(void *, int); };
struct OBJ { char pad[0xC]; VT *vptr; };

CRef func_0010BC88(OBJ *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x1011;
    int arg;
    CRef refResult = RefSetArgsFromSplice(1, args, &aotyp, &arg);
    VT *vtable = object->vptr;
    int value = vtable->fn((char *)object + vtable->delta, arg);
    refResult.SetBool(value != 0);
    return refResult;
}
