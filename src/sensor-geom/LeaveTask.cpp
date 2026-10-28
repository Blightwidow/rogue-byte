// SPDX-License-Identifier: GPL-3.0-or-later
struct VT { char pad[0x18]; short delta; short index; void (*fn)(void *, int, int, int, int, int); };
struct TASK {
    char pad0[0xC]; VT *vt; char pad1[0x5C - 0x10];
    int music; int musicOn; char pad2[0xA8 - 0x64];
    int ntoggle; void *atoggle; int nanim; void *aanim; char pad3[0xF4 - 0xB8];
    int cause;
};
struct SW; struct CAM; struct HUD;
extern "C" {
extern SW B_003DD490;
extern CAM B_002DEB30;
extern HUD B_003DA0C0;
void SetSwCurrentTask(SW *, TASK *);
int FTaskRunning(TASK *);
void bevy_camera_follow_activity(CAM *, int, TASK *);
void ApplyTaskToggles(TASK *, int, int, void *);
void ApplyTaskAnims(TASK *, int, int, void *, int);
void ClearHudLabel(HUD *, int);
void LeaveTask(TASK *task)
{
    SetSwCurrentTask(&B_003DD490, 0);
    if (FTaskRunning(task)) {
        bevy_camera_follow_activity(&B_002DEB30, 0x24, task);
        ApplyTaskToggles(task, 5, task->ntoggle, task->atoggle);
        ApplyTaskAnims(task, 5, task->nanim, task->aanim, task->cause);
        if (task->music != -1 && task->musicOn != 0)
            ClearHudLabel(&B_003DA0C0, task->music);
        task->vt->fn((char *)task + task->vt->delta, 0x14, 0, 0, 0, 0);
    }
}
}
