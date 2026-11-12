extern "C" {
struct SemaParam_2382B8 { int attr; int initCount; int maxCount; int field0C; int field10; const char *name; };
struct Request_2382B8 { int semaphore; int *result; int command; int field0C; void *buffer; int size; int field18; int index; };
struct Entry_2382B8 { int field0; int flags; int field8; int fieldC; };
int CreateSema(SemaParam_2382B8 *);
void DeleteSema(int);
void WaitSema(int);
void SignalSema(int);
Entry_2382B8 *func_002376D0(void);
void func_00237B50(int);
void func_00237B80(void);
void func_0023B170(void *, int);
int func_002375E0(void *, int, int, void *, int, void *, int, int, int, int);
extern Request_2382B8 B_0044A680;
extern Entry_2382B8 B_0044BB80[];
extern int B_0044B2C0[];
extern char B_0044BD80[];
extern int D_002C4A7C;
extern int D_002C4A8C;
extern int D_002C49F8[32];
int sceRead(int fd, void *buffer, int size) {
    SemaParam_2382B8 param;
    int result;
    Request_2382B8 *request = &B_0044A680;
    Entry_2382B8 *entry = func_002376D0();
    func_00237B50(2);
    if (D_002C4A7C == 0 || entry == 0 || entry->flags == 0) {
        func_00237B80();
        return -9;
    }
    int flags = entry->flags;
    request->field0C = entry->field0;
    request->index = entry - B_0044BB80;
    param.initCount = 1;
    param.name = "SceStdioReadSema";
    int waited;
    int wait = flags & 0x8000;
    request->buffer = buffer;
    request->size = size;
    param.maxCount = 0;
    int semaphore = CreateSema(&param);
    request->result = &result;
    request->command = 4;
    B_0044A680.semaphore = semaphore;
    if (wait) {
        waited = wait;
        WaitSema(D_002C4A8C);
        for (int index = 0; index < 32; index++) {
            if (D_002C49F8[index] == -1) {
                D_002C49F8[index] = request->semaphore;
                request->semaphore = -request->semaphore;
                break;
            }
        }
        SignalSema(D_002C4A8C);
    } else {
        waited = 0;
    }
    if (!(flags & 0x20000000)) {
        func_0023B170(buffer, size);
    }
    func_0023B170(request, 0x20);
    if (func_002375E0(B_0044BD80, 2, 0, &B_0044A680, 0x20, B_0044B2C0, 4, 0, 0, waited) < 0) {
        DeleteSema(semaphore);
        func_00237B80();
        return -0xB;
    }
    int done = *(int *)((unsigned)B_0044B2C0 | 0x20000000);
    func_00237B80();
    if (done == 0) {
        DeleteSema(semaphore);
        return -0xB;
    }
    if (waited) {
        DeleteSema(semaphore);
        return 0;
    }
    WaitSema(semaphore);
    DeleteSema(semaphore);
    return result;
}
}
