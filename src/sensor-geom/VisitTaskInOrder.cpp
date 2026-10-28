#include "sly2.h"
struct TASK;
struct JOB { char pad0[0x68]; TASK *endTask; char pad1[0x84]; int cause; int causeArg; };
struct TASK {
    char pad0[0x7C]; JOB *job; char pad1[0x14]; int cPrereq; char pad2[0x8]; int cDependent; TASK **aDependent;
    char pad3[0x4C]; int cause; int causeArg; int cVisit; int depthMax; int jobDepthMax;
};
extern "C" void VisitTaskInOrder_self(TASK *, int *, TASK **, int, int);
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
void VisitTaskInOrder(TASK *task, int *count, TASK **tasks, int depth, int jobDepth)
{
    int visits = task->cVisit + 1;
    int depthMax = task->depthMax;
    if (depthMax <= depth)
        depthMax = depth;
    int jobDepthMax = task->jobDepthMax;
    if (jobDepthMax <= jobDepth)
        jobDepthMax = jobDepth;
    task->depthMax = depthMax;
    task->jobDepthMax = jobDepthMax;
    task->cVisit = visits;
    if (visits < task->cPrereq)
        return;
    int index = *count;
    tasks[index] = task;
    *count = index + 1;
    depth++;
    if (task->job != 0 && task->job->endTask == task)
        jobDepth++;
    for (int dependent = 0; dependent < task->cDependent; dependent++) {
        TASK *next = task->aDependent[dependent];
        CAUSESCOPE scope(next, task->cause, task->causeArg);
        VisitTaskInOrder_self(next, count, tasks, depth, jobDepth);
    }
}
