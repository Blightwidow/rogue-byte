// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct SW;
struct TASK;
struct JM { char pad[0x10]; int a; int b; int c; };
extern SW B_003DD490;
extern JM B_002DEB30;
extern "C" TASK *PloFindSwObject_thunk(SW *, int, int, int);
extern "C" void SetSwRestartTask(SW *, TASK *);
extern "C" void RestartAtTask(TASK *);
extern "C" void RequestTransition(SW *, void *, int, int, int, int);
void RestartAtTaskOid(void *unused, void *desc, int oid)
{
    TASK *task = PloFindSwObject_thunk(&B_003DD490, 0x105, oid, 0);
    if (task) {
        SetSwRestartTask(&B_003DD490, task);
        RestartAtTask(task);
    } else {
        B_002DEB30.a = -1;
        B_002DEB30.b = -1;
        B_002DEB30.c = oid;
        RequestTransition(&B_003DD490, desc, 0x189, -1, 8, -1);
    }
}
