#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void SetAloScrollingMasterSpeeds(BASIC *, float, float);
extern const B8 RO_002A3A80;

CRef RefCallSetAloScrollingMasterSpeeds(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    float a;
    float b;
    aotyp = RO_002A3A80;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    SetAloScrollingMasterSpeeds(object, a, b);
    return ref;
}
