#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A4008;
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddTaskToggle(BASIC *, int, CRef *, int, int);

CRef *RefCallAddTaskToggle(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B16 aotyp; CRef states; CRef ref; int oid, parent, level; } l;
    l.aotyp = RO_002A4008;
    l.states.tagk = -1;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 4, args, &l.aotyp, &l.oid, &l.states, &l.parent, &l.level);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddTaskToggle(object, l.oid, &l.states, l.parent, l.level);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    CRef_Destruct(&l.states);
    return result;
}
