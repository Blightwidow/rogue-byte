#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void AttachPt_FAddTaskStateRequest(BASIC *, int, int);
extern const B8 RO_002A3C08;

CRef RefCallAttachPtAddTaskStateRequest(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int first;
    int second;
    aotyp = RO_002A3C08;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AttachPt_FAddTaskStateRequest(object, first, second);
    return ref;
}
