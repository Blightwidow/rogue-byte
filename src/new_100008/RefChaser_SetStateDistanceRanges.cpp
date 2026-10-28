#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct B8 { char b[8]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const void *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);

struct Raw12 { B8 x; int z; };
extern "C" void Chaser_SetStateDistanceRanges(BASIC *, int, void *, void *);
extern "C" const Raw12 RO_002A4098;

CRef *RefChaser_SetStateDistanceRanges(CRef *result, BASIC *object, int count, CRef *args)
{
    struct L { Raw12 types; int pad; char v1[16]; char v2[16]; CRef ref; int a; } l;
    l.types = RO_002A4098;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&l.ref, 3, args, &l.types, &l.a, l.v1, l.v2);
    CRef_Destruct(&l.ref);
    SetTag__4CRef4TAGK(&l.ref, 0x24);
    Chaser_SetStateDistanceRanges(object, l.a, l.v1, l.v2);
    CRef_CopyConstruct(result, &l.ref);
    CRef_Destruct(&l.ref);
    return result;
}
