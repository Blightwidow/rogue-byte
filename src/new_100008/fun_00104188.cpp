#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };

extern "C" const Raw8 RO_002A3B80;
extern "C" int NNextSensorState(BASIC *, int, int);
CRef func_00104188(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int a;
    int b;
    types = RO_002A3B80;
    CRef ref = RefSetArgsFromSplice(2, args, &types, &a, &b);
    ref.SetS32(NNextSensorState(object, a, b));
    return ref;
}
