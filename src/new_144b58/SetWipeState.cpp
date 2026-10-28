#include "sly2.h"
struct VT { char pad[0x40]; short d40; short i40; void (*fn40)(char *); char pad48[0x48 - 0x48]; };
struct VTB { char pad[0xB8]; short dB8; short iB8; void (*fnB8)(char *); };
struct VTC { char pad[0x48]; short d48; short i48; void (*fn48)(char *); };
struct Root { char pad[0xC]; VTB *vt; };
struct RootRecord { Root *plo; };
struct Wipe { char pad[0xC]; VT *vt; int pad10; RootRecord *proot; char pad18[0x150 - 0x18]; int wipes; float tWipes; char pad158[8]; void *pasega; };
struct Clock { char pad[0x3C]; float t; };
struct Sw { char pad[0x2C]; char dl[1]; };
extern Wipe *g_2dd644;
extern Clock g_2dded0;
extern char B_003DD040[];
extern Sw B_003DD490;
extern "C" {
void func_001FE5B8(void *, int, int);
void SetClockRate(void *, int, float);
void SetHandsOff(void *, int);
void ClearHandsOff(void *, int);
int FIsLoInWorld(void *);
void AppendDlEntry(void *, void *);
void SetAsegaMasterSpeed(void *, float);
}
extern "C" void SetWipeState(Wipe *wipe, int wipes)
{
    int wipesOld = wipe->wipes;
    if (wipes == wipesOld)
        return;
    switch (wipesOld) {
    case -1:
        g_2dd644 = wipe;
        func_001FE5B8(B_003DD040, 2, 0);
        SetClockRate(&g_2dded0, 8, 0.0f);
        {
        Sw *psw = &B_003DD490;
        SetHandsOff(psw, 0);
        wipe->vt->fn40((char *)wipe + wipe->vt->d40);
        if (FIsLoInWorld(wipe) == 0) {
            AppendDlEntry(psw->dl, wipe->proot);
            Root *plo = wipe->proot->plo;
            plo->vt->fnB8((char *)plo + plo->vt->dB8);
        }
        }
        break;
    case 3:
        if (wipe->pasega != 0)
            SetAsegaMasterSpeed(wipe->pasega, 1.0f);
        break;
    }
    wipe->wipes = wipes;
    wipe->tWipes = g_2dded0.t;
    switch (wipes) {
    case -1:
        g_2dd644 = 0;
        SetClockRate(&g_2dded0, 8, 1.0f);
        func_001FE5B8(B_003DD040, 2, 1);
        ClearHandsOff(&B_003DD490, 0);
        ((VTC *)wipe->vt)->fn48((char *)wipe + ((VTC *)wipe->vt)->d48);
        break;
    case 3:
        if (wipe->pasega != 0)
            SetAsegaMasterSpeed(wipe->pasega, 0.0f);
        break;
    }
}
