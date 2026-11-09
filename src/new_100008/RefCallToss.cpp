#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { int w[3]; };
extern "C" void AddSeqRecordToss(BASIC *, int, int, int);
extern "C" const B8 RO_002A3B88;

CRef RefCallToss(BASIC *obj, int count, CRef *args)
{
    B8 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A3B88;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordToss(obj,a,b,c);
    return ref;
}
