#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3B18;
extern "C" void func_00203CB8(BASIC *, int, int);
CRef func_00102858(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int first;
    int second;
    types = RO_002A3B18;
    RefSetArgsFromSplice(2, args, &types, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_00203CB8(object, first, second);
    return ref;
}
