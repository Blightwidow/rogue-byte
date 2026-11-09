#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; int w; };
extern "C" void AddSeqRecordShowBrief(BASIC *, int, float, int);
extern const B8 RO_002A3E90;

CRef RefCallShowBrief(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int a;
    float b;
    int c;
    aotyp = RO_002A3E90;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordShowBrief(object, a, b, c);
    return ref;
}
