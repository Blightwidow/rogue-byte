#include "sly2.h"
struct CRef { int tagk; union { float g; int n; }; };
struct JOB { char pad0[0x7C]; int cStart; char pad1[0xC]; int ctoggle; void *atoggle; int canim; void *aanim; char pad2[8]; float tJob; int saveVar; int oidAseg; char pad3[8]; int ploAseg; int ploAsegDone; char pad4[0x10]; char pathStart[0x10]; char pathTime[8]; char pathVar[8]; };
extern "C" char B_003E0EA8[];
extern "C" int B_003D4A60;
extern "C" void PostLoLoad(JOB *);
extern "C" int FIsCurrentJob(JOB *);
extern "C" int FJobRunning(JOB *);
extern "C" void ApplyTaskToggles(JOB *, int, int, void *);
extern "C" void ApplyTaskAnims(JOB *, int, int, void *, int);
extern "C" void RefGetGameSaveValue(CRef *, void *, int *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int PvFindSaveVar(void *, void *, int *);
extern "C" int PloFindSwObject_thunk(void *, int, int, int);
void PostJobLoad(JOB *job)
{
    CRef ref;
    char *base;
    PostLoLoad(job);
    if (!FIsCurrentJob(job) && FJobRunning(job)) {
        ApplyTaskToggles(job, 5, job->ctoggle, job->atoggle);
        ApplyTaskAnims(job, 5, job->canim, job->aanim, 1);
    }
    char *pathStart = job->pathStart;
    if (*(int *)pathStart != 0) {
        RefGetGameSaveValue(&ref, pathStart, &B_003D4A60);
        int start = ref.n;
        CRef_Destruct(&ref);
        job->cStart = start;
    }
    char *pathTime = job->pathTime;
    if (*(int *)pathTime != 0) {
        RefGetGameSaveValue(&ref, pathTime, &B_003D4A60);
        float time = ref.g;
        CRef_Destruct(&ref);
        job->tJob = time;
    }
    base = B_003E0EA8;
    job->saveVar = PvFindSaveVar(base, job->pathVar, &B_003D4A60);
    if (job->oidAseg != -1)
        job->ploAseg = PloFindSwObject_thunk(base - 0x3A18, 0x405, job->oidAseg, 0);
    job->ploAsegDone = PloFindSwObject_thunk(base - 0x3A18, 0x405, 0x379, 0);
}
