#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
typedef int QW __attribute__((mode(TI)));
struct VT { char pad[584]; short delta; short index; int (*fn)(void *, QW); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_SetBool(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *func_00100C80(CRef *result, OBJ *object, int count, CRef *args)
{
    struct L { QW vec; CRef ref; int aotyp[1]; } l;
    l.aotyp[0] = 2;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 1, args, l.aotyp, &l.vec);
    VT *vtable = object->vptr;
    int value = vtable->fn((char *)object + vtable->delta, l.vec);
    CRef_SetBool(&l.ref, value != 0);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
