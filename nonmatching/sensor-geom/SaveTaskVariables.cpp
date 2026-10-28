struct CRef { int tagk; union { float g; int n; }; };
struct Task {
    char pad0[0x54]; int state; char pad58[0x64 - 0x58]; int cEnter; int cComplete; char pad6C[0x7C - 0x6C]; void *pjob;
    char pad80[0xC8 - 0x80]; char pathEnter[8]; char pathCount[8]; char pathComplete[8]; char pathState[8]; char pathForced[8];
    char padF0[4]; int cause;
};
extern "C" int B_003D4A60;
extern "C" void CRef_CopyConstruct(CRef *, CRef *);
extern "C" void CRef_Destruct(CRef *);
extern "C" void RefSetGameSaveValue(CRef *, void *, CRef *, int *);
extern "C" int FTaskComplete(Task *);
extern "C" void SaveJobVariables(void *);
static inline void SetSaveRef(void *path, CRef *value)
{
    CRef copy;
    CRef result;
    CRef_CopyConstruct(&copy, value);
    RefSetGameSaveValue(&result, path, &copy, &B_003D4A60);
    CRef_Destruct(&result);
    CRef_Destruct(&copy);
}
extern "C" void SaveTaskVariables(Task *task)
{
    if (task->cause == 1)
        return;
    if (task->state == -1)
        return;
    char *pathEnter = task->pathEnter;
    if (*(int *)pathEnter != 0) {
        CRef ref;
        ref.tagk = 21;
        ref.n = task->cEnter;
        SetSaveRef(pathEnter, &ref);
        CRef_Destruct(&ref);
    }
    char *pathCount = task->pathCount;
    if (*(int *)pathCount != 0) {
        CRef ref;
        ref.tagk = 21;
        ref.n = task->cComplete;
        SetSaveRef(pathCount, &ref);
        CRef_Destruct(&ref);
    }
    char *pathComplete = task->pathComplete;
    if (*(int *)pathComplete != 0) {
        CRef ref;
        ref.tagk = 23;
        ref.n = FTaskComplete(task) ? 1 : 0;
        SetSaveRef(pathComplete, &ref);
        CRef_Destruct(&ref);
    }
    char *pathState = task->pathState;
    if (*(int *)pathState != 0) {
        CRef ref;
        ref.tagk = 21;
        ref.n = task->state;
        SetSaveRef(pathState, &ref);
        CRef_Destruct(&ref);
    }
    char *pathForced = task->pathForced;
    if (*(int *)pathForced != 0) {
        CRef ref;
        ref.tagk = 23;
        ref.n = 0;
        SetSaveRef(pathForced, &ref);
        CRef_Destruct(&ref);
    }
    if (task->pjob != 0)
        SaveJobVariables(task->pjob);
}
