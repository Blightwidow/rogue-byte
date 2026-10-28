#include "sly2.h"
struct TASK { char pad[0xF4]; int cause; int arg; };
struct JOBX { char pad[0xF0]; int f0; int f4; };
struct SW { char pad[0x3B10]; TASK *curTask; };
struct SCOPE { JOBX *job; TASK *task; int savedCause; int savedArg; };
extern SW B_003DD490;
extern "C" int FIsCurrentTask(TASK *);
extern "C" void LeaveTaskIfCurrent(TASK *);
extern "C" void EnterTask(TASK *);
void SwitchCurrentTask(TASK *task)
{
    if (FIsCurrentTask(task))
        return;
    TASK *old = B_003DD490.curTask;
    if (old != 0) {
        SCOPE scope;
        scope.job = 0;
        scope.task = old;
        int c = task->cause;
        int a = task->arg;
        scope.savedCause = old->cause;
        old->cause = c;
        scope.savedArg = scope.task->arg;
        scope.task->arg = a;
        LeaveTaskIfCurrent(B_003DD490.curTask);
        if (scope.job != 0) {
            scope.job->f0 = scope.savedCause;
            scope.job->f4 = scope.savedArg;
        }
        if (scope.task != 0) {
            scope.task->cause = scope.savedCause;
            scope.task->arg = scope.savedArg;
        }
    }
    EnterTask(task);
}
