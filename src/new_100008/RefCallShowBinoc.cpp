#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3E10;
extern "C" void AddSeqRecordShowBinoc(OBJ *, int, int, int, int);

CRef RefCallShowBinoc(OBJ *object, int count, CRef *args)
{
    B16 types;
    int a;
    int b;
    int c;
    int d;
    types = RO_002A3E10;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordShowBinoc(object, a,b,c,d);
    return ref;
}
