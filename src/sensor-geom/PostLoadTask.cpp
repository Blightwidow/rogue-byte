struct CRef { int tagk; union { float g; int n; }; };
struct Task {
    char pad0[0x28]; long dw28; char pad30[0x40 - 0x30]; unsigned flags; char pad44[0x64 - 0x44];
    int cEnter; int cComplete; char pad6C[0x78 - 0x6C]; float tLimit; char *pjob; void *marker;
    char pad84[0x90 - 0x84]; int *aoidPre; int cPre; int *atpre; int *aoidPost; int cPost; int *atpost;
    int ctoggle; void *atoggle; int canim; void *aanim; char padB8[0xC8 - 0xB8]; char pathEnter[8]; char pathComplete[8];
};
extern "C" char B_003DD490[];
extern "C" int B_003D4A60;
extern "C" void PostLoLoad(Task *);
extern "C" void AppendSlEntry(void *, Task *);
extern "C" int FIsCurrentTask(Task *);
extern "C" int FTaskRunning(Task *);
extern "C" void ApplyTaskToggles(Task *, int, int, void *);
extern "C" void ApplyTaskAnims(Task *, int, int, void *, int);
extern "C" void RefGetGameSaveValue(CRef *, void *, int *);
extern "C" void CRef_Destruct(CRef *);
extern "C" int PloFindSwObject_thunk(void *, int, int, int);
extern "C" void func_001A6CA8(Task *, int);
extern "C" void PostLoadTask(Task *task)
{
    CRef ref;
    int i, found;
    PostLoLoad(task);
    if (task->pjob != 0)
        AppendSlEntry(task->pjob + 0x80, task);
    found = 0;
    for (i = 0; i < task->cPre; i++) {
        int plo = PloFindSwObject_thunk(B_003DD490, 0x105, task->aoidPre[i], 0);
        if (plo != 0)
            task->atpre[found++] = plo;
    }
    task->cPre = found;
    char *pathEnter = task->pathEnter;
    char *pathComplete = task->pathComplete;
    found = 0;
    for (i = 0; i < task->cPost; i++) {
        int plo = PloFindSwObject_thunk(B_003DD490, 0x105, task->aoidPost[i], 0);
        if (plo != 0)
            task->atpost[found++] = plo;
    }
    task->cPost = found;
    if (!FIsCurrentTask(task) && FTaskRunning(task)) {
        ApplyTaskToggles(task, 5, task->ctoggle, task->atoggle);
        ApplyTaskAnims(task, 5, task->canim, task->aanim, 1);
    }
    if (*(int *)task->pathEnter != 0) {
        RefGetGameSaveValue(&ref, pathEnter, &B_003D4A60);
        int cEnter = ref.n;
        CRef_Destruct(&ref);
        task->cEnter = cEnter;
    }
    if (*(int *)task->pathComplete != 0) {
        RefGetGameSaveValue(&ref, pathComplete, &B_003D4A60);
        int cComplete = ref.n;
        CRef_Destruct(&ref);
        task->cComplete = cComplete;
    }
    float limit = task->tLimit;
    float zero;
    asm volatile("mtc1 $0, %0\n\tnop" : "=f" (zero));
    if (limit == zero && task->marker == 0)
        return;
    if (((task->dw28 << 8) >> 60) == 2)
        func_001A6CA8(task, 0);
    unsigned flags = task->flags;
    if ((flags ^ 1) & 1)
        *(unsigned *)flags |= 2;
    else
        task->flags = flags | 2;
}
