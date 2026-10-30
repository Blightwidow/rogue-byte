extern "C" {
struct ThreadParam_235388 { int attr; void *entry; void *stack; int stackSize; void *gp; int initPriority; char pad18[8]; const char *name; };
struct SemaParam_235388 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct Pair_235388 { int first; int second; };
int CreateSema(SemaParam_235388 *);
int CreateThread(ThreadParam_235388 *);
void DeleteSema(int);
int GetThreadId(void);
void ChangeThreadPriority(int, int);
void func_002355E0(int, Pair_235388 *);
void func_002352B0(void);
extern char B_002E5270[];
extern char B_00448540[];
extern int B_00448940;
extern Pair_235388 B_00448948;
extern int D_002C49E8;
int func_00235388(void) {
    ThreadParam_235388 thread;
    SemaParam_235388 sema;
    if (D_002C49E8 > 0) {
        return -1;
    }
    sema.initCount = 0xFF;
    sema.maxCount = 0;
    sema.name = "SceKerneltopThread";
    B_00448940 = CreateSema(&sema);
    if (B_00448940 < 0) {
        return -1;
    }
    thread.entry = (void *)func_002352B0;
    thread.stack = B_00448540;
    thread.stackSize = 0x400;
    thread.gp = B_002E5270;
    thread.initPriority = 0;
    thread.name = "SceKerneltopThread";
    D_002C49E8 = CreateThread(&thread);
    if (D_002C49E8 < 0) {
        DeleteSema(B_00448940);
        return -1;
    }
    B_00448948.first = 0;
    B_00448948.second = 0;
    func_002355E0(D_002C49E8, &B_00448948);
    ChangeThreadPriority(GetThreadId(), 1);
    return D_002C49E8;
}
}
