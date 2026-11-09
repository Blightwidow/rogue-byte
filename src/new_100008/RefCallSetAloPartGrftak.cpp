#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void func_001F6BC8(BASIC *, int, int);
extern const B8 RO_002A3A70;

CRef RefCallSetAloPartGrftak(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int oid;
    int arg;
    aotyp = RO_002A3A70;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &oid, &arg);
    CRef ref;
    ref.SetTag(TAGK_Void);
    func_001F6BC8(object, oid, arg);
    return ref;
}
