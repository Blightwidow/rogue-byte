#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void func_00212F80(BASIC *, float, int);
extern const B8 RO_002A3F70;

CRef RefCallSeekBlotLabelTime(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    float first;
    int second;
    aotyp = RO_002A3F70;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_00212F80(object, first, second);
    return ref;
}
