#include "sly2.h"
struct CRef { int tagk; union { float g; int n; }; };
struct JOB { char pad0[0x7C]; int cStart; char pad1[0x24]; float tJob; char pad2[0x28]; char pathStart[8]; char pathComplete[8]; char pathTime[8]; };
extern "C" int B_003D4A60;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefSetGameSaveValue(CRef *, void *, CRef *, int *);
extern "C" int FEndTaskComplete(JOB *);
static inline void SetSaveRef(void *path, CRef *value)
{
    CRef copy;
    CRef result;
    CRef_CopyConstruct(&copy, value);
    RefSetGameSaveValue(&result, path, &copy, &B_003D4A60);
    CRef_Destruct(&result);
    CRef_Destruct(&copy);
}
void SaveJobVariables(JOB *job)
{
    char *pathpathStart = job->pathStart;
    if (*(int *)pathpathStart != 0) {
        char *path = pathpathStart;
        CRef ref;
        ref.tagk = 0x15;
        ref.n = job->cStart;
        SetSaveRef(path, &ref);
        CRef_Destruct(&ref);
    }
    char *pathpathComplete = job->pathComplete;
    if (*(int *)pathpathComplete != 0) {
        char *path = pathpathComplete;
        CRef ref;
        ref.tagk = 0x17;
        ref.n = FEndTaskComplete(job) ? 1 : 0;
        SetSaveRef(path, &ref);
        CRef_Destruct(&ref);
    }
    char *pathpathTime = job->pathTime;
    if (*(int *)pathpathTime != 0) {
        char *path = pathpathTime;
        CRef ref;
        ref.tagk = 0x16;
        ref.g = job->tJob;
        SetSaveRef(path, &ref);
        CRef_Destruct(&ref);
    }
}
