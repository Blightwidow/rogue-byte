// SPDX-License-Identifier: GPL-3.0-or-later
struct TASK { char pad0[0x54]; int state; char pad1[0xA0 - 0x58]; int ndep; TASK **adep; char pad2[0xF4 - 0xA8]; int cause; int arg; };
struct JOBX { char pad[0xF0]; int f0; int f4; };
struct SCOPE { JOBX *job; TASK *task; int savedCause; int savedArg; };
extern "C" void ApplyTaskState(TASK *, int);
extern "C" void UpdateDependentTaskState(TASK *, int);
extern "C" void SetTaskStateCascade(TASK *task, int state)
{
    if (task->state == state)
        return;
    ApplyTaskState(task, state);
    for (int index = 0; index < task->ndep; index++) {
        TASK *dep = task->adep[index];
        SCOPE scope;
        scope.job = 0;
        scope.task = dep;
        int c = task->cause;
        int a = task->arg;
        if (dep != 0) {
            scope.savedCause = dep->cause;
            dep->cause = c;
            scope.savedArg = scope.task->arg;
            scope.task->arg = a;
        }
        UpdateDependentTaskState(dep, task->state);
        if (scope.job != 0) {
            scope.job->f0 = scope.savedCause;
            scope.job->f4 = scope.savedArg;
        }
        if (scope.task != 0) {
            scope.task->cause = scope.savedCause;
            scope.task->arg = scope.savedArg;
        }
    }
}
