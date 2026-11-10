#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B16 { char b[16]; };
extern "C" const B16 RO_002A3C78;
extern "C" void AddSeqRecordCallAnimation(BASIC *, int, int, int, int);

CRef RefCallCallAnimation(BASIC *object, int count, CRef *args)
{
    B16 aotyp;
    int v0;
    int v1;
    int v2;
    int v3;
    aotyp = RO_002A3C78;
    RefSetArgsFromSplice(4, args, &aotyp, &v0, &v1, &v2, &v3);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordCallAnimation(object, v0, v1, v2, v3);
    return ref;
}
