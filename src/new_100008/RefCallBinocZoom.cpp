#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3E30;
extern "C" void AddSeqRecordBinocZoom(BASIC *, float, int);
CRef RefCallBinocZoom(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    float a;
    int b;
    types = RO_002A3E30;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordBinocZoom(object, a, b);
    return ref;
}
