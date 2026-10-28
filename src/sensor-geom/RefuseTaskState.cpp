#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, void *, int); };
struct JOB;
struct TASK { char pad0[0xC]; VT *vt; char pad1[0x7C - 0x10]; JOB *job; };
struct JOB { char pad0[0xC]; VT *vt; };
struct EVT { char pad[8]; int arg; };
extern EVT B_002DEB30;
extern "C" int FTaskRunning(TASK *);
extern "C" int FJobRunning(JOB *);
extern "C" void bevy_camera_follow_activity(void *, int, void *);
void RefuseTaskState(TASK *task, int state)
{
    int local = state;
    void *args[1];
    args[0] = &local;
    if (FTaskRunning(task)) {
        B_002DEB30.arg = local;
        bevy_camera_follow_activity(&B_002DEB30, 0x27, task);
        VT *vt = task->vt;
        vt->fn((char *)task + vt->delta, 0x12, 0, 1, args, 0);
    }
    JOB *job = task->job;
    if (job != 0 && FJobRunning(job)) {
        VT *vt = task->job->vt;
        vt->fn((char *)task->job + vt->delta, 0x12, 0, 1, args, 0);
    }
}
