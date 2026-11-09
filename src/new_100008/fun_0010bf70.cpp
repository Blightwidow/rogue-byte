#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[1]; };
extern "C" BASIC *func_001C4AF8(BASIC *, QW);

CRef func_0010BF70(BASIC *object, int count, CRef *args)
{
    VECTOR arg;
    AOT aotyp;
    aotyp.v[0] = 2;
    CRef refResult = RefSetArgsFromSplice(1, args, &aotyp, &arg);
    BASIC *found = func_001C4AF8(object, *(QW *)&arg);
    refResult.SetBasic(found);
    return refResult;
}
