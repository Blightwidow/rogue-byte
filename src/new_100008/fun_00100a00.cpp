#include "sly2.h"
#include "cref.h"
struct BASIC;
struct VT { char pad[304]; short delta; short index; void (*fn)(void *, int); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_SetBool(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *func_00100A00(CRef *result, OBJ *object, int count, CRef *args)
{
    CRef ref;
    int aotyp[1];
    int arg;
    aotyp[0] = 0x2002;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 1, args, aotyp, &arg);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    VT *vtable = object->vptr;
    vtable->fn((char *)object + vtable->delta, arg);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
