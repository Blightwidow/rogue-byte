#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[1]; };
struct VT { char pad[0x260]; short delta; short index; int (*fn)(void *, int); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" CRef *CRef_SetBool(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *func_0010BC88(CRef *result, OBJ *object, int count, CRef *args)
{
    AOT aotyp;
    aotyp.v[0] = 0x1011;
    int arg;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 1, args, &aotyp, &arg);
    VT *vtable = object->vptr;
    int value = vtable->fn((char *)object + vtable->delta, arg);
    CRef_SetBool(&refResult, value != 0);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}
