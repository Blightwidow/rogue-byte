#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { int w[3]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordVoice(BASIC *, int, int, int);
extern "C" const B8 RO_002A3E48;

CRef *RefCallVoice(CRef *result, BASIC *obj, int count, CRef *args)
{
    struct L { B8 aotyp; int pad1; CRef ref; int a; int b; int c; } l;
    l.aotyp = RO_002A3E48;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, (const int *)&l.aotyp, &l.a, &l.b, &l.c);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordVoice(obj,l.a,l.b,l.c);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
