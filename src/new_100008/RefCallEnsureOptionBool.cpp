#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void EnsureOptionBool(BASIC *, int, int);
extern const B8 RO_002A3A30;

CRef RefCallEnsureOptionBool(BASIC *object, int count, CRef *args)
{
    B8 aotyp;
    int oid;
    int arg;
    aotyp = RO_002A3A30;
    RefSetArgsFromSplice(2, args, (const int *)&aotyp, &oid, &arg);
    CRef ref;
    ref.SetTag(TAGK_Void);
    EnsureOptionBool(object, oid, arg);
    return ref;
}
