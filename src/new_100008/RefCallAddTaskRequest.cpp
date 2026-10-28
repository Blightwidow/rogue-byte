#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordAddTaskRequest(BASIC *, int, int);
extern "C" const Raw8 RO_002A3C08;

CRef *RefCallAddTaskRequest(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { Raw8 types; int pad[2]; CRef ref; int a; int b; } l;
    l.types = RO_002A3C08;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 2, args, &l.types, &l.a, &l.b);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordAddTaskRequest(object, l.a, l.b);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
