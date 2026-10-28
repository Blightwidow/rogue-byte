#include "sly2.h"
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct JOB { char pad0[0xC]; VT *vt; char pad1[0x7C - 0x10]; int count; char pad2[0x8C - 0x80]; int a8c; int a90; int a94; int a98; char pad3[0xF0 - 0x9C]; int af0; };
extern char B_003DD490[];
extern char B_002DEB30[];
extern "C" void SetSwCurrentJob(void *, void *);
extern "C" int FJobRunning(void *);
extern "C" void SaveJobVariables(void *);
extern "C" void bevy_camera_follow_activity(void *, int, void *);
extern "C" void ApplyTaskToggles(void *, int, int, int);
extern "C" void ApplyTaskAnims(void *, int, int, int, int);
void StartJob(JOB *job)
{
    SetSwCurrentJob(B_003DD490, job);
    if (FJobRunning(job)) {
        job->count = job->count + 1;
        SaveJobVariables(job);
        bevy_camera_follow_activity(B_002DEB30, 0x21, job);
        ApplyTaskToggles(job, 4, job->a8c, job->a90);
        ApplyTaskAnims(job, 4, job->a94, job->a98, job->af0);
        VT *vt = job->vt;
        vt->fn((char *)job + vt->delta, 0x13, 0, 0, 0, 0);
    }
}
