#include "sly2.h"
struct SW { char pad[0x3B20]; void *ppath; };
struct CRef { int tagk; int n; int pad[2]; };
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefSetGameSaveValue(CRef *, void *, CRef *, void *);
extern "C" void ShowCoinBlot(SW *);
extern "C" SW B_003DD490;
extern "C" char B_003D4A60[];

void SetGameCoins(void *pvUnused, int ccoin)
{
    CRef refs[3];
    void *ppath = B_003DD490.ppath;
    refs[0].tagk = 0x15;
    refs[0].n = ccoin;
    CRef_CopyConstruct(&refs[1], &refs[0]);
    RefSetGameSaveValue(&refs[2], ppath, &refs[1], B_003D4A60);
    CRef_Destruct(&refs[2]);
    CRef_Destruct(&refs[1]);
    CRef_Destruct(&refs[0]);
    ShowCoinBlot(&B_003DD490);
}
