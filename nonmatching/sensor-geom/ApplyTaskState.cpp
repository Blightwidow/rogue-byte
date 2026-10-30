struct TASK;
struct VT {
    char pad0[0x18];
    short delta18; short unused18; void (*fn1C)(void *, int, int, int, int, int);
    short delta20; short unused20; void (*fn24)(void *, int, void *);
};
struct TASK {
    char pad0[0xC]; VT *vt; int id;
    char pad1[0x54 - 0x14]; int state; float timer;
    char pad2[0x64 - 0x5C]; TASK *link64; int count68;
    int field6C; int field70; int field74; int field78; TASK *owner7C;
    char pad3[0xA8 - 0x80]; int a8; void *ac; int b0; void *b4;
    char pad4[0xF4 - 0xB8]; unsigned kind;
};
extern "C" {
void AppendDlEntry(void *, void *);
void ApplyTaskAnims(TASK *, int, int, void *, int);
void ApplyTaskToggles(TASK *, int, int, void *);
int FTaskRunning(TASK *);
void LeaveTaskIfCurrent(TASK *);
void RemoveDlEntry(void *, TASK *);
void SaveTaskVariables(TASK *);
void SwitchCurrentTask(TASK *);
void bevy_camera_follow_activity(void *, int, TASK *);
extern char B_002DEB30[];
extern int B_002DEB44;
extern char B_003E0F90[];
extern float g_2dded0;
void ApplyTaskState(TASK *task, int newState) {
    if (task->state != newState) {
        if (FTaskRunning(task) != 0) {
            bevy_camera_follow_activity(B_002DEB30, 0x26, task);
            VT *vt = task->vt;
            vt->fn1C((char *)task + vt->delta18, 0x16, 0, 0, 0, 0);
        }
        if (task->state == 1) RemoveDlEntry(B_003E0F90, task);
        if (FTaskRunning(task) != 0) {
            ApplyTaskToggles(task, newState, task->a8, task->ac);
            ApplyTaskAnims(task, newState, task->b0, task->b4, task->kind);
        }
        switch (newState) {
        case 0:
            if (task->kind == 4) {
                TASK *owner = task->owner7C;
                task->link64 = 0;
                task->count68 = 0;
                if (owner != 0) {
                    if (owner->link64 == task) owner->owner7C = 0;
                }
            }
            break;
        case 2:
            if (task->kind == 0) task->count68 = task->count68 + 1;
            break;
        case 1:
            AppendDlEntry(B_003E0F90, task);
            break;
        }
        task->state = newState;
        task->timer = g_2dded0;
        SaveTaskVariables(task);
        if (FTaskRunning(task) != 0) {
            bevy_camera_follow_activity(B_002DEB30, 0x25, task);
            VT *vt1 = task->vt;
            vt1->fn1C((char *)task + vt1->delta18, 0x15, 0, 0, 0, 0);
            VT *vt2 = task->vt;
            vt2->fn24((char *)task + vt2->delta20, 0x11, task);
        }
        unsigned kind = task->kind;
        switch (kind) {
        case 1:
            if (task->state == 1 && task->field74 != 0) {
                B_002DEB44 = task->id;
                return;
            }
            break;
        case 3:
            break;
        case 0:
        case 2:
        case 4:
            int stateNow = task->state;
            switch (stateNow) {
            case 1:
                if (task->field70 != 0) {
                    SwitchCurrentTask(task);
                    return;
                }
                break;
            case 0:
            case 3:
                LeaveTaskIfCurrent(task);
                break;
            }
            break;
        }
    }
}
}
