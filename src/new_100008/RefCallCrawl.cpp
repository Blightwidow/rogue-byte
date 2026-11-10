#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B20 { B8 x; B8 y; int z; };
extern "C" const B20 RO_002A3D48;
extern "C" void AddSeqRecordCrawl(BASIC *, int, float, float, int, int);

CRef RefCallCrawl(BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    int v0;
    float v1;
    float v2;
    int v3;
    int v4;
    aotyp = RO_002A3D48;
    RefSetArgsFromSplice(5, args, &aotyp, &v0, &v1, &v2, &v3, &v4);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordCrawl(object, v0, v1, v2, v3, v4);
    return ref;
}
