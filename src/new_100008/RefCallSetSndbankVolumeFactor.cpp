#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3B10;
extern "C" void SetSndbankVolumeFactor(BASIC *, int, int, float);
CRef RefCallSetSndbankVolumeFactor(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int first;
    float second;
    types = RO_002A3B10;
    RefSetArgsFromSplice(2, args, &types, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    SetSndbankVolumeFactor(object, first, 0, second);
    return ref;
}
