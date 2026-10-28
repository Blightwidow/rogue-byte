#include "sly2.h"
struct JT { char pad0[0x1A8]; float heading; char pad1[0x10E4 - 0x1AC]; int focusKind; int pad10e8; int focusMode; };
struct BINOC { JT *jt; char pad[0x20 - 4]; int mode; char pad1[0x3C - 0x24]; float camera; };
struct BLOT { char pad[0x58]; int state; };
struct HUD { BINOC *binoc; int state; BLOT *blotA; int pad0c; BLOT *blotCur; void *recon; };
extern "C" int D_002BF920;
extern "C" void bevy_ui_binoc_recon_202d38(void *);
extern "C" void SetBinocHudState(HUD *, int);
extern "C" void func_00213B00(BLOT *, int);
extern "C" void func_00213928(BLOT *, int);
extern "C" void SeekBlotLabel(BLOT *, int, float);
extern "C" void UpdateBinocHud(HUD *hud)
{
    if (hud->recon)
        bevy_ui_binoc_recon_202d38(hud->recon);
    int state = hud->state;
    switch (state) {
    case 2: {
        int blotAGone = 0;
        if (hud->blotA == 0 || hud->blotA->state < 2)
            blotAGone = 1;
        int blotCurGone = 1;
        if (hud->binoc->mode == 1) {
            blotCurGone = 0;
            if (hud->blotCur == 0 || hud->blotCur->state < 2)
                blotCurGone = 1;
        }
        if (blotAGone && blotCurGone)
            SetBinocHudState(hud, -1);
        return;
    }
    case 0: {
        int blotAReady = 0;
        if (hud->blotA == 0 || hud->blotA->state == 2)
            blotAReady = 1;
        int blotCurReady = 1;
        D_002BF920 = -1;
        if (hud->binoc->mode == 1) {
            blotCurReady = 0;
            if (hud->blotCur == 0 || hud->blotCur->state == 2)
                blotCurReady = 1;
        }
        if (blotAReady && blotCurReady)
            SetBinocHudState(hud, 1);
        break;
    }
    case -1:
        return;
    }
    if (hud->blotA == 0)
        return;
    if (hud->state != 0) {
        int mode = hud->binoc->jt->focusMode;
        if (mode == 4) {
            if (D_002BF920 != mode)
                func_00213B00(hud->blotA, 0x353);
            if (hud->binoc->jt->focusMode == mode)
                goto store;
        }
        if (D_002BF920 == 4)
            func_00213928(hud->blotA, 0x353);
    store:
        D_002BF920 = hud->binoc->jt->focusKind;
    }
    SeekBlotLabel(hud->blotA, 0x352, (hud->binoc->jt->heading + 3.14159274f) * 0.159154937f);
    SeekBlotLabel(hud->blotA, 0x351, hud->binoc->camera);
}
