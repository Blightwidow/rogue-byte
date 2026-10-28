#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; int w; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordPlayGuardScript(BASIC *, int, int, int);
extern const B8 RO_002A3C88;

CRef *RefCallPlayGuardScript(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { B8 aotyp; int pad; CRef ref; int a; int b; int c; } l;
    l.aotyp = RO_002A3C88;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordPlayGuardScript(object, l.a, l.b, l.c);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
