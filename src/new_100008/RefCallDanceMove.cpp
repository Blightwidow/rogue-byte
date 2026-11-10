#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct OBJ;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3E68;
extern "C" void AddSeqRecordDanceMove(OBJ *, int, float, int, int);

CRef RefCallDanceMove(OBJ *object, int count, CRef *args)
{
    B16 types;
    float a;
    int b;
    int c;
    int d;
    types = RO_002A3E68;
    RefSetArgsFromSplice(4, args, (const int *)&types, &a, &b, &c, &d);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordDanceMove(object, b,a,c,d);
    return ref;
}
