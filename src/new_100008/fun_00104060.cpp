#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct Raw8 { char b[8]; };
extern "C" const Raw8 RO_002A3B80;
extern "C" void func_00154038(int, int, int);
CRef func_00104060(BASIC *object, int count, CRef *args)
{
    Raw8 types;
    int first;
    int second;
    types = RO_002A3B80;
    RefSetArgsFromSplice(2, args, &types, &first, &second);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_00154038(*(int *)((char *)object + 0xF64), first, second);
    return ref;
}
