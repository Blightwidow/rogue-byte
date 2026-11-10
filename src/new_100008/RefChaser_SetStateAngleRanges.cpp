#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };

struct Raw12 { B8 x; int z; };
extern "C" void Chaser_SetStateAngleRanges(BASIC *, int, void *, void *);
extern "C" const Raw12 RO_002A4098;

CRef RefChaser_SetStateAngleRanges(BASIC *object, int count, CRef *args)
{
    Raw12 types;
    char v1[16];
    char v2[16];
    int a;
    types = RO_002A4098;
    RefSetArgsFromSplice(3, args, &types, &a, v1, v2);
    CRef ref;
    ref.SetTag(TAGK_Void);
    Chaser_SetStateAngleRanges(object, a, v1, v2);
    return ref;
}
