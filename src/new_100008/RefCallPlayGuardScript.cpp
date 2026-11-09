#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; int w; };
extern "C" void AddSeqRecordPlayGuardScript(BASIC *, int, int, int);
extern const B8 RO_002A3C88;

CRef RefCallPlayGuardScript(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int a;
    int b;
    int c;
    aotyp = RO_002A3C88;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordPlayGuardScript(object, a, b, c);
    return ref;
}
