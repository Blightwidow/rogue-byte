struct JOB { char pad[0x78]; int unk78; };
struct TASK {
    char pad0[0x54]; int state;
    char pad1[0x7C - 0x58]; JOB *job;
    char pad2[0x94 - 0x80]; int cprereq; TASK **aprereq;
    char pad3[0xF0 - 0x9C]; int pending;
};
extern "C" void CollectTaskPrerequisites(TASK *ptask, int nState, int *pctask, TASK **aptask) __attribute__((weak));
extern "C" void CollectTaskPrerequisites(TASK *ptask, int nState, int *pctask, TASK **aptask)
{
    for (int i = 0; i < ptask->cprereq; i++) {
        TASK *prereq = ptask->aprereq[i];
        int nStatePrereq = nState;
        if (nState == 2) {
            JOB *job = prereq->job;
            if (job == 0) goto three;
            if (job != ptask->job) {
                if (job->unk78 == 0) {
                three:
                    nStatePrereq = 3;
                }
            }
        }
        CollectTaskPrerequisites(prereq, nStatePrereq, pctask, aptask);
    }
    if (ptask->pending == -1 && ptask->state < nState) {
        int n = *pctask;
        aptask[n] = ptask;
        *pctask = n + 1;
        ptask->pending = nState;
    }
}
