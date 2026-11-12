typedef unsigned int u32;
extern "C" {
struct Entry { int handle; u32 flags; int pad8; int padC; };
struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; int attr; int option; };
struct Request {
    int semaphoreId;
    int *result;
    int mode;
    int handle;
    int source;
    int size;
    int length;
    char data[0x10];
    int index;
};
struct SifClient { char pad0[0x24]; int serverReady; };
Entry *func_002376D0(int arg0);
void func_00237B50(int arg);
void func_00237B80();
int CreateSema(SemaParam *param);
int DeleteSema(int id);
int WaitSema(int id);
int SignalSema(int id);
void func_0023B170(int address, int size);
int func_002375E0(SifClient *client, int a1, int a2, Request *a3, int a4, int *a5, int a6, int a7, int a8, int a9);
extern Entry B_0044BB80[];
extern Request B_0044A680;
extern int B_0044B2C0;
extern SifClient B_0044BD80;
extern int D_002C4A7C;
extern int D_002C4A8C;
extern int D_002C49F8[32];
int func_00238528(int arg0, int source, int size) {
    Request *request = &B_0044A680;
    int result;
    SemaParam param;
    Entry *entry;
    u32 flags;
    int semaphore;
    int asyncFlag;
    int pending;
    int index;
    int length;
    int word;
    entry = func_002376D0(arg0);
    func_00237B50(3);
    if (D_002C4A7C == 0 || entry == 0 || (flags = entry->flags) == 0) {
        func_00237B80();
        return -9;
    }
    request->handle = entry->handle;
    request->index = entry - B_0044BB80;
    param.maxCount = 1;
    param.option = (int)"SceStdioWriteSema";
    request->size = size;
    asyncFlag = flags & 0x8000;
    request->source = source;
    param.initCount = 0;
    semaphore = CreateSema(&param);
    request->mode = 4;
    request->result = &result;
    B_0044A680.semaphoreId = semaphore;
    if (asyncFlag != 0) {
        WaitSema(D_002C4A8C);
        pending = asyncFlag;
        for (index = 0; index < 32; index++) {
            if (D_002C49F8[index] == -1) {
                D_002C49F8[index] = request->semaphoreId;
                request->semaphoreId = -request->semaphoreId;
                break;
            }
        }
        SignalSema(D_002C4A8C);
    } else {
        pending = 0;
    }
    if ((source & 0xF) == 0) {
        length = 0;
    } else {
        int previous = source - 0x10;
        length = (((u32)source >> 4) << 4) - previous;
    }
    if (size < length) {
        length = size;
    }
    if ((flags & 0x20000000) == 0) {
        func_0023B170(source, size);
    }
    source |= 0x20000000;
    request->length = length;
    for (index = 0; index < length; index++) {
        request->data[index] = *(unsigned char *)(source + index);
    }
    if (func_002375E0(&B_0044BD80, 3, 0, &B_0044A680, 0x30, &B_0044B2C0, 4, 0, 0, pending) < 0) {
        DeleteSema(semaphore);
        func_00237B80();
        return -0xB;
    }
    word = *(int *)((u32)&B_0044B2C0 | 0x20000000);
    func_00237B80();
    if (word == 0) {
        DeleteSema(semaphore);
        return -0xB;
    }
    if (pending != 0) {
        DeleteSema(semaphore);
        return 0;
    }
    WaitSema(semaphore);
    DeleteSema(semaphore);
    return result;
}
}
