#include "sly2.h"
struct JOB;
struct LOB { char pad[0x40]; unsigned flags; };
struct TASKVTBL { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct TASK {
    char pad0[0xC]; TASKVTBL *vtbl; char pad1[0x4C]; int labelId; int labelFlag; int cEnter; char pad2[0x14];
    JOB *job; char pad3[0x28]; int ctoggle; void *atoggle; int canim; void *aanim; int oidSpawn; char pad4[8]; LOB *plo; char pad5[0x2C];
    int cause;
};
extern "C" char B_003DD490;
extern "C" char B_002DEB30;
extern "C" char B_003DA0C0;
extern "C" void SetSwCurrentTask(void *, TASK *);
extern "C" void SetSwRestartTask(void *, TASK *);
extern "C" int FIsCurrentJob(JOB *);
extern "C" void ActivateJobOfTask(JOB *);
extern "C" int FTaskRunning(TASK *);
extern "C" void SaveTaskVariables(TASK *);
extern "C" void bevy_camera_follow_activity(void *, int, TASK *);
extern "C" void ApplyTaskToggles(TASK *, int, int, void *);
extern "C" void ApplyTaskAnims(TASK *, int, int, void *, int);
extern "C" void ShowHudLabel(float, void *, int);
extern "C" void Warp_Start(LOB *);
void EnterTask(TASK *task)
{
    SetSwCurrentTask(&B_003DD490, task);
    if (task->oidSpawn != -1)
        SetSwRestartTask(&B_003DD490, task);
    if (task->job != 0 && !FIsCurrentJob(task->job))
        ActivateJobOfTask(task->job);
    if (!FTaskRunning(task))
        return;
    task->cEnter = task->cEnter + 1;
    SaveTaskVariables(task);
    bevy_camera_follow_activity(&B_002DEB30, 0x23, task);
    ApplyTaskToggles(task, 4, task->ctoggle, task->atoggle);
    ApplyTaskAnims(task, 4, task->canim, task->aanim, task->cause);
    if (task->labelId != -1 && task->labelFlag != 0)
        ShowHudLabel(-1.0f, &B_003DA0C0, task->labelId);
    task->vtbl->fn((char *)task + task->vtbl->delta, 0x13, 0, 0, 0, 0);
    if (task->plo != 0) {
        unsigned flags = task->plo->flags;
        if (!(flags & 1))
            *(unsigned *)flags |= 0x100;
        else
            task->plo->flags = flags | 0x100;
        Warp_Start(task->plo);
    }
}
