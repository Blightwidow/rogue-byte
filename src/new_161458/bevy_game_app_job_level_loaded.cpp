#include "sly2.h"
struct CRefX_161A58 { int tagk; union { float g; int n; }; int p2; int p3; };
struct TASK_161A58 { char pad[0xF0]; int fF0; int fF4; int fF8; };
struct JOB_161A58 { char pad[0x64]; int event; };
struct LOOTOBJ_161A58 { char pad[0x11A8]; int loot; };
struct CID_161A58 { char pad[8]; int f8; char pad2[0x2C]; int f38; };
struct SW_161A58 {
    char pad[0x3B0C];
    JOB_161A58 *pjob;
    int ptask;
    int event;
    char pad3B18[4];
    void *saveRoot;
    char pad3B20[0xD4];
    int flags;
    char pad3BF8[0x90];
    int transA;
    int transB;
    char pad3C90[0x1A8];
    int transFlag;
};
struct GAME_161A58 { char pad[8]; int mode; char pad2[0xFD50 - 0xC]; int pending; void *options; };
struct JOBMGR_161A58 { char pad[0x10]; int oidJob; int oidTask; int oidRestart; };
struct CTaskHold_161A58 {
    TASK_161A58 *pother;
    TASK_161A58 *ptask;
    int saveF4;
    int saveF8;
    CTaskHold_161A58(TASK_161A58 *task, int value)
    {
        pother = 0;
        ptask = task;
        if (ptask != 0) {
            saveF4 = ptask->fF4;
            ptask->fF4 = value;
            saveF8 = ptask->fF8;
            ptask->fF8 = 0;
        }
    }
    ~CTaskHold_161A58()
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
extern SW_161A58 B_003DD490;
extern GAME_161A58 B_002E65E0;
extern CID_161A58 B_003E1088;
extern const CID_161A58 RO_002A37E8;
extern int B_003D4A60;
void ApplyOptionsFromSave(void *);
void ApplyPendingSave();
void CRef_Destruct(CRefX_161A58 *);
void CStackFrame_Construct(void *);
void CStackFrame_Destructor(void *, int);
int CploFindSwObjectsByClass(SW_161A58 *, int, int, int, int, LOOTOBJ_161A58 **);
void EnterTask(int);
int IEpisodeCurrent();
void JobMgr_Construct(JOBMGR_161A58 *);
int LootId(int);
void OrderTasks(int *, TASK_161A58 ***);
void *PloFindSwObject_thunk(SW_161A58 *, int, int, void *);
void PostTaskJobEvent(int);
void RefGetGameSaveValue(CRefX_161A58 *, void *, void *);
void RequestTransition(SW_161A58 *, int, int, int, int, int);
void RestoreTaskStateFromSave(TASK_161A58 *);
void SaveTaskVariables(TASK_161A58 *);
void SetSwCurrentJob(SW_161A58 *, void *);
void SetSwCurrentTask(SW_161A58 *, void *);
void SetSwRestartTask(SW_161A58 *, void *);
void StartJob(JOB_161A58 *);
void func_00143AF0(LOOTOBJ_161A58 *, int);
void func_00165280(JOBMGR_161A58 *);
void func_001AB630(GAME_161A58 *);
}
static inline float GetSaveFloat_161A58(void *root, void *path)
{
    CRefX_161A58 ref;
    RefGetGameSaveValue(&ref, root, path);
    float g = ref.g;
    CRef_Destruct(&ref);
    return g;
}
static inline int FCidEqual_161A58(const CID_161A58 *a, const CID_161A58 *b)
{
    if (a == b)
        return 1;
    if (a == 0 || b == 0)
        return 0;
    return (a->f8 ^ a->f38) == (b->f8 ^ b->f38);
}
extern "C" void bevy_game_app_job_level_loaded(JOBMGR_161A58 *pjobmgr, int msg)
{
    switch (msg) {
    case 1:
        if (FCidEqual_161A58(&B_003E1088, &RO_002A37E8)) {
            LOOTOBJ_161A58 *apobj[3];
            int cobj = CploFindSwObjectsByClass(&B_003DD490, 5, 0x34, 0, 3, apobj);
            for (int index = 0; index < cobj; index++) {
                LOOTOBJ_161A58 *pobj = apobj[index];
                if (pobj->loot != 0)
                    func_00143AF0(pobj, LootId(pobj->loot));
            }
        }
        break;
    case 3:
        if (B_003DD490.flags & 1) {
            JobMgr_Construct(pjobmgr);
            B_002E65E0.pending = 0;
        } else if (B_003DD490.flags & 0x40) {
            ApplyPendingSave();
        }
        func_001AB630(&B_002E65E0);
        if (IEpisodeCurrent() == 0 && B_002E65E0.mode == 6 && B_002E65E0.pending == 0 && B_002E65E0.options != 0) {
            if (GetSaveFloat_161A58(B_003DD490.saveRoot, &B_003D4A60) == 0.0f) {
                if (GetSaveFloat_161A58(B_003DD490.saveRoot, B_002E65E0.options) != 0.0f)
                    ApplyOptionsFromSave(B_002E65E0.options);
            }
        }
        break;
    case 4:
        func_00165280(pjobmgr);
        break;
    case 5: {
        int frame;
        int ctask;
        TASK_161A58 **aptask;
        CStackFrame_Construct(&frame);
        OrderTasks(&ctask, &aptask);
        for (int index = 0; index < ctask; index++) {
            TASK_161A58 *ptask = aptask[index];
            CTaskHold_161A58 hold(ptask, 1);
            RestoreTaskStateFromSave(ptask);
        }
        SetSwCurrentJob(&B_003DD490, PloFindSwObject_thunk(&B_003DD490, 0x105, pjobmgr->oidJob, 0));
        SetSwCurrentTask(&B_003DD490, PloFindSwObject_thunk(&B_003DD490, 0x105, pjobmgr->oidTask, 0));
        SetSwRestartTask(&B_003DD490, PloFindSwObject_thunk(&B_003DD490, 0x105, pjobmgr->oidRestart, 0));
        if (B_003DD490.pjob != 0)
            StartJob(B_003DD490.pjob);
        if (B_003DD490.ptask != 0)
            EnterTask(B_003DD490.ptask);
        if (B_003DD490.flags & 4) {
            if (B_003DD490.event != 0)
                PostTaskJobEvent(B_003DD490.event);
            else if (B_003DD490.pjob != 0)
                PostTaskJobEvent(B_003DD490.pjob->event);
        }
        for (int index = 0; index < ctask; index++) {
            TASK_161A58 *ptask = aptask[index];
            CTaskHold_161A58 hold(ptask, 0);
            SaveTaskVariables(ptask);
        }
        CStackFrame_Destructor(&frame, 2);
        break;
    }
    case 16:
        if (B_003DD490.pjob == 0)
            RequestTransition(&B_003DD490, 0, B_003DD490.transA, B_003DD490.transB, B_003DD490.transFlag != 0 ? 0x20 : 0, 0x30A);
        break;
    }
}
