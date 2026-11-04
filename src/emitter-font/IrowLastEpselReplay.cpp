#include "sly2.h"
struct CRef_15D798 { int a; union { float g; int n; }; int c; int d; };
struct EPSEL_15D798 { char pad0[0x118]; int last; };
struct GS_15D798 { char pad[0x3B58]; int dt[9]; int path[9]; };
extern int D_002BE26C;
extern int D_002BE2D0[];
extern GS_15D798 B_003DD490;
extern int B_003D4A60;
extern "C" void RefGetGameSaveValue(CRef_15D798 *pref, int ppath, int *pgsv);
extern "C" void CRef_Destruct(CRef_15D798 *);
extern "C" int IrowLastEpselReplay(EPSEL_15D798 *pepsel)
{
    if (D_002BE26C != 0) return 0x10;
    int episode = pepsel->last;
    int irow = D_002BE2D0[episode];
    int dt = B_003DD490.dt[episode];
    int ppath = B_003DD490.path[episode];
    CRef_15D798 ref;
    RefGetGameSaveValue(&ref, dt, &B_003D4A60);
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
