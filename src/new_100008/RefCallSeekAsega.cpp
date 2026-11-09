#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct B8 { char b[8]; };
extern "C" void SeekAsega(BASIC *, int, float, float);
extern const struct B12 { int w[3]; } RO_002A3AF8;

CRef RefCallSeekAsega(BASIC *object, int count, CRef *args)
{
    B12 aotyp;
    int a;
    float b;
    float c;
    aotyp = RO_002A3AF8;
    RefSetArgsFromSplice(3, args, (const int *)&aotyp, &a, &b, &c);
    CRef ref;
    ref.SetTag(TAGK_Void);
    SeekAsega(object, a, b, c);
    return ref;
}
