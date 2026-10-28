#include "sly2.h"
struct TASK { char pad[0x7C]; struct JOB *job; };
struct SW { char pad0[0x3B14]; TASK *restartTask; char pad1[0x170]; int spawn; int spawnArg; };
struct JOBVTBL { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct JOB { char pad0[0xC]; JOBVTBL *vtbl; char pad1[0x7C]; int ctoggle; void *atoggle; int canim; void *aanim; char pad2[0x54]; int cause; };
struct DESC { char pad0[8]; int idA; char pad1[0x2C]; int idB; };
extern "C" SW B_003DD490;
extern "C" char B_002DEB30;
extern "C" void SetSwCurrentJob(SW *, JOB *);
extern "C" void SetSwRestartTask(SW *, TASK *);
extern "C" DESC *PdescHubOfCurrentEpisode(void);
extern "C" int IdCurrentLevel(void);
extern "C" DESC *PdescFromLevelRow(int);
extern "C" int FJobRunning(JOB *);
extern "C" void bevy_camera_follow_activity(void *, int, JOB *);
extern "C" void ApplyTaskToggles(JOB *, int, int, void *);
extern "C" void ApplyTaskAnims(JOB *, int, int, void *, int);
static inline int FSameDesc(DESC *descA, DESC *descB)
{
    if (descA == descB)
        return 1;
    if (descA == 0 || descB == 0)
        return 0;
    unsigned idA = descA->idA ^ descA->idB;
    unsigned idB = descB->idA ^ descB->idB;
    return idA == idB;
}
void StopJob(JOB *job)
{
    SetSwCurrentJob(&B_003DD490, 0);
    TASK *restart = B_003DD490.restartTask;
    if (restart != 0 && restart->job != 0 && restart->job == job)
        SetSwRestartTask(&B_003DD490, 0);
    DESC *hub = PdescHubOfCurrentEpisode();
    DESC *level = PdescFromLevelRow(IdCurrentLevel());
    if (FSameDesc(hub, level)) {
        B_003DD490.spawn = 0x189;
        B_003DD490.spawnArg = -1;
    }
    if (FJobRunning(job)) {
        bevy_camera_follow_activity(&B_002DEB30, 0x22, job);
        ApplyTaskToggles(job, 5, job->ctoggle, job->atoggle);
        ApplyTaskAnims(job, 5, job->canim, job->aanim, job->cause);
        job->vtbl->fn((char *)job + job->vtbl->delta, 0x14, 0, 0, 0, 0);
    }
}
