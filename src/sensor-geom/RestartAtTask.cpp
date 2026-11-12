#include "sly2.h"
struct CRefX { int tagk; int n; int pad[2]; };
struct JOB;
struct TASK { char pad0[0x18]; int oid; char pad1c[0x7C - 0x1C]; JOB *pjob; char pad80[0xB8 - 0x80]; int fB8; int fBC; int fC0; char padC4[0xF0 - 0xC4]; int fF0; int fF4; int fF8; };
#include "sw.h"
struct CTaskHold {
    TASK *pother;
    TASK *ptask;
    int saveF4;
    int saveF8;
    CTaskHold(TASK *task, int value)
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
struct JOB : TASK { };
struct CJobHold {
    JOB *pjob;
    JOB *pother;
    int saveF0;
    int saveF4;
    CJobHold(JOB *job, int value)
    {
        pjob = job;
        pother = 0;
        if (pjob != 0) {
            saveF0 = pjob->fF0;
            pjob->fF0 = value;
            saveF4 = pjob->fF4;
            pjob->fF4 = 0;
        }
    }
    ~CJobHold()
    {
        if (pjob != 0) {
            pjob->fF0 = saveF0;
            pjob->fF4 = saveF4;
        }
        if (pother != 0) {
            pother->fF4 = saveF0;
            pother->fF8 = saveF4;
        }
    }
};
extern "C" {
extern SW B_003DD490;
extern const char RO_002A5238[];
void CRef_Destruct(CRefX *);
void EndJob(JOB *);
int IdCurrentLevel(void);
int PdescFromLevelRow(int);
void RequestTransition(SW *, int, int, int, int, int);
void SetCurrentJob(JOB *);
void SetTaskState(TASK *, int);
void SwitchCurrentTask(TASK *);
void func_001D8B20(CRefX *, CRefX *, const char *, int);
void RestartAtTask(TASK *task)
{
    CTaskHold holdTask(task, 2);
    CJobHold holdJob(task->pjob, 2);
    if (task->pjob != B_003DD490.pjobCurrent) {
        if (B_003DD490.pjobCurrent != 0) {
            CJobHold holdCur(B_003DD490.pjobCurrent, 2);
            EndJob(B_003DD490.pjobCurrent);
        }
        if (task->pjob != 0)
            SetCurrentJob(task->pjob);
    }
    SetTaskState(task, 1);
    SwitchCurrentTask(task);
    int value = task->fC0;
    if (value != -1) {
        CRefX result;
        CRefX arg;
        arg.tagk = 0x15;
        arg.n = value;
        func_001D8B20(&result, &arg, RO_002A5238, 0);
        CRef_Destruct(&result);
        CRef_Destruct(&arg);
    }
    int mode = 4;
    int row = task->fB8 == -1 ? 0x189 : task->fB8;
    if (B_003DD490.field_0x3E38 != 0 && (task->fBC == -1 || task->fBC == IdCurrentLevel()))
        mode = 0x24;
    RequestTransition(&B_003DD490, PdescFromLevelRow(task->fBC), row, -1, mode, 0x30A);
}
}
