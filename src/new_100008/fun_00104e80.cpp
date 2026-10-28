#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct B8 { char b[8]; };
struct VT { char pad[0x270]; short delta; short index; void (*fn)(void *, int, void *); };
struct BASIC { char pad[0xC]; VT *vptr; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" int CRef_CopyConstruct(CRef *, CRef *);
extern const B8 RO_002A3BF0;
CRef *T(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad[2]; int vec[4]; CRef ref; int pobject; } l __attribute__((aligned(16)));
    l.aotyp = RO_002A3BF0;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, (const int *)&l.aotyp, &l.pobject, l.vec);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    VT *vt = object->vptr;
    vt->fn((char *)object + vt->delta, l.pobject, l.vec);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
