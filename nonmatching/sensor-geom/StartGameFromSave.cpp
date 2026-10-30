#include "sly2.h"
struct CRef { int tagk; union { int n; float g; }; };
struct Sw { char pad[0x3B1C]; void *ppathDt; char pad3B20[8]; void *ppathEpisode; char pad3B2C[0x3B7C - 0x3B2C]; void *appathPercent[1]; };
struct Job { char pad[0x10]; int v10; int v14; int v18; };
extern Sw B_003DD490;
extern Job B_002DEB30;
extern char B_003DA530[];
extern char RO_002A3828[];
extern int g_2deb4c;
extern "C" {
void RefGetGameSaveValue(CRef *, void *, void *);
void CRef_Destruct(CRef *);
int CGc_FFindScreen(void *);
void StoreAudioModeInSave(void);
void func_001DD888(void *);
void *PdescFromEpisode(int);
void RequestTransition(void *, void *, int, int, int, int);
}
extern "C" void StartGameFromSave(void *pvSave)
{
    CRef ref;
    Sw *psw = &B_003DD490;
    RefGetGameSaveValue(&ref, psw->ppathDt, pvSave);
    float dtSave = ref.g;
    CRef_Destruct(&ref);
    if (CGc_FFindScreen(B_003DA530) != 0) {
        if (dtSave == 0.0f) {
            StoreAudioModeInSave();
            func_001DD888(B_003DA530);
            return;
        }
    } else if (dtSave == 0.0f) {
        g_2deb4c = (int)pvSave;
        B_002DEB30.v10 = -1;
        B_002DEB30.v14 = -1;
        B_002DEB30.v18 = 0x62F;
        RequestTransition(psw, PdescFromEpisode(0), 0x189, -1, 0x48, -1);
        return;
    }
    B_002DEB30.v18 = -1;
    g_2deb4c = (int)pvSave;
    B_002DEB30.v10 = -1;
    B_002DEB30.v14 = -1;
    RefGetGameSaveValue(&ref, psw->ppathEpisode, pvSave);
    int iEpisode = ref.n;
    CRef_Destruct(&ref);
    void *pdesc = PdescFromEpisode(iEpisode);
    int nPercent = 0;
    void *ppathPercent = psw->appathPercent[iEpisode];
    if (ppathPercent != 0) {
        RefGetGameSaveValue(&ref, ppathPercent, pvSave);
        nPercent = ref.n;
        CRef_Destruct(&ref);
    }
    if (nPercent >= 100 || pdesc == 0)
        pdesc = RO_002A3828;
    RequestTransition(psw, pdesc, 0x189, -1, 0x40, -1);
}
