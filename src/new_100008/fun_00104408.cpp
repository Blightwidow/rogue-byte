#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3B98;
extern "C" void func_0020AF38(BASIC *, int, int);
CRef func_00104408(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int first;
    int second;
    types = RO_002A3B98;
    RefSetArgsFromSplice(2, args, &types, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_0020AF38(object, first, second);
    return ref;
}
