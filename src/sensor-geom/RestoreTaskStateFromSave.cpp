#include "sly2.h"
#include "cref.h"
struct TASK;
struct JOB { char pad0[0x64]; TASK *startTask; char pad1[0x14]; int cStart; };
struct TASK {
    char pad0[0x54]; int state; char pad1[0xC]; int cEnter; char pad2[0x14]; JOB *job; char pad3[0x14]; int cPrereq; TASK **aPrereq;
    char pad4[0x44]; char pathState[8]; char pathForced[8];
};
extern "C" int B_003D4A60;
extern "C" CRef RefGetGameSaveValue(void *, int *);
extern "C" void ApplyTaskState(TASK *, int);
void RestoreTaskStateFromSave(TASK *task)
{
    int state = 0;
    int forced = 0;
    char *pathState = task->pathState;
    if (*(int *)pathState != 0) {
        int value = RefGetGameSaveValue(pathState, &B_003D4A60).m_tag.m_n;
        state = value;
    }
    char *pathForced = task->pathForced;
    if (*(int *)pathForced != 0) {
        int value = RefGetGameSaveValue(pathForced, &B_003D4A60).m_tag.m_n;
        forced = value;
    }
    if (forced != 0 && task->job != 0 && state < 3 && 0 < state) {
        task->cEnter = 0;
        state = 1;
        if (task->job->startTask == task)
            task->job->cStart = 0;
        for (int index = 0; index < task->cPrereq; index++) {
            if (task->aPrereq[index]->state <= 1) {
                state = 0;
                break;
            }
        }
    }
    if (state == 0)
        state = task->cPrereq == 0;
    ApplyTaskState(task, state);
}
