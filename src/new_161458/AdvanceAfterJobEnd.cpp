// SPDX-License-Identifier: GPL-3.0-or-later
#include "sly2.h"
struct JOB { char pad[0xC0]; void *task; int pad2[2]; struct LO *warp; };
struct LO { char pad[0x40]; unsigned flags; };
struct BQ;
extern BQ B_002E1E88;
extern "C" int FBootQueueHasEntries(BQ *);
extern "C" void RunNextBootQueueEntry(BQ *);
extern "C" void RequestTaskState(void *, int, JOB *);
extern "C" void Warp_Start(LO *);
void AdvanceAfterJobEnd(JOB *job)
{
    if (FBootQueueHasEntries(&B_002E1E88)) {
        RunNextBootQueueEntry(&B_002E1E88);
        return;
    }
    if (job->task) {
        RequestTaskState(job->task, 4, job);
        return;
    }
    LO *warp = job->warp;
    if (warp) {
        unsigned flags = warp->flags;
        if (!(flags & 1))
            *(unsigned *)flags |= 0x100;
        else
            warp->flags = flags | 0x100;
        Warp_Start(job->warp);
    }
}
