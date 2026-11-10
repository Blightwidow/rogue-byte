#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3E38;
extern "C" void AddSeqRecordWaitForButton(BASIC *, int, int);
CRef RefCallWaitForButton(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3E38;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordWaitForButton(object, a, b);
    return ref;
}
