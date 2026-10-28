struct VT {
    char pad0[0x50]; short d50; short i50; void (*f50)(char *);
    short d58; short i58; void (*f58)(char *);
    char pad1[0x70 - 0x60]; short d70; short i70; void (*f70)(char *, int);
    char pad2[0x80 - 0x78]; short d80; short i80; void (*f80)(char *);
};
struct BLOT {
    char pad[0xC]; VT *vt;
    char pad1[0x58 - 0x10]; int blots;
    char pad2[0x70 - 0x5C]; int a70; int a74; int a78;
};
struct ENT { int pobj; int a; int b; };
struct JOBMENU {
    char pad0[0xC]; VT *vt;
    char pad1[0x24 - 0x10];
    BLOT *pblot;
    char pad2[0x40 - 0x28];
    int page; float tPage; int cent; ENT aent[1];
    char pad3[0x10C - 0x58];
    int crowMax; int pjobSel; int fFromJobs; int isel;
    int labelHolder0; int labelHolder1; int labelHolder2;
};
extern "C" {
extern char B_003DD490[];
extern float g_2ddf0c;
extern int B_003E0F9C;
void SetHandsOff(void *, int);
void ClearHandsOff(void *, int);
void SetBlotBlots(BLOT *, int);
void SetTimerTimers__FP5TIMER6TIMERS(BLOT *, int);
void JobMenu_BuildList(JOBMENU *);
void JobMenu_SetPage(JOBMENU *menu, int page)
{
    int none = -1;
    int pageNew = none;
    if (menu->pblot)
        pageNew = page;
    if (pageNew == menu->page)
        return;
    if (menu->page == none) {
        SetHandsOff(B_003DD490, 0);
        menu->vt->f50((char *)menu + menu->vt->d50);
    }
    int pagePrev = menu->page;
    menu->page = pageNew;
    menu->tPage = g_2ddf0c;
    switch (pageNew) {
    case -1:
        ClearHandsOff(B_003DD490, 0);
        menu->vt->f58((char *)menu + menu->vt->d58);
        if (menu->pblot->blots > 0)
            SetTimerTimers__FP5TIMER6TIMERS(menu->pblot, 1);
        menu->labelHolder2 = menu->labelHolder0 = menu->labelHolder1 = -1;
        break;
    case 0:
        menu->crowMax = 10;
        menu->pblot->a70 = 0x4E3;
        menu->pblot->a78 = 0x4E2;
        if (pagePrev == 1)
            menu->pblot->a74 = 0x4E8;
        else
            menu->pblot->a74 = 0x4E1;
        if (menu->pblot->blots != 0) {
            SetBlotBlots(menu->pblot, 1);
            SetTimerTimers__FP5TIMER6TIMERS(menu->pblot, 2);
            menu->pblot->vt->f80((char *)menu->pblot + menu->pblot->vt->d80);
        }
        break;
    case 1: {
        int pjob = B_003E0F9C;
        if (menu->isel >= 0 && menu->isel < menu->cent)
            pjob = menu->aent[menu->isel].pobj;
        menu->pjobSel = pjob;
        menu->fFromJobs = pagePrev == 0;
        menu->crowMax = 4;
        menu->pblot->a70 = 0x4E6;
        menu->pblot->a78 = 0x4E5;
        if (pagePrev == 0)
            menu->pblot->a74 = 0x4E7;
        else
            menu->pblot->a74 = 0x4E4;
        if (menu->pblot->blots != 0) {
            SetBlotBlots(menu->pblot, 1);
            SetTimerTimers__FP5TIMER6TIMERS(menu->pblot, 2);
            menu->pblot->vt->f80((char *)menu->pblot + menu->pblot->vt->d80);
        }
        break;
    }
    }
    JobMenu_BuildList(menu);
    menu->vt->f70((char *)menu + menu->vt->d70, -1);
}
}
