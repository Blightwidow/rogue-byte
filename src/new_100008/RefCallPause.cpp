#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };
extern "C" void AddSeqRecordPause(BASIC *, float, int, int);
extern "C" const B8 RO_002A3CF0;

CRef RefCallPause(BASIC *obj, int count, CRef *args)
{
    B8 aotyp;
    float a;
    int b;
    int c;
    aotyp = RO_002A3CF0;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordPause(obj,a,b,c);
    return ref;
}
