#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3DA0;
extern "C" void AddSeqRecordExplode(BASIC *, int, int, int, float);

CRef RefCallExplode(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int v0;
    int v1;
    int v2;
    float v3;
    aotyp = RO_002A3DA0;
    RefSetArgsFromSplice(4, args, &aotyp, &v0, &v1, &v2, &v3);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordExplode(object, v0, v1, v2, v3);
    return ref;
}
