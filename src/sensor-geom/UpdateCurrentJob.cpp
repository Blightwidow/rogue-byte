// SPDX-License-Identifier: GPL-3.0-or-later
struct JOB { char pad[0x64]; int startTask; int endTask; };
struct SW { char pad[0x3B0C]; JOB *current; };
extern "C" {
extern SW B_003DD490;
int CploFindSwObjectsByClass(SW *, int, int, int, int, JOB **);
int FTaskComplete(int);
void StopJobIfCurrent(JOB *);
void SetCurrentJob(JOB *);
void UpdateCurrentJob()
{
    JOB *apjob[256];
    JOB *newJob = 0;
    int count = CploFindSwObjectsByClass(&B_003DD490, 5, 0x84, 0, 0x100, apjob);
    for (int index = 0; index < count; index++) {
        JOB *job = apjob[index];
        if (FTaskComplete(job->startTask) && !FTaskComplete(job->endTask))
            newJob = job;
    }
    if (newJob != B_003DD490.current) {
        if (B_003DD490.current != 0)
            StopJobIfCurrent(B_003DD490.current);
        if (newJob != 0)
            SetCurrentJob(newJob);
    }
}
}
