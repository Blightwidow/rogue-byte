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
extern "C" void ForceTaskState(TASK *, int, int);
extern "C" void UpdateCurrentJob();
void func_00164B38(TASK *task)
{
    CAUSESCOPE scope(task, 4, 0);
    ForceTaskState(task, 1, 0);
    UpdateCurrentJob();
}
