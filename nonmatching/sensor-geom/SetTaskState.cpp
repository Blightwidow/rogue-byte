struct CRefX { int tagk; int n; int pad[2]; };
struct ALLOCREQ { int size; int align; };
struct TASK {
    char pad0[0x54]; int state; char pad58[0x7C - 0x58]; int notified; char pad80[0x94 - 0x80]; int cprereq;
    char pad98[0xA0 - 0x98]; int cdep; TASK **adep; char padA8[0xF0 - 0xA8]; int fF0; int fF4; int fF8;
};
struct SW { char pad[0x3B7C]; int pathSlot; };
struct CTaskHold {
    TASK *pother;
    TASK *ptask;
    int saveF4;
    int saveF8;
    CTaskHold(TASK *task, int value4, int value8)
    {
        pother = 0;
        ptask = task;
        if (ptask != 0) {
            saveF4 = ptask->fF4;
            ptask->fF4 = value4;
            saveF8 = ptask->fF8;
            ptask->fF8 = value8;
        }
    }
    ~CTaskHold()
    {
        if (pother != 0) {
            pother->fF0 = saveF4;
            pother->fF4 = saveF8;
        }
        if (ptask != 0) {
            ptask->fF4 = saveF4;
            ptask->fF8 = saveF8;
        }
    }
};
extern "C" {
extern int B_002DEB28;
extern char B_002DEB30[];
extern char B_002E65E0[];
extern char B_003D4A60[];
extern char B_003DD490[];
extern int B_003E0F8C;
void CRef_CopyConstruct(CRefX *, CRefX *);
void CRef_Destruct(CRefX *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
void CollectTaskPrerequisites(TASK *, int, int *, TASK **);
int FTaskRunning(TASK *);
unsigned IEpisodeCurrent();
int NPercentComplete(void *);
void NotifyJobTaskState(int, TASK *);
void *PvAllocStackClearImpl__Fi(ALLOCREQ *);
void RefSetGameSaveValue(CRefX *, int, CRefX *, void *);
void SetTaskStateCascade(TASK *, int);
void TryAutosave(void *, int);
}
extern "C" void SetTaskState(TASK *self, int state)
{
    char frame[0x10];
    int old = self->state;
    if (state == old) return;
    if (B_002DEB28 != 0) return;
    int mode = -1;
    B_002DEB28 = 1;
    if (state < 3) {
        if (state > 0) mode = 2;
    } else if (state == 3) {
        mode = 3;
    }
    if (mode != -1) {
        int ctask;
        CStackFrame_Construct(frame);
        ctask = 0;
        TASK **aptask;
        {
            ALLOCREQ req;
            int align = 0x10;
            req.size = B_003E0F8C << 2;
            aptask = (TASK **)PvAllocStackClearImpl__Fi((req.align = align, &req));
        }
        self->fF0 = state;
        CollectTaskPrerequisites(self, mode, &ctask, aptask);
        for (int index = 0; index < ctask; index++) {
            TASK *task = aptask[index];
            CTaskHold hold(task, self->fF4, self->fF8);
            SetTaskStateCascade(task, task->fF0);
        }
        for (int index = 0; index < ctask; index++) {
            aptask[index]->fF0 = -1;
        }
        self->fF0 = -1;
        CStackFrame_Destructor(frame, 2);
    }
    SetTaskStateCascade(self, state);
    B_002DEB28 = 0;
    unsigned episode = IEpisodeCurrent();
    if (episode < 9) {
        int slot = *(int *)(B_003DD490 + episode * 4 + 0x3B7C);
        if (slot != 0) {
            CRefX tag;
            tag.tagk = 0x15;
            tag.n = NPercentComplete(B_002DEB30);
            CRefX copy;
            CRef_CopyConstruct(&copy, &tag);
            CRefX result;
            RefSetGameSaveValue(&result, slot, &copy, B_003D4A60);
            CRef_Destruct(&result);
            CRef_Destruct(&copy);
            CRef_Destruct(&tag);
        }
    }
    if (FTaskRunning(self) != 0 && old != -1 && old < 2 && self->state >= 2
        && (self->notified == 0 || (NotifyJobTaskState(self->notified, self), self->notified == 0))) {
        int ok = 1;
        if (self->cprereq != 0) {
            int cdep = self->cdep;
            int index = 0;
            if (cdep > 0) {
                TASK **adep = self->adep;
                TASK *dep = *adep;
                for (;;) {
                    if (dep->notified != 0) {
                        index++;
                        if (index < cdep) { dep = adep[index]; continue; }
                    } else {
                        ok = 0;
                    }
                    break;
                }
            }
        }
        if (ok != 0) TryAutosave(B_002E65E0, 0);
    }
}
