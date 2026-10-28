#include "sly2.h"
struct CRef { int a; union { float g; int n; }; int c; int d; };
struct EPSEL { char pad0[0x118]; int last; };
extern int D_002BE26C;
extern int D_002BE2D0[];
extern int B_003DD490[];
extern int B_003D4A60;
extern "C" void RefGetGameSaveValue(CRef *, int, int *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int IrowLastEpselReplay(EPSEL *pepsel)
{
    if (D_002BE26C != 0) return 0x10;
    int episode = pepsel->last;
    int *base = B_003DD490 + episode;
    int ppath = base[0x3B7C / 4];
    int irow = D_002BE2D0[episode];
    CRef ref;
    RefGetGameSaveValue(&ref, base[0x3B58 / 4], &B_003D4A60);
    float dtPlayed = ref.g;
    CRef_Destruct(&ref);
    if (dtPlayed == 0.0f) {
        irow -= 2;
    } else {
        RefGetGameSaveValue(&ref, ppath, &B_003D4A60);
        int percent = ref.n;
        CRef_Destruct(&ref);
        if (percent < 100) irow -= 1;
    }
    return irow;
}
