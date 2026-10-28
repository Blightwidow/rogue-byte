// SPDX-License-Identifier: GPL-3.0-or-later
struct VT { char pad[0x40]; short showDelta; short showIndex; void (*show)(void *); short hideDelta; short hideIndex; void (*hide)(void *); };
struct LO { char pad[0xC]; VT *vt; };
struct TASK { char pad0[0x54]; int state; float startTime; char pad1[0x78 - 0x5C]; float limit; char pad2[4]; LO *marker; };
extern "C" {
void UpdateLo(TASK *);
void SendTaskTimeLimit(TASK *, int);
struct GT { float a; float b; };
extern GT g_2dded0;
extern int B_003E0F9C;
void UpdateTask(TASK *task)
{
    UpdateLo(task);
    if (task->state == 1) {
        float limit = task->limit;
        float zero;
        asm("mtc1 $0, %0\n\tnop" : "=f" (zero));
        if (zero < limit) {
            float elapsed = g_2dded0.a - task->startTime;
            if (elapsed < limit && limit + g_2dded0.b <= elapsed)
                SendTaskTimeLimit(task, 0);
        }
    }
    LO *marker = task->marker;
    if (marker != 0) {
        int ok = (task->state == 1);
        if (B_003E0F9C) ok = 0;
        if (ok)
            marker->vt->show((char *)marker + marker->vt->showDelta);
        else
            marker->vt->hide((char *)marker + marker->vt->hideDelta);
    }
}
}
