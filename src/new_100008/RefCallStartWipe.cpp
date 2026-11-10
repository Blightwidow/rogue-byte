#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void StartWipe(BASIC *, int, int);
extern const B8 RO_002A3F88;

CRef RefCallStartWipe(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int first;
    int second;
    aotyp = RO_002A3F88;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    StartWipe(object, first, second);
    return ref;
}
