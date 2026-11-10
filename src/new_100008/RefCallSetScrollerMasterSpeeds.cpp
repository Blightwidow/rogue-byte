#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct SCROLLER;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3A80;
void SetScrollerMasterSpeeds__FP8SCROLLERff(SCROLLER *, float, float);
CRef RefCallSetScrollerMasterSpeeds(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    float first;
    float second;
    types = RO_002A3A80;
    RefSetArgsFromSplice(2, args, &types, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    SetScrollerMasterSpeeds__FP8SCROLLERff((SCROLLER *)object, first, second);
    return ref;
}
