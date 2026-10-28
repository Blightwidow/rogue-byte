#include "sly2.h"
struct TASK { char pad0[0x7C]; void *job; char pad1[0x88 - 0x80]; TASK *next; };
struct SW { char pad[0x3B0C]; void *curJob; };
extern SW B_003DD490;
extern char B_002DE578[];
extern TASK *B_003E0F90;
extern "C" void bevy_game_app_job_level_loaded(void *, int, void *);
extern "C" void OnDifficultyEvent(void *, int, void *);
extern "C" void SendTaskEvent(TASK *, int, void *);
extern "C" void OnJobEvent(void *, int, void *);
void bevy_camera_follow_activity(void *mgr, int event, void *arg)
{
    bevy_game_app_job_level_loaded(mgr, event, arg);
    OnDifficultyEvent(B_002DE578, event, arg);
    for (TASK *task = B_003E0F90; task != 0; task = task->next) {
        if (task->job == B_003DD490.curJob)
            SendTaskEvent(task, event, arg);
    }
    if (B_003DD490.curJob != 0)
        OnJobEvent(B_003DD490.curJob, event, arg);
}
