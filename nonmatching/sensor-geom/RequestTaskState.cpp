#include "sly2.h"
struct TASK;
struct JOB { char pad0[0xF0]; int cause; int causeArg; };
struct TASK { char pad0[0x54]; int state; char pad1[0x24]; JOB *job; char pad2[0x74]; int cause; int causeArg; };
struct CAUSESCOPE {
    JOB *job;
    TASK *task;
    int cause;
    int arg;
    CAUSESCOPE(TASK *target, int newCause, int newArg)
    {
        job = 0;
        task = target;
        if (target) {
            cause = task->cause;
            task->cause = newCause;
            arg = task->causeArg;
            task->causeArg = newArg;
        }
    }
    CAUSESCOPE(JOB *target, int newCause, int newArg)
    {
        job = target;
        task = 0;
        if (target) {
            cause = job->cause;
            job->cause = newCause;
            arg = job->causeArg;
            job->causeArg = newArg;
        }
    }
    ~CAUSESCOPE()
    {
        if (job) {
            job->cause = cause;
            job->causeArg = arg;
        }
        if (task) {
            task->cause = cause;
            task->causeArg = arg;
        }
    }
};
extern "C" int FTaskPrerequisitesDone(TASK *);
extern "C" void SetTaskState(TASK *, int);
extern "C" void RefuseTaskState(TASK *, int);
extern "C" void SwitchCurrentTask(TASK *);
extern "C" void LeaveTaskIfCurrent(TASK *);
void RequestTaskState(TASK *task, int request, int causeArg)
{
    CAUSESCOPE scopeTask(task, task->cause, causeArg);
    CAUSESCOPE scopeJob(task->job, task->cause, causeArg);
    if (request == -1)
        request = 4;
    int state = task->state;
    if (state != -1) {
        switch (request) {
        case 4:
            if (state == 0) {
                if (FTaskPrerequisitesDone(task)) {
                    SetTaskState(task, 1);
                    goto sw;
                }
                RefuseTaskState(task, 4);
                goto done;
            }
            if (state == 3)
                goto done;
        sw:
            SwitchCurrentTask(task);
            break;
        case 5:
            LeaveTaskIfCurrent(task);
            break;
        case 0: case 1: case 2: case 3: {
            int allowed = request - state == 1;
            switch (state) {
            case 0:
                if (request == 1)
                    allowed = FTaskPrerequisitesDone(task);
                break;
            case 1:
                if (request == 3)
                    allowed = state;
                break;
            case 3:
                goto done;
            }
            if (allowed)
                SetTaskState(task, request);
            else
                RefuseTaskState(task, request);
        }
        }
    }
done:;
}
