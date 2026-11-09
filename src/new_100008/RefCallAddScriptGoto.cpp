#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
struct B12 { B8 a; int b; };
struct B16 { B8 a; B8 b; };
extern "C" void CRef_SetBasic(CRef *, BASIC *);
extern "C" void AddScriptGoto(BASIC *, int, float, int);
extern const B12 RO_002A3C60;
CRef T(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    float b;
    int c;
    aotyp = RO_002A3C60;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    AddScriptGoto(object, a, b, c);
    return ref;
}
