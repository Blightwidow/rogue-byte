#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void AddSeqRecordAddTaskRequest(BASIC *, int, int);
extern "C" const Raw8 RO_002A3C08;

CRef RefCallAddTaskRequest(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3C08;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordAddTaskRequest(object, a, b);
    return ref;
}
