#include "sly2.h"
#include "cref.h"
CRef RefSetArgsFromSplice(int cref, CRef *aref, const void *aotyp, ...);
struct BASIC;
struct AOT { int v[7]; };
extern "C" void AddSeqRecordSoundEffect(BASIC *, int, int, int, int, float, float, float);
extern const AOT RO_002A3DC0;

extern "C" CRef RefCallSoundEffect(BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3DC0;
    int a;
    int b;
    int c;
    int d;
    float e;
    float f;
    float g;
    RefSetArgsFromSplice(7, args, &aotyp, &a, &b, &c, &d, &e, &f, &g);
    CRef refResult;
    refResult.SetTag(TAGK_Void);
    AddSeqRecordSoundEffect(object, a, b, c, d, e, f, g);
    return refResult;
}

