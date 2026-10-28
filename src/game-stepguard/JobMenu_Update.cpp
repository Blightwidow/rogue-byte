struct VT { char pad[0x80]; short d80; short i80; void (*f80)(char *); };
struct BLOT { char pad[0xC]; VT *vt; char pad1[0x58 - 0x10]; int blots; };
struct JOBMENU {
    char pad0[0xC]; void *vt;
    void *pjoy;
    char pad1[0x24 - 0x14];
    BLOT *pblot;
    char pad2[0x40 - 0x28];
    int page; int pad3; int cent;
    char pad4[0x114 - 0x4C];
    int fFromJobs;
};
extern "C" {
void Menu_Update(JOBMENU *);
int func_002127C8();
void SetBlotBlots(BLOT *, int);
void SetTimerTimers__FP5TIMER6TIMERS(BLOT *, int);
int FJoyButtonPressed(void *, int);
void JobMenu_SetPage(JOBMENU *, int);
void Menu_UpdateStick(JOBMENU *);
void JobMenu_UpdateBlot(JOBMENU *);
}

void JobMenu_Update(JOBMENU *job)
{
    Menu_Update(job);
    if (job->page == -1 || job->pjoy == 0)
        return;
    if (job->pblot->blots == 0) {
        if (func_002127C8() == 0)
            return;
        SetBlotBlots(job->pblot, 1);
        SetTimerTimers__FP5TIMER6TIMERS(job->pblot, 2);
        BLOT *blot = job->pblot;
        blot->vt->f80((char *)blot + blot->vt->d80);
    }
    if (FJoyButtonPressed(job->pjoy, 0x800)) {
        JobMenu_SetPage(job, -1);
        return;
    }
    switch (job->page) {
    case 0:
        if (FJoyButtonPressed(job->pjoy, 0x10)) {
            JobMenu_SetPage(job, -1);
            return;
        }
        if (job->cent != 0 && FJoyButtonPressed(job->pjoy, 0xF0)) {
            JobMenu_SetPage(job, 1);
            return;
        }
        break;
    case 1:
        if (job->fFromJobs == 0 && FJoyButtonPressed(job->pjoy, 0x10)) {
            JobMenu_SetPage(job, -1);
            return;
        }
        if (FJoyButtonPressed(job->pjoy, 0xF0)) {
            JobMenu_SetPage(job, 0);
            return;
        }
        break;
    }
    Menu_UpdateStick(job);
    JobMenu_UpdateBlot(job);
}
