struct CLOCK { char pad[0x3C]; float tReal; };
struct VT { char pad[0x50]; short d50; short i50; void (*f50)(char *); short d58; short i58; void (*f58)(char *);
 char pad2[0x70 - 0x60]; short d70; short i70; void (*f70)(char *, int); };
struct VT2 { char pad[0x190]; short d190; short i190; void (*f190)(char *); };
struct BLOT { char pad[0xC]; VT2 *vt; char pad1[0x58 - 0x10]; int blots; char pad2[0x70 - 0x5C]; int a70; int a74; int a78; };
struct SHOP {
    char pad0[0xC]; VT *vt;
    char pad1[0x24 - 0x10];
    BLOT *pblot;
    char pad2[0x40 - 0x28];
    int page; float tPage;
    char pad3[0x25C - 0x48];
    int labelUp; int labelDialog; int labelDown;
};
extern "C" {
void SetClockRate(CLOCK *, int, float);
void SetHandsOff(void *, int);
void ClearHandsOff(void *, int);
void SetBlotBlots(BLOT *, int);
void SetTimerTimers__FP5TIMER6TIMERS(BLOT *, int);
void ShopMenu_BuildList(SHOP *);
void ShopMenu_Select(SHOP *, int);
void *NewEmitter(int);
void SetEmitterUnpositioned(void *, void *);
extern char B_003DD490[];
extern CLOCK g_2dded0;
}

void ShopMenu_SetPage(SHOP *shop, int page)
{
    int pageNew = page;
    if (!shop->pblot)
        pageNew = -1;
    if (pageNew == shop->page)
        return;
    if (shop->page == -1) {
        SetClockRate(&g_2dded0, 0, 0.0f);
        SetHandsOff(B_003DD490, 0);
        shop->vt->f50((char *)shop + shop->vt->d50);
        SetBlotBlots(shop->pblot, 1);
    }
    int pagePrev = shop->page;
    shop->page = pageNew;
    shop->tPage = g_2dded0.tReal;
    switch (pageNew) {
    case -1: {
        BLOT *blot = shop->pblot;
        blot->vt->f190((char *)blot + blot->vt->d190);
        SetClockRate(&g_2dded0, 0, 1.0f);
        ClearHandsOff(B_003DD490, 0);
        shop->vt->f58((char *)shop + shop->vt->d58);
        if (shop->pblot->blots > 0)
            SetTimerTimers__FP5TIMER6TIMERS(shop->pblot, 1);
        shop->labelUp = -1;
        shop->labelDialog = -1;
        shop->labelDown = -1;
        break;
    }
    case 0: {
        BLOT *blot = shop->pblot;
        blot->a74 = 0x4D4;
        shop->pblot->a70 = 0x4D5;
        shop->pblot->a78 = 0x4D6;
        if (pagePrev == 1) {
            SetBlotBlots(shop->pblot, 1);
            SetBlotBlots(shop->pblot, 2);
        } else {
            SetTimerTimers__FP5TIMER6TIMERS(shop->pblot, 2);
        }
        SetEmitterUnpositioned(NewEmitter(0x35), 0);
        break;
    }
    case 1: {
        BLOT *blot = shop->pblot;
        blot->a74 = 0x49B;
        shop->pblot->a70 = 0x49C;
        shop->pblot->a78 = 0x49D;
        if (pagePrev == 0) {
            SetBlotBlots(shop->pblot, 1);
            SetBlotBlots(shop->pblot, 2);
        } else {
            SetTimerTimers__FP5TIMER6TIMERS(shop->pblot, 2);
        }
        SetEmitterUnpositioned(NewEmitter(0x35), 0);
        break;
    }
    }
    ShopMenu_BuildList(shop);
    ShopMenu_Select(shop, 0);
    shop->vt->f70((char *)shop + shop->vt->d70, -1);
}
