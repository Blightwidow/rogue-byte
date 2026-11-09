#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B24 { char b[24]; };
extern "C" const B24 RO_002A3E78;
extern "C" void AddSeqRecordLift(BASIC *, int, int, int, int, int, int);

CRef RefCallLift(BASIC *object, int count, CRef *args)
{
    B24 aotyp;
    int v0, v1, v2, v3, v4, v5;
    aotyp = RO_002A3E78;
    RefSetArgsFromSplice(6, args, &aotyp, &v0, &v1, &v2, &v3, &v4, &v5);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordLift(object, v0, v1, v2, v3, v4, v5);
    return ref;
}
