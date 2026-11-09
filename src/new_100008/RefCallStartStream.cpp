#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };

extern "C" const Raw8 RO_002A3B08;
extern "C" BASIC *StartStream(BASIC *, int, int);
CRef RefCallStartStream(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3B08;
    CRef ref = RefSetArgsFromSplice(2, args, &types, &a, &b);
    ref.SetBasic(StartStream(object, a, b));
    return ref;
}
