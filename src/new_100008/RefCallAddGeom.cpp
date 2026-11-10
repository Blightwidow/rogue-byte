#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" void AddSeqRecordAddGeom(BASIC *, int, int);
extern "C" const Raw8 RO_002A3C70;

CRef RefCallAddGeom(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3C70;
    RefSetArgsFromSplice(2, args, &types, &a, &b);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddSeqRecordAddGeom(object, a, b);
    return ref;
}
