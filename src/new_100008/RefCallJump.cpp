#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B20 { B8 x; B8 y; int z; };
extern "C" const B20 RO_002A3D60;
extern "C" void AddSeqRecordJump(BASIC *, int, int, int, int, int);

CRef RefCallJump(BASIC *object, int count, CRef *args)
{
    B20 aotyp;
    int v0;
    int v1;
    int v2;
    int v3;
    int v4;
    aotyp = RO_002A3D60;
    RefSetArgsFromSplice(5, args, &aotyp, &v0, &v1, &v2, &v3, &v4);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordJump(object, v0, v1, v2, v3, v4);
    return ref;
}
