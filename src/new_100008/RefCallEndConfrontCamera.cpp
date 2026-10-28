#include "sly2.h"
typedef int QW __attribute__((mode(TI)));
struct CRef { int tagk; int pad[3]; };
struct JSG;
struct B8 { char b[8]; };
extern "C" void *RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" CRef *CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" CRef *CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordEndConfrontCamera(JSG *, QW, QW, float, int, int);
extern "C" const B8 RO_002A3DF8;
struct B20 { B8 a; B8 b; int c; };
extern "C" const B20 RO_002A3DF8_;

CRef *RefCallEndConfrontCamera(CRef *result, JSG *jsg, int count, CRef *args)
{
    struct L { B20 aotyp; int pad[3]; QW v0; QW v1; CRef ref; float g; int f0; int f1; } l;
    l.aotyp = *(const B20 *)&RO_002A3DF8;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 5, args, (const int *)&l.aotyp, &l.v0, &l.v1, &l.g, &l.f0, &l.f1);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    AddSeqRecordEndConfrontCamera(jsg, l.v0, l.v1, l.g, l.f0, l.f1);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
