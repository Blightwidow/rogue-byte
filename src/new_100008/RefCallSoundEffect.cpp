#include "sly2.h"
struct CRef { int tagk; int pad[3]; };
struct BASIC;
struct AOT { int v[7]; };
extern "C" int RefSetArgsFromSplice__FiP4CRefP4OTYPe(CRef *, int, CRef *, const AOT *, ...);
extern "C" void CRef_Destruct(CRef *);
extern "C" int SetTag__4CRef4TAGK(CRef *, int);
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void AddSeqRecordSoundEffect(BASIC *, int, int, int, int, float, float, float);
extern const AOT RO_002A3DC0;

extern "C" CRef *RefCallSoundEffect(CRef *result, BASIC *object, int count, CRef *args)
{
    AOT aotyp = RO_002A3DC0;
    int a;
    int b;
    int c;
    int d;
    float e;
    float f;
    float g;
    CRef refResult;
    RefSetArgsFromSplice__FiP4CRefP4OTYPe(&refResult, 7, args, &aotyp, &a, &b, &c, &d, &e, &f, &g);
    CRef_Destruct(&refResult);
    SetTag__4CRef4TAGK(&refResult, 0x24);
    AddSeqRecordSoundEffect(object, a, b, c, d, e, f, g);
    CRef_CopyConstruct(result, &refResult);
    CRef_Destruct(&refResult);
    return result;
}

