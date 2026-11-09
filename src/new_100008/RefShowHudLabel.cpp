#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void ShowHudLabel(BASIC *, int, float);
extern const B8 RO_002A4030;

CRef RefShowHudLabel(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int first;
    float second;
    aotyp = RO_002A4030;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    ShowHudLabel(object, first, second);
    return ref;
}
