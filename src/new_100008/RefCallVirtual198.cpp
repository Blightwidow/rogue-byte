#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct VT { char pad[0x198]; short delta; short index; void (*fn)(void *, int); };
struct OBJ { char pad[0xC]; VT *vptr; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);

CRef *RefCallVirtual198(CRef *result, OBJ *object, int count, CRef *args)
{
    struct L { CRef ref; int aotyp[1]; int arg; } l;
    l.aotyp[0] = 0x2002;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 1, args, l.aotyp, &l.arg);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    VT *vtable = object->vptr;
    vtable->fn((char *)object + vtable->delta, l.arg);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
