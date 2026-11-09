#include "sly2.h"
#include "cref.h"
struct OBJ;
struct B16 { char b[16]; };
extern "C" void RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const int *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" void SetTag__4CRef4TAGK(CRef *, int);
extern "C" void *CRef_CopyConstruct(CRef *, CRef *);
extern "C" const B16 RO_002A3E10;
extern "C" void AddSeqRecordShowBinoc(OBJ *, int, int, int, int);

CRef *RefCallShowBinoc(CRef *result, OBJ *object, int count, CRef *args)
{
    B16 types;
    CRef ref;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A3E10;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&ref, 4, args, (const int *)&types, &a, &b, &c, &d);
    CRef_Destruct(&ref);
    SetTag__4CRef4TAGK(&ref, 0x24);
    AddSeqRecordShowBinoc(object, a,b,c,d);
    CRef_CopyConstruct(result, &ref);
    CRef_Destruct(&ref);
    return result;
}
