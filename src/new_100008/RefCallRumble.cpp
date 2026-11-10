#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };
extern "C" void AddSeqRecordRumble(BASIC *, float, int, int);
extern "C" const B8 RO_002A3D90;

CRef RefCallRumble(BASIC *obj, int count, CRef *args)
{
    B8 aotyp;
    float a;
    int b;
    int c;
    aotyp = RO_002A3D90;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordRumble(obj,a,b,c);
    return ref;
}
